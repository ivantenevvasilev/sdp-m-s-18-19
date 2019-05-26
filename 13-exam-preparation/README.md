# Задача 1
Иванчо живее в миналия век, затова на мобифона си държа телефонните номера на своите приятели и това е единствената му връзка с тях.
Един ден Марийка му взима мобифона и размества цифрите в телефонните му номера, така че той да не може да се обади на никого.

За щастие на Иванчо обаче, Марийка не ги е разместила много умно, затова те могат да бъдат възстановени. Всеки номер е разместен по един и същи начин: в началото са цифрите на четните позиции в нарастващ ред, тоест позиция 0, 2, 4, 6, 8, а след тях са нечетните позиции в намаляващ ред, тоест 9, 7, 5, 3, 1.
Например номерът `0923456781` Марийка го е превърнала в `0246817539`. `0891237146` е преврънала в `0927461318`.

Иванчо се обръща към вас за помощ. Задачата ви е да напишете програма, която приема неговите разбъркани телефонни номера и ги възстановява в правилния им вид.

### Вход
На първия ред от стандартния вход ще има едно цяло число `n` – броят номера, които Иванчо е записал в мобифона си.

Следват `n` на брой реда, на всеки от които е записан по един телефонен номер, разместен от Марийка.

### Изход
На стандартния изход трябва да изведете `n` на брой реда, на всеки от които да е възстановеният телефонен номер от входа.