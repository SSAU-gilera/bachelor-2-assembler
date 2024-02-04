// Asm_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

void calc_asm(double x, int N)
{
	const int c2 = 2;
	const float c15 = 1.5;
	int n = 2;
	double sum = 0;
	double curr;
	bool success = false;
	__asm {
		finit;                  //инициализация сопроцессора
		fld sum;			    //sum
		fld x;					//x              sum 
		fmul st, st;			//x^2			 sum
		fld c15;			    //1.5			 x^2            sum
		fmulp st(1), st;		//1.5 * x^2		 sum		
		fst curr;
		fadd st(1), st;	        //curr           sum + curr 
	}
	do {
		double prev;
		double eps;
		double k;
		__asm
		{
			fst prev            //сохранение вершины стека в память (prev = curr)
 			mov ecx, N          //ecx = N
			fild n;				//n              curr           sum
			fild n;             //n              n              curr          sum
			fld1;				//1              n              n             curr          sum
			faddp st(1), st;	//n + 1          n              curr          sum
			fxch st(1);         //n              n + 1          curr          sum
			fld1;				//1              n              n + 1         curr          sum
			fsubp st(1), st;	//n - 1          n + 1          curr          sum
			fld x;				//x              n - 1          n + 1         curr          sum
			fmulp st(1), st;	//x * (n - 1)    n + 1          curr          sum		
			fdivrp st(1), st;	//x*(n-1)/(n+1)  curr           sum
			test n, 1;          //проверяю n на четность
			jnz if_n_nechet;    //переход на метку, если n нечетный
			fild n;             //n              x*(n-1)/(n+1)  curr          sum
			fild n;             //n              n              x*(n-1)/(n+1) curr          sum
			fld1;               //1              n              n             x*(n-1)/(n+1) curr          sum
			faddp st(1), st;    //n + 1          n              x*(n-1)/(n+1) curr          sum
			fdivp st(1), st;    //n/(n+1)        x*(n-1)/(n+1)  curr          sum
			fmulp st(1), st;    //(n/(n+1))*x*(n-1)/(n+1))	curr	sum
			jmp if_n_chet;
		if_n_nechet:            //x*(n-1)/(n+1)  curr           sum
			fild n;             //n              x*(n-1)/(n+1)  curr          sum
			fld1;               //1              n              x*(n-1)/(n+1) curr          sum
			fsubp st(1), st;    //n-1            x*(n-1)/(n+1)	curr		  sum
			fild n;             //n              n-1            x*(n-1)/(n+1) curr          sum
			fld1;               //1              n              n-1           x*(n-1)/(n+1) curr          sum
			fld1;               //1              1              n             n-1           x*(n-1)/(n+1) curr	sum
			faddp st(1), st;	//2              n				n-1           x*(n-1)/(n+1)	curr		  sum
			faddp st(1), st;    //n+2            n-1            x*(n-1)/(n+1) curr          sum
			fdivrp st(1), st;   //n+2/(n-1)      x*(n-1)/(n+1)  curr          sum
			fmulp st(1), st;    //(n+2/(n-1))*x*(n-1)/(n+1))	curr		  sum
		if_n_chet:
			fst k;
			fmulp st(1), st;	//curr * k       sum
			fst curr;
			fadd st(1), st;		//curr           sum + curr
			fxch st(1);			//sum            curr
			fst sum;			//sum            curr
			fxch st(1);			//curr           sum
			fld curr;			//curr           curr           sum
			fld prev;			//prev           curr           curr          sum
			fsubp st(1), st;	//curr - prev    curr           sum
			fabs;				//|curr - prev|  curr           sum
			fstp eps;
			inc n;				//n ++;
			mov edx, n;
			cmp ecx, edx;
			jg exit_1;
			jmp exit_2;
		exit_2:
			mov success, 1
				exit_1 :
		}
		cout << setw(3) << (n - 1) << "   " << setw(3) << (n - 1) << "   " << setw(12) << setprecision(6) << prev << "   " << setw(12) << setprecision(6) << curr << "   " << setw(5) << setprecision(6) << k << "   " << setw(7) << setprecision(6) << eps << "   " << fixed << setw(12) << setprecision(6) << sum << "   " << endl;
	} while (!success);
	cout << endl << "Ответ: " << setprecision(6) << sum << endl;
}

void check(double x, int N) {
	double eps;
	double curr;
	curr = 1.5 * pow(x,2);
	double sum = curr;
	double prev;
	double k;
	double n = 2;
	do {
		prev = curr;
		k = (x * ((n - 1) / (n + 1))) * ((n + 1 + pow(-1, n + 1)) / (n + pow(-1, n)));
		curr = prev * k;
		eps = abs(curr - prev);
		sum = sum + curr;
		n++;
		cout << setw(3) << (int)(n - 1) << "   " << setw(3) << (int)(n - 1) << "   " << setw(12) << setprecision(6) << prev << "   " << setw(12)
			<< setprecision(6) << curr << "   " << setw(5) << setprecision(6) << k << "   " << setw(7) << setprecision(6) << eps << "   "
			<< fixed << setw(12) << setprecision(6) << sum << "   " << endl;
	} while ((n + 1) <= N);
	cout << endl << "Ответ: " << setprecision(6) << sum << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Лабораторная работа №7 || Выполнила: Гижевская Валерия || Группа: 6113-020302D || Вариант 30 " << endl << endl;
	cout << "Задание: вычислить сумму ряда ((n + (-1)^n)/(n * (n - 1))) * x ^ n по n от 2 до бесконечности" << endl << endl;
	double x;
	int N;

	cout << "Введите x: ";
	cin >> x;

	do
	{
		cout << "Введите N: ";
		cin >> N;
		if (N < 0)
		{
			cout << "N не может быть отрицательным. Повторите ввод." << endl;
		}

	} while (N < 0);
	N++;
	cout << endl << "Результат(ассемблер)" << endl;

	cout << setw(3) << "№" << "   " << setw(3) << "n" << "   " << setw(12) << setprecision(6) << "Sn" << "   "
		<< setw(12) << setprecision(6) << "Sn+1" << "   " << setw(8) << setprecision(6) << "k" << "   " << setw(8) << setprecision(6) << "eps" << "   "
		<< fixed << setw(12) << setprecision(6) << "Сумма" << "   " << endl;

	calc_asm(x, N);

	cout << endl << "Проверка(С++" << endl;

	cout << setw(3) << "№" << "   " << setw(3) << "n" << "   " << setw(12) << setprecision(6) << "Sn" << "   "
		<< setw(12) << setprecision(6) << "Sn+1" << "   " << setw(8) << setprecision(6) << "k" << "   " << setw(8) << setprecision(6) << "eps" << "   "
		<< fixed << setw(12) << setprecision(6) << "Сумма" << "   " << endl;

	check(x, N);

	cout << endl;
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
