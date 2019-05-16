# Week 10

During lectures we took a look at the abstract data structure - Queue. We know that it is an abstract data structure in which elements are removed from the start and added to the end (FIFO, First in, first out). This aligns with the way we think of a queue in real life, and in reality queues have many uses in programming. For this exercise we will be mainly using queues.

## Exercise 1
Implement a Queue
We will need the following methods for this exercise.
It will be made using a template class because just as other abstract data structures, it does not depend on the type - its job is to give us the specific order to access the elements.

```c++
class Queue {

  ... other things ...

  void push(const T& x); // adds an element to the queue 
  void pop(T& x); // removes an element from the queue 
  void head(T& x) const; // gives us the first element from the queue
  bool empty() const; // returns if there are any elements in the queue
  
  ... other things ...

};
```

## Exercise 2
Define a function which prints a Queue, without modifying the original.

```c++
void print_queue(<template queue> queue);
```

This function will be useful for debugging in the later tasks.

## Exercise 3
Define a function, which flips the elements of a stack, using a queue.

## Exercise 4
Define a function, which flips the elements of a queue, using a stack.

## Exercise 5
Define a function that acceps a queue `q` and a number `n`.

Let the element in the beginning of the queue is with number `1` and every following element has has a numbre one larger than the previous.
The function should change `q` in such a way that it should not contain the element on the `n`th position, but all other elements should be intact

We can assume that the queue has enough elements.

```c++
T pop_nth(Queue<T>& q, int n)
```

### Examples 

| Input objects | Objects after the call to `pop_nth(q, n)` |
| ----- | ---------------------- |
| q: 1 2 3 4 <br>n: 3 | q: 1 2 4 |
| q: 7 1 2 3 4 <br>n: 1 | q: 1 2 3 4 |
| q: -1 44 10 <br>n: 2 | q: -1 10 |

## Exercise 6
Lets implement a class Task, which will represent a thing that has to be done.
For us it will be a simple text, with a maximum size of a 100 characters.

Define a function that accepts a Queue of Tasks, that does the tasks in the order in which they are added (requested).

By "doing a task" we mean printing it in a suitable way.

## Exercise 7 - [The Josephus Problem](https://en.wikipedia.org/wiki/Josephus_problem)
A number of people are arranged in a circle. They are being killed in the following fashion - when a person is killed, there are `k` people that are skipped, and then follows the next one killed. This continues until there is a single person remaining. The task is to find the initial position of the person who survives.

Define a function `int getSafePosition(int n, int s, int k)` that accepts arguments:
 - `n` - number of people initially 
 - `s` - initial position
 - `k` - count of people that are skipped

The function should return the initial position of the last one standing.

This task has a mathmatical solution, which is rather complicated, but we will wo it the more direct (and slower) way, simulating it using a queue.

