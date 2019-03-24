# Week 4
## Exercise 1
Define a class `Point3`, which represents a point in space.
Define a class `Cuboid`, describing a parallelepiped.

We will say that a parallelepiped is *cannonical*, when its sides are rectangular and its sides are parralel to the coordinate axis.

### 1.1
Define a function `fromPoint` which takes 8 points in space.

If these 8 points are edges of a _cannonical_ parallelepiped, then `fromPoints` returns that parallelepiped.

Otherwise `fromPoints` returns a parralelepiped with a width, depth and height equal to zero.

### 1.2
Define a function which takes an array of _cannonical_ parallelepiped and finds the one with the largest volume.

### 1.3
Define a function which given an array of _cannonical_ parallelepiped, prints out on the screen those that have a larger than the average volume of the parallelepipeds in the array.

### 1.4
Define a function which sorts _cannonical_ parallelepipeds by volume, ascending.

### 1.5*
Define a function which finds the intersection of _cannonical_ parallelepipeds given an array of them.

It is enough to implement a function that finds the intersection of two _cannonical_ parallelepipeds, with it we easily could implement it for a any number of parallelepipeds.


## Exercise 2*
We are given a rule for an expression of the following format:
```
<expression> ::= <digit> | f(<expression>,<expression>,<expression>) | g(<expression>,<expression>,<expression>)
<digit> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```
where
```
f(x,y,z) = (x+2y+3z)%10
g(x,y,z) = (2x+3y+7z)%10
```
Define a function that takes as an argument an expression of the given format and calculates it.
