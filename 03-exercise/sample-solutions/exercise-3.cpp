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

void sort_rooms_by_price(Room * rooms, int count) {
    for (int i = 0; i < count - 1; ++i) {
        int min_id = i;
	for (int k = i + 1; k < count; ++k) {
            if (rooms[min_id].price() > rooms[k].price()) {
	        min_id = k;
	    }
	}
	swap(rooms[min_id], rooms[i]);
    }
}

void sort_rooms_by_size(Room * rooms, int count) {
    for (int i = 0; i < count - 1; ++i) {
        int min_id = i;
	for (int k = i + 1; k < count; ++k) {
            if (rooms[min_id].volume() > rooms[k].volume()) {
	        min_id = k;
	    }
	}
	swap(rooms[min_id], rooms[i]);
    }
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

