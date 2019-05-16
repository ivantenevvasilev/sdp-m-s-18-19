# Week 9
This week we will be taking a look at template functions and template classes. Their idea is to save us as many keystrokes as possible whilst giving us more flexibility when it comes to with what types we can call the function (or use the class).

### Example
Here we have a very simple function

```c++
int sum(int a, int b) {
  return a + b;
}
```

We wouldn't be able to call it with numbers of type `double` (without casting and losing precision). We will have to write out the exact same function in the following way
```c++
double sum(double a, double b) {
  return a + b;
}
```
We will have to do this same thing for every single type we want to sum, but we are programmers and are on the lazy side, we would like to make C++ do it for us (allow us to call it with other types, for example `unsigned long long`, `float, `char` etc). We can acheive that using function templates.

### Exercise 1
Define the template version of the `sum` function that adds up two numbers from a random type.
Using templates this will give us the ability to sum two classes that have a predefined binary `operator+` without us explicitly having to write it ourselves.

### Exercise 2
We have seen `std::swap` before, we would like to implement our own version of that function.
A quick refresher of what it does - given two refrences to elements that have the same type, it swaps their values.

#### Example

|   a   |   b   |   a (before swap) | b (after swap) |
| ----- | ----- | --------------- | ---------------- |
|   1   |   2   |        2        |      1           |
|  5.3  |  1.2  |       1.2       |     5.3          |
|  'c'  |  '2'  |       '2'       |     'c'          |
| true  | false |      false      |     true         |

### Exercise 3
Define a template function `less`, which given two elements of the same type, that have a defined `operator<` and returns `true` in the case when the first element is less than the second one, otherwise it returns `false`.

Why is this function useful? Well, we could use it directly - using `operator<` or use the fact that template function allow us to make a template specialization for a specific type. If we use `operator<` directly in our functions, we bind ourselves to the fact that it must be defined. If the type does not have it predefined, it wouldn't compile. We don't always have a way to change the way a class implementation to add it. So specializing gives us the flexibility that we can define our own ways to compare two elements. We could also opt-out of using the already-defined `operator<` if it does not suit our needs.

### Exercise 4
Specialize the template function `less` from exercise 3 for strings (`char *`), so that it compares lexicographically the two C-Style strings
We have to predefine it because for strings for us are just a basic `char *` that ends when we see a zero. But to C++ that is just a pointer, so `operator<` is going to work the same way the pointers are compared which is not what we want.

### Exercise 5
Define a template function `sort` which sorts an array of an arbitrary type, using the function `less` from exercise 3.

### Exercise 6
Define a template function `euqals`, which in a similar way way to exercise 3, accepts two elements of the same type that have a predefined `operator==` and returns `true` if both elements are equal and `false` otherwise.

### Exercise 7
Define a template function which accepts an array of elemnts (and of course a size of the array) and an element of the same type of the array, and retuns true in the case when the element is found in the array more than two times.

For example an instance of that template would look like
```c++
bool contains_more_than_once(Company * array, int count, Company element);
```

## Template classes
Up until now we have been using specific implementations, for example `CharStack`, `CharVector`, `IntStack` and so on.
But this binds the data structures to the underlying type, a data structure should be able to accomodate an arbitrary data type (so long all elements are the same type, of course). The job of a data structure is to hold the data in a valid state and give us access to the elements in the structure, suited to the abstract idea the structure itself. The concrete data inside the data structure shouldn't matter, so long it's being kept in a valid state.
For example, the Stack allows us to access only the last added element, the queue - to the first added element. The array (or the vector) allows us to access elements at a random position inside it.

To make our classes more abstract, we can use template classes.

### Exercise 8
Take the class `Stack` that we have implemented and to turn it into a templated Stack.
What are the differances between the code of the original class and the template one? Are they significant?

### Exercise 9 * (Bonus)
Implement a class `Tuple` that can hold an arbitrary data type and a random size of n.


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

  // These can be changed for setters and getters
  T& operator[](int index);
  const T& operator[](int index) const;
};
```

Where `S` is the size of the tuple, for example when S = 2, the class would be a pair (x, y) from type T.

Where the function has the following behaviour

|   Function |                          Type                                              | Return Value |
| :-----------: | :----------------------------------------------------------------------:  | ---------------- |
|   operator==  | :heavy_check_mark: Binary </br> :heavy_check_mark: Infix | Returns if the tuples are equal element by element | 
|   operator!=  | :heavy_check_mark: Binary </br>  :heavy_check_mark: Инфиксен           | Returns true in the case if there is a position i in which the tuples differ | 
|   operator+  | :heavy_multiplication_x: Unary </br> :heavy_multiplication_x: Prefix | Returns a new tuple with an element on position i equal to the absolute value of the original on position i | 
|   operator+  | :heavy_check_mark: Binary </br> :heavy_check_mark: Infix | Returns a tuple with an element on position i equal to the sum of the elements on position i on both input tuples | 
|   operator-  | :heavy_multiplication_x: Unary </br> :heavy_multiplication_x: Prefix | Returns a new tuple with an element on position i equal to the negative of the absolute value of the original on position i | 
|   operator-  | :heavy_check_mark: Binary </br> :heavy_check_mark: Infix | Returns a tuple with an element on position i equal to the differance of the elements on position i on both input tuples | 
|   operator\* | :heavy_check_mark: Binary          | Returns the scalar product of the tuples |
|   operator[] const | :heavy_check_mark: Binary    | Returns the element on position i |
|   operator[] | :heavy_check_mark: Binary          | Returns the element on position i that can be modified | 

### Why this idea is good?
We know, that template types are deduced during compilation, and then that means that the size `S` will be known during compilation.
In this case, is there a need for any dynamic memory and the accompanying Rule of the Big Three?
The answer is that there is no need. Here we make use of the fact that template arguments are deduced during compilation and can use a static array for which C++ will handle the destruction and copy of. On top of this, this way of implementing it makes sure we can only operate between two tuples of the same size, because the size information is in the type itself. In other implementations one would have to check the dimensions in each of the functions and handle errors and other nasty things that we are just avoiding by using templates making it this way. This comes for free by the nature of which templates work.

### What's the differance between the two `operator[]`?
One allows for it to be called with an instance of `const Tuple<T, S>` and allows the elements to be read only. Otherwise if we had only the variant that lacks the `const`, then we woulnd't be able to do anything using the `const` instance of the tuple. The other variant (the one with the `const`) gives us a way to modify the value, as it is a refrence.

```c++
Tuple<int, 5> tuple;
tuple[0] = 1;
tuple[1] = 6;
tuple[2] = -8;
tuple[3] = 7;
tuple[4] = 5;
```

In a way, they play the role of a getter and setter for the i-th element of the tuple.
