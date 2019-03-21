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

int main() {
   Room room;
   // Въвеждаме стаята от конзолата
   enter_room(room);

   // Принтираме от конзолата
   print_room(room);
   return 0;
}
