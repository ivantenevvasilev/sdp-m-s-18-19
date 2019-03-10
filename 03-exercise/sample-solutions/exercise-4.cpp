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

void enter_room_array(Room * rooms, int count) {
	for (int i = 0; i < count; ++i) {
             enter_room(rooms[i]);
	}
}

// Даже можем да направим сигнатурата const Room * rooms
// защото във самата функция ние не променяме нито една стая
// и също така защото функцията price която ползваме е дефинирана
// като const
double sum_prices_for_rooms(Room * rooms, int count) {
    // В началото сумата е 0 защото нямаме стаи
    double sum = 0;

    // Сумата на цените на стаите е просто сумата на цената на всяка една от тях
    for (int i = 0; i < count; ++i) {
        sum += rooms[i].price();
    }
    return sum;
}

int main() {
   Room rooms[100];
   int n;
   cin >> n;
   enter_room_array(rooms, n);
   cout << sum_prices_for_rooms(rooms, n) << endl;

   return 0;
}
