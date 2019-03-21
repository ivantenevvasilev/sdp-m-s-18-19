# Week 3

## Pretext
Let's presume that we're developing software for a hotel, we would like to describe what a room is in the given context. What's important for a hotel is the price of a room, because the rooms will be presented to clients. The dimensions of a room are of interest, because clients should know what they're going to be paying for. The hotel must also have a way to differentiate between two rooms, for that we introduce a room number (we wouldn't want the hotel to rent the room to two different clients).


## Exercise 1

Define a structure (or class) describing a **Room**.

A room for the purposes of our exercise will be defined by the following fields:

1. Room number (a non-negative number)
2. Dimensions (width, depth and height)
3. Rent for a day

For the type **Room** implement the following functions

1. Functions that access the fields
2. A function that calculates the volume of a room

## Exercise 2
Define a function that enters a room from that standart input and one that prints it to the standart output.

```c++
void print_room(Room& room);
void enter_room(Room& room);
```

The point of these two functions is to provide an easier way to visualize and enter the data with which we will be working in the following exercises.

### Input
We will input rooms in the format `<room number> <width> <depth> <height> <price>`
The input and output can be in another format, but in that case the sample data will have to be tweaked to fit your own format which would make it a bit harder to follow.

|       Input       |                                          Description                                                 |
| ----------------  | ------------------------------------------------------------------------------------------------  |
| 0 50 50 20 21.50  | Room #0 with a **width** of 50, **depth** of 50, **height** of 20, and **rent** for a day at the cost of 21.50  |
| 23 43 62 12 55.73 | Room #23 with a **width** of 43, **depth** of 62, **heihgt** of 12, and **rent** for a day at the cost of 55.73 |
| 4 20 25 10 10     | Rooom #4 with a **width** of 20, **depth** of 25, **height** of 10, and **rent** for a day at the cost of 10     |


### Printing
We will print a Room in the following format:
`Room #<номер> has dimensions (<width>, <depth>, <height>) and volume <volume> is available for $<price> per day`

The room in the example will be in the same format as the input, as shown in the previous segment.

|      Room         |                                        Output                                                      |
| ----------------- | -------------------------------------------------------------------------------------------------- |
| 0 20 20 20 15.10  | Room #0 has dimensions (20, 20, 20) and volume 8000 is available for $15.1 per day                 |
| 0 50 50 20 21.50  | Room #0 has dimensions (50, 50, 20) and volume 50000 is available for $21.5 per day                |
| 23 43 62 12 55.73 | Room #23 has dimensions (43, 62, 12) and volume 31992 is available for $55.73 per day              |
| 4 20 25 10 10     | Room #4 has dimensions (20, 25, 10) and volume 5000 is available for $10 per day                   |


## Exercise 3
Implement a sorting function which orders the rooms in an ascending order by volume and another sorting function that does the same but sorts by price.

```c++
void sort_rooms_by_size(Room * rooms, int count);
void sort_rooms_by_price(Room * rooms, int count);
```

For easy testing you can use the following functions
```c++
void print_room_array(Room * rooms, int count) {
	for (int i = 0; i < count; ++i) {
		print_room(rooms[i]);
	}
}

void enter_room_array(Room * rooms, int count) {
	for (int i = 0; i < count; ++i) {
        enter_room(rooms[i]);
	}
}

int main() {
	int count;
	Room rooms[100];
	cin >> count;
	enter_room_array(rooms, count);
	sort_rooms_by_price(rooms, count);
	// or sort_rooms_by_size(rooms, count); for other example
	print_room_array(rooms, count);
	return 0;
}

```

Sample output for the function `sort_rooms_by_size`

|       Input      | Output (sorted by size, ascending) |
| --------------- | ---------------------------------- |
|4 <br> 0 20 20 20 15.10 <br> 0 50 50 20 21.50 <br> 23 43 62 12 55.73 <br> 4 20 25 10 10|Room #4 has dimensions (20, 25, 10) and volume 5000 is available for $10 per day<br>Room #0 has dimensions (20, 20, 20) and volume 8000 is available for $15.1 per day<br>Room #23 has dimensions (43, 62, 12) and volume 31992 is available for $55.73 per day<br>Room #0 has dimensions (50, 50, 20) and volume 50000 is available for $21.5 per day|

Sample output for the function `sort_rooms_by_price`

|
       Input      | Output (sorted by price, ascending) |
| --------------- | ---------------------------------- |
|4 <br> 0 20 20 20 15.10 <br> 0 50 50 20 21.50 <br> 23 43 62 12 55.73 <br> 4 20 25 10 10 | Room #4 has dimensions (20, 25, 10) and volume 5000 is available for $10 per day <br>Room #0 has dimensions (20, 20, 20) and volume 8000 is available for $15.1 per day <br>Room #0 has dimensions (50, 50, 20) and volume 50000 is available for $21.5 per day<br>Room #23 has dimensions (43, 62, 12) and volume 31992 is available for $55.73 per day|


**Bonus**:
The two funcions as code would be almost identical, the only differance being the comparison of two rooms.
Programmers are usually lazy and most likely would do one of two things:
1. Copy the function and change the comparison
2. Think of a more general idea to save time

The first solution has a fundamental problem, and it is that if we assume that there is a bug in the first one, then by copying it that same bug will be present in two places. If we find that bug later on and fix it, there is a chance that we forget to fix it on the other places where we have the code copied to. In the case of two copies it isn't really hard for a person to remember, but when there are many more copies and multiple people working on the same code-base the chances rise drastically. What could we do to prevent that from happening?

In C++ there is a thing called [higher-order functions](https://www.learncpp.com/cpp-tutorial/78-function-pointers/).
A higher-order function is a function that does one of two things:
* Accepts a function as a function argument
* Returns a function as the result of it's execution

In our case the first sounds like the thing that could save us. What we would like is to have a sorting function which can specify **how** we compare two Rooms.
```c++
// Sorts rooms, swapping elements if the left room is "bigger" than the right one
// By "bigger" we mean that we evaluate it with a bigger value than we do the right
void sort_rooms(Room * rooms, int count, bool(*comparator) (Room& left, Room& right));

// Assuming that the function price is the accessor function for the price field
bool is_room_more_expensive(Room& left, Room& right) {
    return left.price() > right.price();
}

// Assuming that the function volume is the function getting the volume of the room
bool is_room_bigger(Room& left, Room& right) {
    return left.volume() > right.volume();
}
```
What do we gain if were to write it this way?
1. We can write different functions that compare given other criteria.
2. We can sort in reverse order by just negating the boolean fucntion
3. If we change the sorting algorithm, we have one single place which we have to change and the code will continue functioning.

## Exercise 4
Implement a function that given an array of rooms, sums their prices.
```c++
double sum_prices_for_rooms(Room * rooms, int count);
```
Sample output for the function `sum_prices_for_rooms`

|       Input                                                                            | Result |
| -------------------------------------------------------------------------------------- | -------- |
|4 <br> 0 20 20 20 15.10 <br> 0 50 50 20 21.50 <br> 23 43 62 12 55.73 <br> 4 20 25 10 10 |  102.33  |

## Exercise 5
Implement a function reserve_room with the following signature:
```c++ 
bool reserve_room(Room * rooms, int room_count, int room_number);
``` 
Where in the case of finding a room with the same room number, it gets removed from the array and the elements of the array that are after the found room get shifted left by one position. (to keep the array consistent e.g. no empty rooms or null pointers)
In the case that a room with the number that is to be searched is not present in the array, the function should return false and not modify the array. We need this because when removing an element from the array, the array "changes" its size, but if there isn't an element to be removed, ther size does not change. This will be our way of indicating whether or not the array has shrunk.

**Example**:

|       Input                                                                                                   | State of the array after execution                 | Returned value | Description                                                                                                                                              |
| ------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
| room_number: 0 <br> room_count: 1 <br> rooms: [(0 20 20 20 15.10)]                                           | rooms: []                                            |      true       | Room #0 is found in the array and is removed from it, leaving it empty. Function returns true, because an element has been removed.                |
| room_number: 3 <br> room_count: 1 <br> rooms: [(0 20 20 20 15.10)]                                           | rooms: [(0 20 20 20 15.10)]                          |      false      | Room #3 is not found in the array, the array is unchanged and the returned value is false                                                 |
| room_number: 4 <br> room_count: 1 <br> rooms: [(0 20 20 20 15.10), **(4 20 25 10 10)**, (23 43 62 12 55.73)] | rooms: [(0 20 20 20 15.10), (23 43 62 12 55.73)]     |      true       | Room #4 is found and removed, all elements after it are shifted left by one position, and the result is true because an element has been removed |
