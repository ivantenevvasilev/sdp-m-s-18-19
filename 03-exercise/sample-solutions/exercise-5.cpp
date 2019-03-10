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

bool reserve_room(Room * rooms, int room_count, int room_number) {
   // Проверяваме дали номерът на стаята съвпада със всяка една стая
   for (int i = 0; i < room_count; ++i) {
      if(rooms[i].room_number() == room_number) {
	  // Ако стигнем тук значи сме открили стая
	  // Трябва да я изтрием и върнем истина.
	  // Ще го направим като за всеки елемент след нашият
	  // го презаписваме със следващият, така всеки ще бъде с
	  // 1 позиция наляво, а намереният ще бъде презаписан
	  for (int k = i + 1; k < room_count; ++k) {
	      rooms[k - 1] = rooms[k];
	  }
	  return true;
      }
   }
   return false;
}

int main() {
   Room rooms[100];
   int n;
   cin >> n;
   enter_room_array(rooms, n);
   int numbmer_to_remove;
   cin >> numbmer_to_remove;
   cout << "Before reserve_room\n";
   print_room_array(rooms, n);
   bool result = reserve_room(rooms, n, numbmer_to_remove);
   if (result) {
       --n;
   }
   cout << "Return value: " << result << endl;
   cout << "After reserve_room\n";
   print_room_array(rooms, n);
   return 0;
}
