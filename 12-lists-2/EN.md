# Week 12

This week we will be tackling the Singly-Linked Lists again.
As we saw last week, they are based on a relatively simple idea, every type of linked list is based on the fact that the things we are holding are in a box, which holds information about its "neighbours" and the data itself.
We will see this same idea pop up in trees later on.

### Exercise 1
Define a function that accepts a singly linked list (or `Node<T> *`) which checks if a list is an arithmetic progression.

```c++
template <typename T>
bool is_arithmetic_progression(const List<T>& list);
// or
// bool is_arithmetic_progression(Node<T> * start);
```


### Exercise 2
Define a function that accepts a singly linked list (or `Node<T> *`) which checks if a list is an geometric progression.

```c++
template <typename T>
bool is_geometric_progression(const List<T>& list);
// or 
// bool is_geometric_progression(Node<T> * start);
```

### Exercise 3
Define a function that accepts:
- a number `n`
- a number `d`
- an initial value `a`
The function should generate (return) a linked list that has the first `n` numbers from the arithmetic progression starting with a value `a` and a differance `d`

```c++
template <typename T>
List<T> generate_arithmetic_progression(int n, int d, int a);
```

### Задача 4
Define a function that accepts:
- a number `n`
- a number `q`
- an initial value `b`
The function should generate (return) a linked list that has the first `n` numbers from the geometric progression starting with a value `b` and a scale `q`

```c++
template <typename T>
List<T> generate_geometric_progression(int n, int q, int b);
```

### Exercise 5
Defien a function that given two _sorted_ lists, returns a new _sorted_ list, that contains the elements of the two input lists.

```c++
template <typename T>
List<T> merge_lists(List<T>& left, List<T>& right);
```

### Exercise 6
Define a function that given a list and a number `n`, prints the `n`-th elmeent from the list.

```c++
template <typename T>
void print_nth(List<T>& list, int n);
```

### Exercise 7
Define a function taht given two lists - the first one of an arbitrary type, and the second one of an integer type, prints out on the screen the elements of the first list in the order set by the second list.

```c++
template <typename T>
void print_in_order(List<T>& list, List<int>& indexes);
```

