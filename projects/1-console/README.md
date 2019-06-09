# Проект 1 - Конзола
Какво представлява една конзола?
- Тя изписва текст на екрана и има вход от потребител
- Текстът който ни показва е форматиран, тоест ако принтираме число/знак не ни връща нули и единици - а нещо четимо от човек.
- Входът в типичен конзола се взима от клавиатурата, а изходът се изписва на екранът
- Конзолата има някакъв размер - височина и широчина - съответно това поставя граници за броят на знаци на всеки ред. Височината няма голямо значение, защото ако се препълни екрана, то ни дава възможност да скролваме вертикално.Ще се възползваме от това от това за нашата конзола. Обаче проблемът с широчината остава. Никой не обича хоризонтален скрол.

## Нашата задача 
За нас конзола ще представлява клас който държи съдържанието за изписване на екранът, а входът ще идва от функцията `append`. Предимно няма да отделяме твърде много време за това как се превръщат типове към текст, освен за тези типове за които е проста тази трансформация, част от по-сложните ще са предоставени като код.

Изходът на конзолата ни ще се изписва в истинската конзола когато се извикат неговите `print` функции. Нещото което трябва да имаме в предвид е, че нещата които постъпват първо в буферът са тези които първи се изписват и също така след изписване (извикване на `print` функция) текстът който се показва, вече не е част от буфера.

Иска се да се имплементира клас `Console`

```c++
class Console {
public:
   Console();
   Console(int character_limit_per_line);
   Console(int character_limit_per_line, char fill);

   void append(char element);
   void append(const char * element);
   void append(int element);
   
   void print_characters(int character_count);
   void print_lines(int line_count);
   void print();

   void align_left();
   void align_right();

   void clear();
   void clear(int character_count);
   
   void set_fill(char fill);
   char get_fill() const;

   int get_line_limit() const;
   void set_line_limit(int character_limit);

   long get_buffer_size() const;
};
```

Идеята е следната:
- Конзолата ни държи буфер от знаци които да се принтират.
- `clear()` изпразва буферът
- `clear(int character_count)` - маха първите `n` знака от буфера
- `print()` принтира целият буфер на екрана, като на даден ред не принтира повче от стойността на `get_line_limit()` знака на всеки ред. При достигане на тази бройка просто продължава принтирането на следващият ред. Като приключи изпълнението буферът трябва да е празен.
- `print_characters(int character_count)` - принтира `character_count` на брой знака от буфера, като при повече от `get_line_limit()` знака на текущият ред минава на следващият.
- `print_lines(int line_count)` принтира докато не мине завърши `line_count`ият ред.
- `append(T element)` добавя елементът като поредица от символи накрая (повече информация за какво да прави append, ще обсъдим по-долу) - където `T` е един от следните типове: `int`, `char`, `const char *`.
- `set_line_limit(int character_limit)` променя максималният брой на символи на даден ред (ествствено `character_limit` се предполага че е по-голямо от 0).
- `get_buffer_size()` - връща броят на знаци които предстоят да бъдат принтирани.
- `align_left()` - това е режимът по подразбиране, текстът се принтира нормално, започвайки от началото на редът стигайки до краят. Ако е в режим ляво подравняване и тази функция бъде извикана си остава непроменен. Ако се срещне знак за нов ред преди `line_limit` знака, принтира знакът `fill` до краят на редът.
- `align_right()` - променя режимът в дясно подравняване, ако редът свърши преди `line_limit` на брой знаци, то в началото се слагат `line_limit - n` `setfill` знака където `n` е броят принтирани на редът.
- `set_fill(char fill)` - слага знакът за запълване от до краят на новият ред (или от началото, зависи от подравнеността) на `fill`, по подразбиране ако не е подаден `fill` на конструктора е знакът за празно място `' '` 
# Примери
## За ляво подравняване (`left_align()`)
### Пример 1

Съдържание на буфера:
```
This text is split
on multiple
lines
So very long lines will be wrapped and short ones will not.
```

Изход след функцията `print()` и максимален брой знаци на ред: 19

```
This text is split
on multiple
lines
So very long lines
 will be wrapped an
d short ones will n
ot.
```


### Пример 2

Съдържание на буфера (тук няма нови редове):
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque facilisis justo nec nulla mollis, vitae vehicula ex rutrum. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Duis quis fringilla eros, eu ullamcorper nibh. Fusce ullamcorper dignissim nisi, vitae laoreet mauris. Sed commodo quis diam in mattis. Sed interdum nibh enim, vitae fringilla lectus varius ut. Mauris quis tempus sem. Sed mauris orci, laoreet ut malesuada ut, tempus et neque. Suspendisse aliquam convallis dui, id consequat odio congue vehicula. Quisque ac libero leo. Suspendisse tortor lorem, euismod vitae luctus a, sagittis nec ante. Cras ornare efficitur posuere. Nulla eu mollis dolor.
```

Изход след функцията `print()` и максимален брой знаци на ред: 32

```
Lorem ipsum dolor sit amet, con
sectetur adipiscing elit. Quisqu
e facilisis justo nec nulla moll
is, vitae vehicula ex rutrum. Or
ci varius natoque penatibus et m
agnis dis parturient montes, nas
cetur ridiculus mus. Duis quis f
ringilla eros, eu ullamcorper ni
bh. Fusce ullamcorper dignissim 
nisi, vitae laoreet mauris. Sed 
commodo quis diam in mattis. Sed
 interdum nibh enim, vitae fring
illa lectus varius ut. Mauris qu
is tempus sem. Sed mauris orci, 
laoreet ut malesuada ut, tempus 
et neque. Suspendisse aliquam co
nvallis dui, id consequat odio c
ongue vehicula. Quisque ac liber
o leo. Suspendisse tortor lorem,
 euismod vitae luctus a, sagitti
s nec ante. Cras ornare efficitu
r posuere. Nulla eu mollis dolor
.
```

### Пример 3
Съдържание на буфера и максимален брой на знаци на ред - като предишният пример

Резултат от `print_lines(2)` последван от `print_characters(14)`

```
Lorem ipsum dolor 
sit amet, consectet
ur adipiscing e
```
