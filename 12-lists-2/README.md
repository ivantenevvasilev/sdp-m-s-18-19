# Упражнение 12

Тази седмица отново ще се занимаваме със свързани списъци с една връзка.
Както видяхме предната седмица те се градят на сравнително проста идея, всички типове свързани списъци са базирани на това че нещата които държим са в една кутийка, която държи информация за съседните си елементи и самите данни.
Тази идея също ще я видим когато се сблъскаме дървета по-нататък.

[Примерна имплементация на лист](../11-lists/list-implementation/List.h)

### Задача 1
Да се напише функция приемащта свързан списък с една връзка (може и `Node<T>*`) която проверява дали списъкът образува аритметична прогресия.

```c++
template <typename T>
bool is_arithmetic_progression(List<T>& list);
// или
// bool is_arithmetic_progression(Node<T> * start);
```


### Задача 2
Да се напише функция приемащта свързан списък с една връзка (може и `Node<T>*`) която проверява дали списъкът образува геометрична прогресия.

```c++
template <typename T>
bool is_geometric_progression(List<T>& list);
// или
// bool is_geometric_progression(Node<T> * start);
```

### Задача 3
Да се напише функция която приема:
- брой `n`
- разлика `d`
- начална стойност `a`
Функцията се иска да генерира свързан списък, който има първите `n` на брой числа от аритметичната прогресия започваща с стойност `a` и разлика `d`

```c++
template <typename T>
List<T> generate_arithmetic_progression(int n, T d, T a);
```

### Задача 4
Да се напише функция която приема:
- брой `n`
- частно `q`
- начална стойност `b`
Функцията се иска да генерира свързан списък, който има първите `n` на брой числа от геометрична прогресия започваща с стойност `b` и частно `q`

```c++
template <typename T>
List<T> generate_geometric_progression(int n, T q, T b);
```

### Задача 5
Да се напише функция която по два _сортирани_ списъка, връща нов _сортиран_ списък, който съдържа елементите на двата входни списъка.

```c++
template <typename T>
List<T> merge_lists(List<T>& left, List<T>& right);
```

### Задача 6
Да се напише функция която по списък и число `n`, принтира `n`-тия елемент на списъкът.

```c++
template <typename T>
void print_nth(List<T>& list, int n);
```

### Задача 7
Да се напише функция която по подадени два списъка - първият от произволен тип, вторият от целочислен тип, изписва на екрана елементита на първият списък в редът зададен от вторият списък.

```c++
template <typename T>
void print_in_order(List<T>& list, List<int>& indexes);
```


