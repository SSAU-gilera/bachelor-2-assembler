// Asm_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h> // стандартный ввод/вывод
using namespace std;
// функция вычисления выражения        |  b/a+111,     > ;
//                                 		         X = |    -11,       = ;
//                                    			   | (11*a-1)/b,   < ;
bool err = 0;
int calc(int a, int b) {
	int res = 0;
	__asm {
		mov ecx, a;         ecx = a
		mov ebx, b;		    ebx = b
		cmp ecx, ebx;	    сравнение a и b
		jg l_bigger;	    переход если a > b
		jl l_smaller;       переход если a < b
		mov eax, -11;       eax = -11
		jmp exit_1;		    переход на конец программы
		l_bigger :
		or ecx, ecx;	    сравнение a и 0
			je error;	    ошибка деление на ноль
			mov eax, ebx;   eax = b
			cdq;			подготовка деления
			idiv ecx;	    eax = b / a
			add eax, 111;   eax = a / b + 111
			jmp exit_1;	    переход на конец программы
			l_smaller :
		or ebx, ebx;	    сравнение b и 0
			je error;		ошибка деление на ноль
			mov eax, ecx;	eax = a
			imul eax, 11;   eax = a * 11
			sub eax, 1;		eax = 11 * a - 1
			cdq
			idiv ebx;		eax = (11 * a - 1) / b
			jmp exit_1
			error : mov err, 1
			exit_1 :
			mov res, eax;	res = eax
	}
	return res;
}

void calc_cpp(int a, int b) {

	if (a > b) {
		if (a == 0) cout << "\n Результат С++: ошибка!\n";
		else cout << "\n Результат С++: " << b / a + 111 << endl;
	}
	else if (a == b) {
		cout << "\n Результат С++: " << -11 << endl;
	}
	else {
		if (b == 0) cout << "\n Результат С++: ошибка!\n";
		else cout << "\n Результат С++: " << (11 * a - 1) / b << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	bool m = true;
	while (m) {
		err = 0;
		cout << "Гижевская Валерия \n Группа 6113 \n Лабораторная работа №2 \n Вариант 52\n" << endl;
		cout << "      |  b/a + 111,    a > b" << endl;
		cout << " X =  |     -11,       a = b" << endl;
		cout << "      | (11*a - 1)/b,  a < b" << endl;
		cout << endl;
		cout << " a = ";
		cin >> a;
		cout << " b = ";
		cin >> b;
		int res = calc(a, b);
		if (err == 1)
			cout << "\n Ошибка! Деление на ноль." << endl;
		else
			cout << "\n Результат: X = " << res << endl;
		calc_cpp(a, b);
		cout << endl;
		system("PAUSE");
		system("cls");
	}
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
