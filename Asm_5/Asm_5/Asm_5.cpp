// Asm_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

double f(double a, double b, double eps)
{

	const int c5 = 5;
	const int c30 = 30;
	const int c39 = 39;
	const int c29 = 29;
	const int c47 = 47;
	const int c25 = 25;

	const int c78 = 78;
	const int c117 = 117;
	const int c116 = 116;
	const int c235 = 235;
	const int c225 = 225;
	const int c10 = 10;

	int error = 0;
	__asm {
		//					   st(0)						st(1)						st(2)						st(3)				st(4)
		finit;				 //инициализация сопроцессора
		fld a;				 //a
	begin_loop:
		//вычисление f(x)
		fld st;				 //x							x                             
			fmul st, st;	 //x ^ 2						x                                                                     
			fmul st, st;	 //x ^ 4						x 								                                       
			fmul st, st;	 //x ^ 8						x 							     	                                  
			fmul st, st(1);	 //x ^ 9						x                                   
			fmul st, st(1);	 //x ^ 10						x
			fld st(1);		 //x							x ^ 10                      x
			fmul st, st;	 //x ^ 2						x ^ 10                      x
			fmul st, st;	 //x ^ 4						x ^ 10                      x
			fmul st, st;	 //x ^ 8						x ^ 10                      x
			fld st(2);	   	 //x							x ^ 8						x ^ 10                      x
			fmulp st(1), st; //x ^ 9						x ^ 10                      x
			fild c25;		 //25							x ^ 9						x ^ 10                      x
			fmulp st(1), st; //25x ^ 9						x ^ 10                      x
			faddp st(1), st; //x ^ 10 + 25x ^ 9             x
			fld st(1);		 //x							x ^ 10 + 25x ^ 9            x
			fmul st, st;	 //x ^ 2						x ^ 10 + 25x ^ 9            x
			fmul st, st;	 //x ^ 4						x ^ 10 + 25x ^ 9            x
			fld st(2);		 //x							x ^ 4						x ^ 10 + 25x ^ 9            x
			fmulp st(1), st; //x ^ 5						x ^ 10 + 25x ^ 9            x
			fild c47;		 //47							x ^ 5						x ^ 10 + 25x ^ 9            x
			fmulp st(1), st; //47x ^ 5						x ^ 10 + 25x ^ 9            x
			fsubp st(1), st; //x ^ 10 + 25x ^ 9 - 47x ^ 5   x
			fld st(1);		 //x							x ^ 10 + 25x ^ 9 - 47x ^ 5  x			
			fmul st, st;	 //x ^ 2						x ^ 10 + 25x ^ 9 - 47x ^ 5	x
			fmul st, st;	 //x ^ 4						x ^ 10 + 25x ^ 9 - 47x ^ 5	x
			fild c29;		 //29							x ^ 4						x ^ 10 + 25x ^ 9 - 47x ^ 5	x
			fmulp st(1), st; //29x ^ 4						x ^ 10 + 25x ^ 9 - 47x ^ 5	x
			fsubp st(1), st; //x ^ 10 - ... - 29x ^ 4		x
			fld st(1);		 //x							x ^ 10 - ... - 29x ^ 4		x
			fmul st, st;	 //x ^ 2						x ^ 10 - ... - 29x ^ 4		x
			fld st(2);		 //x							x ^ 2						x ^ 10 - ... - 29x ^ 4		x
			fmulp st(1), st; //x ^ 3						x ^ 10 - ... - 29x ^ 4		x
			fild c39;		 //39							x ^ 3						x ^ 10 - ... - 29x ^ 4		x
			fmulp st(1), st; //39x ^ 3						x ^ 10 - ... - 29x ^ 4		x
			fsubp st(1), st; //x ^ 10 - ... - 39x ^ 3		x
			fld st(1);		 //x							x ^ 10 - ... - 39x ^ 3		x
			fmul st, st;	 //x ^ 2						x ^ 10 - ... - 39x ^ 3		x
			fild c39;		 //39							x ^ 2						x ^ 10 - ... - 39x ^ 3		x
			fmulp st(1), st; //39x ^ 2						x ^ 10 - ... - 39x ^ 3		x
			faddp st(1), st; //x ^ 10 - ... + 39x ^ 2		x
			fld st(1);		 //x							x ^ 10 - ... + 39x ^ 2		x
			fild c30;		 //30							x							x ^ 10 - ... + 39x ^ 2		x
			fmulp st(1), st; //30x							x ^ 10 - ... + 39x ^ 2		x
			faddp st(1), st; //x ^ 10 - ... + 30x			x
			fild c5;		 //5							x ^ 10 - ... + 30x			x				
			fsubp st(1), st; //x ^ 10 - ... - 5				x				
			//вычисление f'(x)
			fld st(1);		 //x							x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 2					    x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 4						x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 8						x ^ 10 - ... - 5			x
			fmul st, st(2);	 //x ^ 9						x ^ 10 - ... - 5			x
			fild c10;		 //10							x ^ 9						x ^ 10 - ... - 5			x
			fmulp st(1), st; //10x ^ 9						x ^ 10 - ... - 5			x
			fld st(2);		 //x							10x ^ 9						x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 2						10x ^ 9						x ^ 10 - ... - 5			x
			fmul st, st;     //x ^ 4	     		        10x ^ 9						x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 8                        10x ^ 9						x ^ 10 - ... - 5	    	x
			fild c225;		 //225							x ^ 8						10x ^ 9						x ^ 10 - ... - 5	x
			fmulp st(1), st; //225x ^ 8						10x ^ 9						x ^ 10 - ... - 5			x
			faddp st(1), st; //10x ^ 9 + 225x ^ 8  			x ^ 10 - ... - 5  			x

			fld st(2);		 //x							10x ^ 9 + 225x ^ 8			x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 2						10x ^ 9 + 225x ^ 8			x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 4						10x ^ 9 + 225x ^ 8			x ^ 10 - ... - 5			x
			fild c235;		 //235							x ^ 4						10x ^ 9 + 225x ^ 8			x ^ 10 - ... - 5	x
			fmulp st(1), st; //235x ^ 4						10x ^ 9 + 225x ^ 8			x ^ 10 - ... - 5			x
			fsubp st(1), st; //10x ^ 9 - ... - 235x ^ 4		x ^ 10 - ... - 5			x

			fld st(2);		 //x							10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5			x
			fld st;          //x                            x						    10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5	x
			fmul st, st;	 //x ^ 2						x                           10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5	x
			fmulp st(1), st; //x ^ 3                        10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5			x
			fild c116;		 //116							x ^ 3						10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5	x
			fmulp st(1), st; //116x ^ 3						10x ^ 9 - ... - 235x ^ 4	x ^ 10 - ... - 5			x
			fsubp st(1), st; //10x ^ 9 - ... - 116x ^ 3		x ^ 10 - ... - 5			x
			 
			fld st(2);		 //x							10x ^ 9 - ... - 116x ^ 3	x ^ 10 - ... - 5			x
			fmul st, st;	 //x ^ 2						10x ^ 9 - ... - 116x ^ 3	x ^ 10 - ... - 5			x
			fild c117;		 //117							x ^ 2						10x ^ 9 - ... - 116x ^ 3	x ^ 10 - ... - 5	x
			fmulp st(1), st; //117x ^ 2						10x ^ 9 - ... - 116x ^ 3	x ^ 10 - ... - 5			x
			fsubp st(1), st; //10x ^ 9 - ... - 117x ^ 2		x ^ 10 - ... - 5			x

			fld st(2);		 //x							10x ^ 9 - ... - 117x ^ 2	x ^ 10 - ... - 5			x
			fild c78;		 //78							x							10x ^ 9 - ... - 117x ^ 2	x ^ 10 - ... - 5	x
			fmulp st(1), st; //78x							10x ^ 9 - ... - 117x ^ 2	x ^ 10 - ... - 5			x
			faddp st(1), st; //10x ^ 9 - ... + 78x 			x ^ 10 - ... - 5			x

			fild c30;		 //30							110x ^ 9 - ... + 78x		x ^ 10 - ... - 5			x
			faddp st(1), st; //10x ^ 9 - ... + 30	 		x ^ 10 - ... - 5			x
			//вычисление f(x) / f'(x)
			fdivp st(1), st; //f(x) / f'(x)					x
			fsub st(1), st;	 //f(x) / f'(x)					x - f(x) / f'(x)
			fabs;			 //| f(x) / f'(x)|				x - f(x) / f'(x)
			fld eps;		 //eps | f(x) / f'(x)|			x - f(x) / f'(x)
			fcomip st, st(1);//сравниваем eps и | f(x) / f'(x)| с выталкиванием и установкой флагов
			fxch st(1);		 //x - f(x) / f'(x)				|f(x) / f'(x) |
			fstp st(1);		 //x - f(x) / f'(x)				копирование значения из st в st(1) с выталкиванием
			ja exit_p;		 //переход к выходу из программы, если | f(x) / f'(x)| < eps
			fld b;			 //b							x - f(x) / f'(x)
			fld a;			 //a							b							x - f(x) / f'(x)			
			main_p:
		fcomip st, st(2);	 //сравнение x - f(x) / f'(x) с минимальной границей 
			ja err;			 //переход к метке error, если min{ a, b } > x - f(x) / f'(x)
			fcomip st, st(1);//сравнение x - f(x) / f'(x) с максимальной границей
			jb err;			 //переход к метке error, если max{ a, b } < x - f(x) / f'(x)
			jmp begin_loop;	 //переход к метке begin_loop;
	err:
		mov error, 1
			exit_p :
	}
	if (error == 1)
	{
		throw exception("\nНа заданном промежутке корень не найден.");
	}
}
double calc(double a, double b, double eps)
{
	double f, d, res = 1;
	double x = a;
	for (int i = 1; abs(res) > eps; i++)
	{
		f = pow(x, 10) + 25 * pow(x, 9) - 47 * pow(x, 5) - 29 * pow(x, 4) - 39 * pow(x, 3) + 39 * pow(x, 2) + 30 * x - 5;
		d = 10 * pow(x, 9) + 225 * pow(x, 8) - 235 * pow(x, 4) - 116 * pow(x, 3) - 117 * pow(x, 2) + 78 * x + 30;
		res = f / d;
		printf("%2d%12.5f%20.4f%20.4f%15.10f\n", i, x, f, d, abs(res));
		x -= res;
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Лабораторная работа №5\nВыполнила: Гижевская Валерия\nГруппа: 6113, вариант 52\n";
	cout << "\nЗадание:      f(x) = x^10 + 25x^9 - 47x^5 - 29x^4 - 39x^3 + 39x^2 +30x - 5" << endl;
	cout << "                f'(x) = 10x^9 + 225x^8 - 235x^4 - 116x^3 - 117x^2 + 78x + 30\n" << endl;
	cout << "Введите границы промежутка:\n";
	double a, b, eps;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << endl;
	cout << "Введите погрешность: ";
	cin >> eps;
	try
	{
		cout << "\nРезультат на ассемблере: " << f(a, b, eps) << endl << endl;
		cout << "Таблица расчётов корня на промежутке[a, b] уравнения" << endl;
		printf("%2s%12s%20s%20s%15s\n", "№", "x", "f(x)", "f'(x)", "Погрешность");
		calc(a, b, eps);
		cout << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl << endl;
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
