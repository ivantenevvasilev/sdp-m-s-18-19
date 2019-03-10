#include <iostream>

using namespace std;
/* Преди
 * class Counter {
 *    int count;
 * }
 * - грешки - count не е достъпен в main()
 * - ако беше достъпен, бихме могли да го променим
 *   да бъде всякаква стойност, бихме искали да се променя
 *   само с 1 и да го регулираме.
 * */

// Написан по този начин винаги ще
// сме сигурни че броячът ще прави каквото очакваме
// - Да държи информация колко пъти е извикана функцията increment
// Нямаме мутатор void set_count(int count) 
// защото това би позволило да се наруши това свойство което искаме да запазим
class Counter {
  private:
     int count;
  public: 
     Counter() : count(0) {}
     
     void increment() {
        ++count;
     }

     // Функцията е const защото не променя член-данните на класът (директно или индиректно)
     int get_count() const {
        return count;
     }
};


// Примерна програма която брои броят на числата които се делят на 5
// използвайки Counter класът по-горе
int main() {
  Counter counter;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
     if (i % 5 == 0) {
         counter.increment();
     }
  }
 
  cout << counter.get_count();

  return 0;
}
