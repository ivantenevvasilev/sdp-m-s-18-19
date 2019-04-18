# Упражнение 9
Тази седмица ще разглеждаме шаблони на функции и шаблони на класове. Тяхната идея е да не пишем допълнителен код и да имаме повече възможности с които да викаме функцията (или да ползваме класът).

### Пример
Ако имаме простата функция 

```c++
int sum(int a, int b) {
  return a + b;
}
```

не бихме могли да я извикаме с числа от тип `double` (без да преобразуваме типовете и губим точност). Ще ни се наложи да напишем същата функция по следният начин 
```c++
double sum(double a, double b) {
  return a + b;
}
```
Това ще се наложи да го направим за всеки тип който искаме да сумираме, но ние сме програмисти и сме мързеливи, бихме искали да кажем на C++ че искаме (например `unsigned long long`, `float`, `char` и тн), това може да се постигне с шаблони на функции (templates).

### Задача 1
Да се напише темплейтна функция `sum` която сумира две числа от произволен тип. 
В частност ще може да работи и за класове които имат предефиниран двуместният `operator+` без да го пишем изрично.

### Задача 2
Виждали сме `std::swap` преди, и бихме искали да реализираме наша си swap фукнция. 
Нека припомним какво прави тя - по подадени две референции към елементи от един и същ тип, тя разменя техните стойности

#### Пример

|   a   |   b   |   a (след swap) | b (след swap) |
| ----- | ----- | --------------- | ------------- |
|   1   |   2   |        2        |      1        |
|  5.3  |  1.2  |       1.2       |     5.3       |
|  'c'  |  '2'  |       '2'       |     'c'       |
| true  | false |      false      |     true      |

### Задача 3
Да се напише темплейтна функция less която приема два елемента от еднакъв тип които имат предефиниран `operator<` и да връща истина ако вторият подаден елемент е по-голям от първият, иначе връща лъжа.

Защо е полезна тази функция? Ами бихме могли да я ползваме директно - чрез `operator<` или да използваме факта че темплейтните функции ни позволяват да специализираме фукнцията за конкретен тип. Ако я ползваме директно, винаги трябва `operator<` да е дефиниран, а за тези които не е функцията няма да работи. Това ни дава гъвкавостта да напишем отделни имплементации за тези които не го предефинират.

### Задача 4
Да се специализира функцията `less` от задача 3 за низове, така че да връща истина ако низът подаден на втора позиция е лексикографски 'по-голям' от този на първа позиция. 
Нужно е да го предефинираме защото низовете за нас са просто `char *`, тоест указатели, а указателите са просто адреси (големи числа) и C++ знае как да сравнява числа обаче това ще връща грешни резултати често.

### Задача 5
Да се напише темплейтна функция `sort` която сортира масив от произволен тип, използвайки функцията `less` от задача 3.

### Задача 6
Да се напише темплейтна функция `equals`, която подбно на задача 3 приема два елемента от еднакъв тип които имат предефиниран `operator==` и връща истина ако двата елемента са равни, и лъжа в противен случай.

### Задача 7
Да се напише темплейтна функция приемаща масив от елементи (естествено и дължина) и един елемент от същият тип и връща истина ако елементът се среща поне два пъти в масива.

Примерно една конкретна инстанция би изглеждала така
```c++
bool contains_more_than_once(int * array, int count, int n);
```

## Темплейтни класове
До сега сме писали конкретни имплементации, например `CharStack`, `CharVector`, `IntStack` и така нататък.
Обаче структурите данни не би трябвало да ги интересува какъв тип данни съдържат, те са отговорни за начинът по който се достъпват данните. Тоест ролята на една структура от данни е да държи данните в изрядно състояние и да предоставя строго определен начин за достъп към елементите.
Например стекът ни дава достъп само до последно добавеният елемент, опашката съответно към първият добавен елемент. Масивът (или векторът) ни дават достъп до елемент на произволна позиция от стуктурата. Конкретната имплементация не е от голямо значение.

За да направим нашите класове по-общи, можем да ползваме темплейтни класове.

### Задача 8
Да се вземе клас `Stack` който сте реализирали, и да се направи темплейтен. Иска се да може да държи произволен тип данни. Забележете разликите между оригиналният клас, и неговата темплейтна реализация. Какви са промените и съществени ли са те?

