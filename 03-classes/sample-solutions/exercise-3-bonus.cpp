#include <iostream>

#include "Room.h"

using namespace std;

void enter_room(Room& room) {
   int room_number;
   cin >> room_number;
   room.set_room_number(room_number);
   double temp;
   cin >> temp;
   room.set_width(temp);
   cin >> temp;
   room.set_depth(temp);
   cin >> temp;
   room.set_height(temp);
   cin >> temp;
   room.set_price(temp);
}

void print_room(Room& room) {
   cout << "Room #" <<
           room.room_number() << 
           " has dimensions (" << 
           room.width() << 
           ", " << 
           room.depth() << 
           ", " << 
           room.height() <<
           ") and volume " << 
           room.volume() <<
           " is available for $" << 
           room.price() << 
           " per day" << 
           endl;
}


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

void swap(Room& a, Room& b) {
    Room temp = a;
    a = b;
    b = temp;
}

// Сортира стаи, като ги размества ако лявата стая е "по-голяма" от дясната
// Под "по-голяма" се има предвид оценява с по-голяма стойност от дясната
void sort_rooms(Room * rooms, int count, bool(*comparator) (Room& left, Room& right)) {
    for (int i = 0; i < count - 1; ++i) {
        int min_id = i;
	for (int k = i + 1; k < count; ++k) {
	    // comparator е проста функция която приема две стаи и връща булева стойност
	    if (comparator(rooms[min_id], rooms[k])) {
	        min_id = k;
	    }
	}
	swap(rooms[min_id], rooms[i]);
    }

}

// Предполагайки че член-функцията price връща цената на стая
bool is_room_more_expensive(Room& left, Room& right) {
    return left.price() > right.price();
}

// Предполагайки че член-функцията volume връща обема на стаята
bool is_room_bigger(Room& left, Room& right) {
    return left.volume() > right.volume();
}
void sort_rooms_by_price(Room * rooms, int count) {
  sort_rooms(rooms, count, is_room_more_expensive);
}

void sort_rooms_by_size(Room * rooms, int count) {
   sort_rooms(rooms, count, is_room_bigger);
}


int main() {
	int count;
	Room rooms[100];
	cin >> count;
	enter_room_array(rooms, count);
	//sort_rooms_by_price(rooms, count);
        sort_rooms_by_size(rooms, count);
	print_room_array(rooms, count);
	return 0;
}

