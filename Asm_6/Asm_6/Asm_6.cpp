// Asm_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

double integral_asm(double a, double b, int n) {
	printf("%3s%14s%20s%15s%20s\n", "i", "x", "f(x)", "Коэф.", "Сумма");
	int N = 2 * n, i, k;
	const int c3 = 3;
	double x, f, _sum;
	__asm {
		;				//	st(0)			st(1)				st(2)		st(3)	st(4)
		finit;			//инициализация сопроцессора
		xor esi, esi;	//esi = 0
		mov edi, N;		//edi = 2n
		fldz;			//sum = 0
		fld a;			//a					sum = 0
		fld b;			//b					a					sum = 0
		fsub st, st(1);	//b - a				a					sum = 0
		fidiv N;		//(b - a) / 2n		a					sum = 0
		fxch;			//x = a             (b - a) / 2n = h	sum = 0
	begin_loop:
		mov i, esi;		//i = esi;
		fst x;			//x = st(0)
		fld		st;		//x					x					h			sum
		fmul	st, st;	//x*x				x					h			sum
		fild c3;		//	3				x*x					x			h		sum
		fmulp st(1),st;	//3 * x*x 			x					h			sum
		fsub st, st(1);	//3 * x*x - x 		x					h			sum
		fld1;			//1					3 * x*x - x 		x			h		sum
		fsubp st(1), st;//3 * x*x - x - 1	x					h			sum
		fst f;			//f = st(0)
		mov k, 1;		//k = 1
		or esi, esi;	//сравниваем номер с 0
		je sum;			//если равны, то k = 1, переходим к метке sum
		cmp esi, edi;	//сравниваем номер и 2n
		je sum;			//если номер = 2n, то k = 1, переходим к метке sum
		test esi, 1;	//проверяем номер на четность
		jne odd;		//если номер нечетный, переход к метке odd
		mov k, 2;		//k = 2
		jmp sum;		//переходим к метке sum
	odd :
		mov k, 4;		//k = 4
		jmp sum;		//переходим к метке sum
	sum :
		fimul k;		//k * (3 * x* x - x - 1)	x			h			sum
		faddp st(3), st;//x					h	sum + k * (3 * x * x - x - 1)
		fld st(2);		//sum				x					h			sum
		fstp _sum;		//_sum = st(0)
	}
	printf("%3i%14.6f%20.6f%15i%20.6f\n", i, x, f, k, _sum);
	__asm {
		inc esi;		//esi++
		fadd st, st(1);	//x + h				h					sum
		cmp esi, edi;	//сравниваем номер и 2n
		jle begin_loop;	//если меньше или равно, продолжаем цикл
		fstp st;		//h					sum
		fmul;			//sum* h
		fidiv c3;		//sum* h / 3
	}
}

double integral_cpp(double a, double b, int n) {
	n = 2 * n;
	double h = (b - a) / n, x = a, f;
	double result = 0;
	int k;
	for (int i = 0; i <= n; i++) {
		if (i == 0 || i == n)
		{
			k = 1;
		}
		else if (i % 2 == 0)
		{
			k = 2;
		}
		else
		{
			k = 4;
		} 
		f = 3 * x * x - x - 1;
		result += k * f;
		x += h;
		printf("%5i%14.6f%20.6f%15.1i%20.6f\n", i, x, f, k, result);
	}
	return (h * result) / 3;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Лабораторная работа №6 || Выполнила: Гижевская Валерия || Группа: 6113-020302D || Вариант 30" << endl
		<< "Вычисление определенного интеграла функции 3x^2 - x - 1 от x = 1 до 3" << endl << endl
		<< "Введите количество интервалов: ";
	int n;
	cin >> n;

	try {
		cout << endl << "Результат (ассемблер): " << integral_asm(1, 3, n) << endl << endl;
		printf("%5s%14s%20s%15.1s%20s\n", "i", "x", "f(x)", "k", "сумма");
		cout << endl << "Результат (C++): " << integral_cpp(1, 3, n) << endl;
	}
	catch (exception & e) {
		cout << "Ошибка: " << e.what() << endl;
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