### Задача 9 * (Бонус)  
Да се реализира клас наредена n-торка от произволен тип и произволна размерност n.


```c++
template<class T, int S>
class Tuple {
private:
  T arr[S];
public:
  Tuple();
  Tuple(T * arr);
 
  void print() const;
  
  bool operator==(const Tuple<T, S>& other) const;
  bool operator!=(const Tuple<T, S>& other) const;
  bool operator>=(const Tuple<T, S>& other) const;
  bool operator<=(const Tuple<T, S>& other) const;
  bool operator<(const Tuple<T, S>& other) const;
  bool operator>(const Tuple<T, S>& other) const;
  
  Tuple<T, S> operator+(const Tuple<T, S>& other) const;
  Tuple<T, S> operator-(const Tuple<T, S>& other) const;
  
  Tuple<T, S> operator-() const;
  Tuple<T, S> operator+() const;

  T operator*(const Tuple<T, S>& other) const;

  // Може да се заменят с мутатор и селектор
  T& operator[](int index);
  const T& operator[](int index) const;
};
```

Където `S` е размерът на n-торката, например при S = 2, класът ни ще представлява наредена двойка (x, y) от произволен тип T.

Където функциите имат следното поведение

|   Функция     |                          Тип                                              | Върната стойност |
| :-----------: | :----------------------------------------------------------------------:  | ---------------- |
|   operator==  | :heavy_check_mark: Двуместен </br> :heavy_check_mark: Инфиксен            | Връща дали са покомпонентно равени елементите на двете n-торки |
|   operator!=  | :heavy_check_mark: Двуместен </br>  :heavy_check_mark: Инфиксен           | Връща дали съществува позиция i в n-торките такава че двете да се различават в позиция i |
|   operator+  | :heavy_multiplication_x: Двуместен </br> :heavy_multiplication_x: Инфиксен | Връща n-торка с елемент на позиция i равен на абсолютната стойност на оригиналният |
|   operator+  | :heavy_check_mark: Двуместен </br> :heavy_check_mark: Инфиксен             |  Връща n-торка с елемент на позиция i равен на сборът на елементите на позиции i на двете n-торки |
|   operator-  | :heavy_multiplication_x: Двуместен </br> :heavy_multiplication_x:          | Връща n-торка с елемент на позиция i равен на отрицателната стойност на абсолютната стойност на оригиналният |
|   operator-  | :heavy_check_mark: Двуместен </br>  :heavy_check_mark:                     |  Връща n-торка с елемент на позиция i равен на разликата на елементите на позиции i на двете n-торки (от лявата се вади дясната) |
|   operator\* | :heavy_check_mark: Двуместен </br> :heavy_multiplication_x:                | Връща скаларното произведение на двете n-торки |
|   operator[] const | :heavy_check_mark: Двуместен </br> :heavy_multiplication_x:          | Връща елементът на подадената позиция |
|   operator[] | :heavy_check_mark: Двуместен </br> :heavy_multiplication_x:                | Връща елементът на подадената позиция която може да се променя |

### Защо това представяне е добро?
Знаем че, шаблонните типове се разбират по време на компилация, тогава и размерът `S` ще се знае по време на компилация. 
В такъв случай ще има ли нужда от динамична памет и съответно канонично представяне?
Отговорът е, че няма нужда. Тук се възползваме от факта че темплейтите се разбират по време на компилация и може да ползваме статичен масив, за който C++ ще се погрижи да за правилното копиране и изтриване. Също така, това представяне ни дава възможност да правим операции единствено между n-торки от един и същ размер, което е желаното поведение, иначе при други представяния би трябвало да правим изрични проверки за размерността на двете и да боравим с динамична памет. Това идва безплатно използвайки шаблоните по този начин.

### Каква е разликата между двата `operator[]`?
Едната позволява да се вика от инстанция с тип `const Tuple<T, S>` и съответно да се достъпват елементите само за четене. Иначе ако имаше само вариантът без `const`, нямаше да можем да достъпваме елементите на n-торката. Другият вариант ни позволява да правим промени от типа.

```c++
Tuple<int, 5> tuple;
tuple[0] = 1;
tuple[1] = 6;
tuple[2] = -8;
tuple[3] = 7;
tuple[4] = 5;
```

Един вид играят роля съответно на селектор и мутатор за i-тият елемент от n-торката.