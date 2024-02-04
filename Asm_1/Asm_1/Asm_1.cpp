// Asm_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;
// функция вычисления выражения (c*b - 24 + a)/((b/2)*c - 1);
bool err = 0;
int calc(int a, int b, int c)
{
	int result = 0;
	__asm {
		mov ecx, 2 //	ecx = 2
		mov eax, b //	eax = b
		cdq
		idiv ecx   //	eax = b/2
		mov ebx, eax//	ebx = eax
		mov ecx, c //	ecx = c
		mov eax, a //	eax = a
		imul ebx, ecx //ebx = (b/2)*c
		dec ebx //		ebx = (b/2)*c - 1
		je error;//проверка деления на 0
		push ebx
		mov ebx, b //	ebx = b
		imul ebx, ecx //ebx = c*b
		sub ebx, 24//   ebx = c*b - 24
		add ebx, eax // ebx = c*b - 24 + a
		push ebx
		pop eax //		eax = c*b - 24 + a
		cdq
		pop ebx //		ebx = (b/2)*c - 1
		idiv ebx //		eax = (c*b - 24 + a)/((b/2)*c - 1)
		jmp exit_1;
	error:
		mov err, 1;
		exit_1:
		mov result, eax;//result = (c*b - 24 + a)/((b/2)*c - 1)
	}
	return result; // возвращаем результат вычисления выражения
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	cout << "Гижевская Валерия 6113 Вариант 52" << endl;
	cout << "(c*b - 24 + a)/((b/2)*c - 1)" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	int resA = calc(a, b, c);
	if (err == 1)
	{
		cout << "Ошибка! Деление на ноль\n";
	}
	else {
		cout << "\nРезультат Assembler = " << resA << endl;
		int resCpp = (c * b - 24 + a) / ((b / 2) * c - 1);
		cout << "Результат C++ = " << resCpp << endl;
	}

	system("PAUSE");
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
