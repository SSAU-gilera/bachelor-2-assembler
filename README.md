# Организация ЭВМ и вычислительных систем

#### Зеленко Лариса Сергеевна

1 курс 2 полугодие (2 семестр)

### Варианты

| Лабораторная работа | Вариант |
| :------------------ | :------ |
| 1                   | 52      |
| 2                   | 52      |
| 3                   | 52      |
| 4                   | 52      |
| 5                   | 52      |
| 6                   | 30      |
| 7                   | 30      |

# Лабораторные работы

> Если в папке лабораторной работы нет файлов программы или появляются ошибки при запуске, вы всегда можете найти код в конце отчёта.

## Лабораторная работа 1

Арифметические и логические команды в ассемблере.

**Задание**

1. В программе необходимо реализовать функцию вычисления целочисленного выражения `(с * b – 24 + a) / (b / 2 * c – 1)` на встроенном ассемблере MASM в среде Microsoft Visual Studio на языке C++.
2. Значения переменных передаются в качестве параметров функции.
3. Результат выводить в консольном приложении (проект – консольное приложение Win32).
4. В программе реализовать ввод переменных из командной строки и вывод результата на экран.
5. Все параметры функции 32-битные числа (знаковые и беззнаковые).
6. Первые строки функции вычисления выражения заносят значения аргументов функции в соответствующие регистры.
7. Необходимо реализовать проверки вводимых данных и вычисления отдельных операций. Например, проверка деления на 0.
8. В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
9. По возможности использовать команды сдвига.

## Лабораторная работа 2

Арифметические и логические команды в ассемблере.

**Задание**

1. В программе необходимо реализовать функцию вычисления заданного условного целочисленного выражения, используя команды сравнения, условного и безусловного переходов на встроенном ассемблере.

![Формула](https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-2.png)

2. Результат X – целочисленный, возвращается из функции в регистре eax.
3. Значения переменных передаются в качестве параметров функции.
4. В программе реализовать вывод результата на экран.
5. Все параметры функции 32-битные числа.
6. Проверку деления на 0 реализовать также на встроенном ассемблере.
7. В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
8. По возможности использовать команды сдвига.

## Лабораторная работа 3

Команды работы с массивами и стеком.

**Задание**

1. В программе необходимо реализовать функцию обработки элементов массива используя команды сравнения, переходов и циклов на встроенном ассемблере.
2. Результат – целочисленный, возвращается из функции регистре eax.
3. Массив передаётся в качестве параметра функции.
4. В программе реализовать вывод результата на экран.
5. В качестве комментария к каждой строке необходимо указать, какое действие выполняет команда относительно массива.

Условие: сформировать новый массив из одномерного массива `A={a[i]}` целых чисел по следующему правилу:

![Формула](https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-3.jpg)

## Лабораторная работа 4

Изучение работы математического сопроцессора в среде Assembler.

**Задание**

1. В программе необходимо реализовать функцию вычисления заданного условного выражения на языке ассемблера с использованием команд арифметического сопроцессора.

![Формула](https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-4.jpg)

2. Значения переменных передаются в качестве параметров функции.
3. В программе реализовать вывод результата на экран.
4. Все параметры функции имеют тип double.
5. Проверку деления на 0 реализовать также на встроенном ассемблере.
6. В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
7. В качестве комментария к строкам, содержащим команды сопроцессора, необходимо указать состояние регистров сопроцессора.
8. Результат можно возвращать из функции в вершине стека сопроцессора.

## Лабораторная работа 5

Нахождение корней уравнения методом Ньютона на языке ассемблера.

**Задание**

1. В программе необходимо найти с заданной точностью ε корень уравнения `f(x)=0` методом Ньютона на языке ассемблера с использованием команд арифметического сопроцессора.
2. Значения переменных передаются в качестве параметров функции.
3. Составить таблицу расчетов корня уравнения на заданном отрезке `[a;b]` и вывести на экран.
4. Все параметры уравнения имеют тип double.
5. Проверку деления на 0 реализовать также на встроенном ассемблере.
6. Если на заданном интервале `[a;b]` не найден корень уравнения, то вывести соответствующее сообщение.
7. В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
8. В качестве комментария к строкам, содержащим команды сопроцессора, необходимо указать состояние регистров сопроцессора.
9. Результат можно возвращать из функции в вершине стека сопроцессора.

Условие: `𝑓(𝑥) = −5 + 30𝑥 + 39𝑥^2 − 39𝑥^3 − 29𝑥^4 − 47𝑥^5 + 25𝑥^9 + 𝑥^10`

## Лабораторная работа 6

Вычисление определенного интеграла методом Симпсона на языке ассемблера.

**Задание**

1. В программе необходимо вычислить определённый интеграл при заданном числе интервалов N методом Симпсона на языке ассемблера с использованием команд арифметического сопроцессора.
2. Значения переменных передаются в качестве параметров функции.
3. Составить таблицу расчетов вычисления интеграла при заданном числе интервалов N и вывести на экран. Выводить пошаговый расчет интеграла по формуле Симпсона
   ![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-6(1).jpg>)
4. Все параметры уравнения имеют тип double.
5. Проверку деления на 0 реализовать также на встроенном ассемблере.
6. Если не найден корень интеграла, то вывести соответствующее сообщение.
7. В качестве комментария к каждой строке необходимо указать, какой промежуточный результат, в каком регистре формируется.
8. В качестве комментария к строкам, содержащим команды сопроцессора, необходимо указать состояние регистров сопроцессора.
9. Результат можно возвращать из функции в вершине стека сопроцессора.

Условие:

![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-6(2).jpg>)

## Лабораторная работа 7

Вычисление суммы ряда на языке ассемблера

**Задание**

1. В программе необходимо реализовать функцию определения значения некоторой элементарной функции y, зависящей от аргумента x, на языке ассемблера с использованием команд арифметического сопроцессора.
2. Функция вычисляется в виде суммы ряда. Вычисления прекращаются если ![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-7(1).jpg>), где ![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-7(2).jpg>) – последующий член ряда; ![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-7(3).jpg>) – предыдущий член ряда. Кроме того, на случай плохой сходимости следует ограничить количество слагаемых сверху некоторым наперёд заданным N, т.е. выход их вычислительной процедуры может произойти не по условию ![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-7(4).jpg>), а по условию k>N. Значение функции и количество итераций вывести для контроля на экран.
3. Значение параметров x, ε и N передаются в качестве аргументов функции.
4. Необходимо определить достигнутую погрешность, вычислив отклонение аналитического значения от значения, вычисленного с помощью ряда. Значение погрешности также вывести для контроля на экран.
5. В качестве комментария к строкам, содержащим команды сопроцессора, необходимо указать состояние регистров сопроцессора.

Условие:

![Формула](<https://github.com/SSAU-gilera/bachelor-2-assembler/blob/main/src/img-task-7(5).jpg>)
