//#include "pch.h"
#include <iostream>
#include <math.h>


using namespace std;

double func(double a, double b)
{
	double res;
	const int c2 = 2;
	const int c5 = 5;
	const int c3 = 3;

	__asm
	{
		//							    st0        st1        st2        st3        st4
		finit                       // инициализация сопроцессора
		fld qword ptr[a]            //   a
		fld qword ptr[b]            //   b          a
		fcomi st, st(1)             // сравнение a и b
		jb a_bigger                 // a > b
		ja b_bigger                 // a < b
		fadd      				    // a + b
		fld st				        // a + b     a + b
		fmul st, st			    // (a + b)^2 a + b 
		fmul					    // (a + b)^3
		fild c2						//   2      (a + b)^3
		fsqrt						// sqrt2    (a + b)^3
		fmul						// sqrt2*(a + b)^3
		jmp end_
		a_bigger :
		fxch st(1)					//   a		   b
			fldl2e					// log2e       a         b
			fmul					// a*log2e     b
			fld st					// a*log2e   a*log2e     b
			frndint 				// [a*log2e] a*log2e     b
			fsub st(1), st			// [a*log2e] {a*log2e}   b
			fxch st(1)				// {a*log2e} [a*log2e]   b
			f2xm1					// 2^({a*log2e})-1 [a*log2e] b
			fld1					//   1  2^({a*log2e})-1 [a*log2e] b
			faddp st(1), st			// 2^({a*log2e}) [a*log2e] b
			fscale					//  e^a    [a*log2e]     b
			fstp st(1)				//  e^a        b
			fild c3					//   3         e^a       b 
			fsubp st(1), st 		// e^a-3	   b
			fxch st(1)				//   b       e^a-3
			fldl2e					// log2e       b       e^a-3
			fmul					// b*log2e     e^a-3
			fld st					// b*log2e   b*log2e     e^a-3
			frndint 				// [b*log2e] b*log2e     e^a-3
			fsub st(1), st			// [b*log2e] {b*log2e}   e^a-3
			fxch st(1)				// {b*log2e} [b*log2e]   e^a-3
			f2xm1					// 2^({b*log2e})-1 [b*log2e] e^a-3
			fld1					//   1  2^({b*log2e})-1 [b*log2e] e^a-3
			faddp st(1), st			// 2^({b*log2e}) [b*log2e] e^a-3
			fscale					//  e^b    [b*log2e]     e^a-3
			fstp st(1)				//  e^b       e^a-3
			fimul c2				// 2*e^b      e^a-3
			fild c5					//   5        2*e^b      e^a-3
			faddp st(1), st			// 2*e^b+5    e^a-3
			fxch st(1)				// e^a-3     2*e^b+5
			fdiv					// (2*e^b+5)/(e^a-3)
			jmp end_
			b_bigger :
		fxch st(1)					//   a         b
			fstp st(1)				//   a
			fld st					//   a         a       
			fldl2t  				// log2(10)    a         a
			fmul 					// a*log2(10)     b
			fld st					// a*log2(10)   a*log2(10)     a
			frndint 				// [a*log2(10)] a*log2(10)     a
			fsub st(1), st			// [a*log2(10)] {a*log2(10)}   a
			fxch st(1)				// {a*log2(10)} [a*log2(10)]   a
			f2xm1					// 2^({a*log2(10)})-1 [a*log2(10)] a
			fld1					//   1  2^({a*log2(10)})-1 [a*log2(10)] a
			faddp st(1), st			// 2^({a*log2(10)}) [a*log2(10)] a
			fscale					//  10^a    [a*log2(10)]     a
			fstp st(1)				//  10^a        a
			fxch st(1)				//    a        10^a
			fild c5					//    5         a        10^a
			fsub					//   a-5       10^a
			fsqrt					// sqrt(a-5)   10^a
			fadd					// sqrt(a-5) + 10^a
			jmp end_
			end_ :
		fstp res
	}
	return res;
}

double Check(double a, double b)
{
	double y;
	if (a == b) {
		y = (sqrt(2)) * (pow(a + b, 3));
	}
	else if (a > b) {
		y = (2 * exp(b) + 5) / (exp(a) - 3);
	}
	else {
		y = sqrt(a - 5) + pow(10, a);
	}
	return y;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	bool m = true;
	while (m)
	{
		cout.setf(ios::fixed);
		cout << " Гижевская Лера \n Группа 6113 \n Лабораторная работа №4 \n Вариант 52" << endl;
		cout << " Задание:\n" << endl;
		cout << "     |sqrt(5a-ln(b+1)), если a > b " << endl;
		cout << " x = {(2*e^b+5)/(e^a-3),если a = b  " << endl;
		cout << "     |sqrt(a-5) + 10^a, если a < b  " << endl;
		cout << endl;
		cout << " a = ";
		cin >> a;
		cout << " b = ";
		cin >> b;
		double assembler = func(a, b);
		double prov = Check(a, b);
		cout << " Результат : x = " << assembler << endl;
		cout << " Проверка C++ : x = " << prov << endl;
		system("PAUSE");
		system("cls");
	}

	return 0;
}