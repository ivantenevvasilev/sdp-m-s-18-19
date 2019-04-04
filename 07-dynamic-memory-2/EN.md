# Week 7

This week we will be dealing with dynamic memory once again.
A very important thing when dealing with dynamic memory is always to delete it after we finish using it.

## Exercise 1
Define a function which when given a non-negative integer number N returns a string representing the number in binary format without allocating any unnecessary memory.
For example if we pass the number 5, then its binary representation is 101 and the string that the function returns should be with length 4.

```c++
char * decimal_to_binary(int number);
```

### Input
The input is a single non-negative integer number N.

### Output
The string representing the binary format of the number N without the leading zeros.

### Examples

| Input | Output |
| ----- | ------ |
| 5     | 101    |
| 10    | 1010   |
| 32    | 10000  |
| 127   | 111111 |

## Exercise 2
Define a function that given two integer matrices, returns a new matrix, which is the result of the multiplication of the two input matrices.

```c++
int ** multiply_matrices(int ** left_matrix, int ** right_matrix, int rows, int columns);
```

### Input
On the first line there will be entered the numbers N and M, dimensions of the matrices corresponding to the rows and columns of the matrix.
On the next N lines there will be entered M numbers on each line which will be the elements of the left matrix.
Following those lines will come M more lines representing the contents of the right matrix with N numbers on each line.

### Output
Print the resulting matrix from the multiplication of the two matrices that were entered from the console.

### Examples

|                               Input                                   |                Output             |
| --------------------------------------------------------------------- | --------------------------------- |
| 1 3 <br> 1 2 3 <br> 4 <br> 5 <br> 6                                   | 32                                |
| 3 3 <br> 5 6 1 <br> 2 1 4 <br> 2 2 1 <br> 5 1 2 <br> 1 2 0 <br> 2 1 4 | 33 18 14 <br> 19 8 20 <br> 14 7 8 |
| 2 3 <br> 5 2 1 <br> 1 2 4 <br> 4 3 <br> 5 9 <br> 5 6                  | 35 39 <br> 34 45                  |

## Exercise 3
Define a function that given a stack of characters, it finds the sum of every third **digit** in the stack.

```c++
int sum_every_third_digit(CharStack stack);
```

### Examples

| Input | Output | Reason |
| :---: | :---: | :---: |
|![Stack1](images/stack-1.png) | 6 | ![Stack1 Solution](images/stack-1-solution.png) |
|![Stack2](images/stack-2.png) | 9 | ![Stack2 Solution](images/stack-2-solution.png) |

## Exercise 4
Define a function which given a stack, flips its elements in-place.

```c++
void flip_stack(CharStack& stack);
```

### Examples

![Flip Stack](images/flip-stack.png)
