### Домашно 2
# Data Center, част втора
Искаме да разширим моделът, който създадохме на миналото домашно, като добавим възможността да се симулират действията на компаниите и център за данни.

Ще разглеждаме опростената задача – имаме няколко компании, няколко хранилищни единици и един център за данни. Имаме опашка от поръчки на компании, всяка от които желае да закупи определено количество хранилищни единици.

Всеки ден центрът за данни обработва тези поръчки доколкото успее. Тоест обработва поръчки докато не свършат свободните хранилищни единици, или денят изтече (един [работен] ден продължава 8 часа).

На края на деня центърът за данни таксува своите клиенти, след което си увеличава хранилището с фиксиран брой хранилищни единици, ако са останали толкова в симулацията и има неизпълнени поръчки.

Симулацията приключва когато бюджетът на центъра за данни стане неположителен или поръчките се изчерпат.

Целта на симулацията е да се видят след колко дни ще се стигне граничното условие, тоест център ще фалира или ще изпълни всички поръчки. Също е ценно да се видят и неизпълнените поръчки.

## Какво трябва да се свърши
Като за начало ще внесем леки промени по [класовете от предишното домашно](../02-data-center-part-one/solution)

### DataCenter
Първо в член-функцията `upgradeStorage` ще направим бюджета да се намаля с цената на всеки добавен `StorageUnit`, тоест центърът за данни ще плаща за него.

За да правим по-лесни проверки ще си добавим член-данна, която следи бройката свободни хранилищни единици, примерно `numberOfFreeStorageUnits`.

Ще добавим и конструктор по подразбиране, който инициализира бюджета и `numberOfFreeStorageUnits` с 0.

Също ще направим конструктор, който приема като аргумент бюджет.

Ще ни трябват и селектори за бюджета и за `numberOfFreeStorageUnits`.

### Company
Ще ни трябва селектор за `name` и следният конструктор:
```c++
Company (const char* inputName = "", double budget = 0);
```

### StorageUnit
Ще ни трябва мутатор за `owner` и следният конструктор:
```c++
StorageUnit::StorageUnit (double pricePerGB, unsigned int gigabytes);
```

### Simulation
Ще си направим нов клас `Simulation`, който съдържа следните член-данни:
```c++
DataCenter dataCenter;
DynamicArray<Company> companies;
StorageUnit storageUnits[STORAGE_UNITS_COUNT];
```
където извън класа `const int STORAGE_UNITS_COUNT = 1024;`

и най-важната член-функция:
```c++
SimulationResult Simulation::simulate (std::queue<Order> orders, int storageUnitsPerUpgrade, int minutesPerStorageUnit);
```

където се използват следните структури:
```c++
struct Order {
	int numberOfStorageUnits;
	Company company;

	Order (int numberOfStorageUnits, const Company& company)
		: company(company), numberOfStorageUnits(numberOfStorageUnits) {}
};

struct SimulationResult {
	char status;
	unsigned int totalDays;
	double finalBudget;
	std::queue<Order> unfinishedOrders;
};
```

`simulate` връща структурата `SimulationResult` като:
 - `finalBudget` е бюджетът на центърът за данни в края на симулацията
 - `status` е `'s'` ако бюджетът е `>=0`, иначе `'f'`
 - `totalDays` е броят дни (закръглен нагоре), които симулацията е продължила
 - `unfinishedOrders` е опашката с неизпълнените поръчки, като тя е празна ако `status == 's'`


### Тестване
За да видите дали всичко ви работи коректно може да си добавите тези член-функции към `Simulation`

```c++
void Simulation::prepare () {
	companies = DynamicArray<Company>();
	companies.pushBack(Company("ABC", 163868));
	companies.pushBack(Company("Google", 235781));
	companies.pushBack(Company("Microsoft", 102140));
	companies.pushBack(Company("FMI", 62100));
	companies.pushBack(Company("Bell", 21747));
	companies.pushBack(Company("Dell", 131897));
	companies.pushBack(Company("Github", 131897));
	companies.pushBack(Company("SpaceX", 140318));
	companies.pushBack(Company("KickStarter", 139560));
	companies.pushBack(Company("Samsung", 153655));

	for (int i = 0; i < STORAGE_UNITS_COUNT; ++i) {
		storageUnits[i] = StorageUnit(1, (floor(i / 128.0) + 1) * 128);
	}

	dataCenter = DataCenter(30312);
}

std::queue<Order> Simulation::getSampleOrders1 () {
	std::queue<Order> result;

	for (int i = 0; i < 10; ++i) {
		int j = i + 90;
		result.push(Order((j * j * j) % 20 + 12, companies[i]));
	}

	return result;
}

std::queue<Order> Simulation::getSampleOrders2 () {
	std::queue<Order> result;

	for (int i = 0; i < 10; ++i) {
		int j = i + 90;
		result.push(Order((j * j * j) % 100 + 1, companies[i]));
	}

	return result;
}

std::queue<Order> Simulation::getSampleOrders3 () {
	std::queue<Order> result;

	result.push(Order(8, companies[1]));
	result.push(Order(68, companies[2]));

	return result;
}
```

Може да използвате и [тази main функция](main.cpp), като правилният изход от нея е
```
---- First simulation ----
status: s, totalDays: 8, finalBudget: 16833.6

---- Second simulation ----
status: f, totalDays: 6, finalBudget: -5732.8
unfinished orders: 
    Company: Github, requested units: 37
    Company: SpaceX, requested units: 74
    Company: KickStarter, requested units: 93
    Company: Samsung, requested units: 100

---- Third simulation ----
status: f, totalDays: 2, finalBudget: -35582.4
unfinished orders: 
    Company: Microsoft, requested units: 64

---- Fourth simulation ----
status: s, totalDays: 10, finalBudget: 13364.8
```
