# Упражнение 5

Както сме виждали, стекът (`Stack`) е абстрактна структура от данни, която може да пази някакво количество данни от един и същ тип.

Стекът добавя данни в единия си край (върха) и премахва данни от същия край (LIFO). Също така предоставя достъп до елемента на върха и може да върне дали съдържа елементи.

Това е доста общо казано и може по няколко начина да се реализира стек. Сега ще направим един от тях.

## Задача 1
Нека си напишем собствен клас `CharStack`, който реализира стек от символи (`char`). Елементите на стека ще пазим в негов си низ с максимална дължина примерно 256.
Също ще ни трябва и целочислена променлива, която пази позицията на върха на стека.

Трябва да може да се създава празният стек. Ще дефинираме и следните функции:
```c++
char top() const;  // връща елементът на върха на стека
void push(const char c); // добавя елемент в стека
char pop();  // премахва елемент от стека
bool is_empty() const; // връща булева стойност, дали стекът е празен
```

Разбира се, можете по ваша преценка да си сложите и други методи в класа, ако те ви помагат за някоя задача.

## Задача 2
Нека сега решим задачата от миналия път:

Даден е правилно написан израз от вида:
```
<израз> ::= <цифра> | f(<израз>,<израз>,<израз>) | g(<израз>,<израз>,<израз>)
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```
където
```
f(x,y,z) = (x+2y+3z)%10
g(x,y,z) = (2x+3y+7z)%10
```
Да се дефинира функция, която приема такъв израз под формата на низ и го изчислява.

### Например
| Вход                     | Изход |
| :----------------------- | ----- |
| "9"                      | 9     |
| "f(g(1,2,3),4,f(5,6,7))" | 1     |
| "f(1,g(2,3,4),f(5,6,7))" | 7     |

## Задача 3
XML е текстов формат за обмен на данни. Той е пригоден да се обработва лесно от компютри, както и да е четим за хора.

XML определя така наречените тагове, които са някакво име, заградено от триъгълни скоби.
Има два вида тагове - отварящи, примерно `<something>`, и затварящи - `</otherthing>`.
Между един отварящ и един затварящ таг с едно и също име може да има всякакъв текст, включително и други тагове.
По този начин един таг може да е 'родител' на (тоест да съдържа) няколко други тага.

Обаче за да e **коректен** XML-ът, трябва всеки родител да се затваря след като всеки таг, който съдържа, е затворен.
Също така трябва всеки таг да бъде затворен и да няма затварящи тагове, на които не съответстват отварящи тагове.

### Например
Това **не** е _коректен_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
                            </a> -- <a> is closed before <c>, but <a> contains <c>
   </c>
```

Това също **не** е _коректен_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
   </c>

-- <a> is never closed
```

И това **не** е _коректен_ XML
```xml
<b></b>
</a>
```

Това вече е _коректен_ XML
```xml
<a>
   <b> <d>     whitespace doesn't matter       </d>
   </b> but makes things more readable
   <c>
   </c>
           </a>
```

С цел улеснение ще разглеждаме само XML, който съдържа единствено тагове с еднобуквени имена и удовлетворява горните дефиниции (в действителност XML включва повече неща, но те не ни интересуват).
Тоест ще разглеждаме текст единствено с тагове от типа `<a>` и `</a>`.

### Самата задача
Да се напише функция, която приема низ и връща булева стойност, която указва дали низът е _коректен_ XML.
_Забележка_: "some text without tags" е _коректен_ XML по нашата дефиниция.