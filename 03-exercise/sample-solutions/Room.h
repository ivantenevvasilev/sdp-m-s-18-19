#ifndef DEFINE_ROOM
#define DEFINE_ROOM

class Room {
  private:
     // Именувал съм полетата с префикс m_ за да не се препокриват с функциите за достъп
     // m значи member, тоест член променлива
     int m_room_number;
     double m_width;
     double m_depth;
     double m_height;
     double m_price;
  public:
      // Създаваме празен конструктор защото за да създадем масив от стаи, трябва да имат такъв.
      // В празният конструктор слага на всички стойности техните стойности по подразбиране
      Room();
      Room(int room_number, double width, double depth, double height, double price);

      // Функции за достъп до член променливите
      // Слагаме const на краят на функцията за да се подсигурим че няма да променяме
      // член-променливите на this (текущата инстанция) на обекта.
      // Така хората които го използват ще знаят със сигурност че нищо не се променя
      // и ще може да бъде извиквана от други функции които имат const накрая
      // Ако имаме обект от тип const Room ще можем да достъпваме само const функции на този обект
      // защото не би трябвало да можем да променяме състоянието от обект който е константен.
      int room_number() const;
      double width() const;
      double depth() const;
      double height() const;
      double price() const;

      // Тази функция не променя член-данните за това можем да я направим също да е const
      double volume() const;

      // Тези функции променят състоянието на обекта, и се очаква това от тях
      // За това не са const
      void set_room_number(int room_number);
      void set_width(double width);
      void set_depth(double depth);
      void set_height(double height);
      void set_price(double price);
};

#endif
