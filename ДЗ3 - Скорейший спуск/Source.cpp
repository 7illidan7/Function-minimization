#include <iostream>
#include <Windows.h>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

void TableOpen(int flag);
void TableOutput2(int flag, int k, double x1, double x2, double Fdx1, double Fdx2, double F);
void TableOutput3(int flag, int k, double x1, double x2, double x3, double Fdx1, double Fdx2, double Fdx3, double F);
void TableClose(int flag);

double FCalc(int NumF, double x1, double x2, double x3);

int main()
{
	int NumF = 0;
	int n;
	double Eps;
	double x1, x2, x3;
	x1 = -7;
	x2 = 5;
	x3 = 1.5;

	cout << " Type number of choosen function:\n";
	cout << endl;
	cout << " 1) f(x1,x2) = (x1)^2 + (x2)^2 - 2 * x1 - 4 * x2 + 5\n";
	cout << " 2) f(x1,x2) = 2 * (x1)^2 - 2 * x1 * x2 + x2^2 + 2 * x1 - 2 * x2\n";
	cout << " 3) f(x1, x2, x3) = x1^2 + 2 * x2^2 + x3^2 - 2 * x1 * x2 - x1 + 2 * x3\n";
	cout << " 4) f(x1, x2, x3) = x1^2 + x2^2 + x3^2 - x1 * x2 + x1 - 2 * x3\n";
	cout << " 5) f(x1, x2, x3) = \n";
	cout << " 6) f(x1, x2) = x1^2 + x2^2 -0.2 * x1 * x2 - 2.2 * x1 + 2.2 * x2 + 2.2\n";
	cout << " 7) f(x1, x2) = 5 * x1^2 + 4.075 * x2^2 - 9 * x1 * x2 + x1 + 2\n";
	cout << " 8) f(X) = \n";
	cout << endl;

	cin >> NumF;
	switch (NumF)
	{
	case(1):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2) = (x1) ^ 2 + (x2) ^ 2 - 2 * x1 - 4 * x2 + 5\033[0m\t\t\n";
		break;
	case(2):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2) = 2 * (x1)^2 - 2 * x1 * x2 + x2^2 + 2 * x1 - 2 * x2\033[0m\t\t\n";
		break;
	case(3):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2, x3) = x1^2 + 2 * x2^2 + x3^2 - 2 * x1 * x2 - x1 + 2 * x3\033[0m\t\t\n";
		break;
	case(4):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2, x3) = x1^2 + x2^2 + x3^2 - x1 * x2 + x1 - 2 * x3\033[0m\t\t\n";
		break;
	case(5):
		cout << "\n" << "I have no idea how minimize this function\n";
		return 5;
	case(6):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2) = x1^2 + x2^2 -0.2 * x1 * x2 - 2.2 * x1 + 2.2 * x2 + 2.2\033[0m\t\t\n";
		break;
	case(7):
		cout << "\n" << "Function:\n" << "\x1B[31mf(x1, x2) = 5 * x1^2 + 4.075 * x2^2 - 9 * x1 * x2 + x1 + 2\033[0m\t\t\n";
		break;
	case(8):
		cout << "\n" << "I have no idea how minimize this function\n";
		return 8;
	};

	cout << "\n" << "Epsilon = 1 * 10 ^ (-n). Type 'n':\n";
	cin >> n;
	Eps = 1 * pow(10, -n);
	cout << "\x1B[33mEps = \033[0m" << setprecision(10) << fixed << Eps << endl;

	if ((NumF == 1) || (NumF == 2) || (NumF == 6) || (NumF == 7))
	{
		int flag = 2;
		double F, Fdx1, Fdx2;
		double x1new, x2new;
		double h1 = 0.1;
		double h2 = 0.1;
		int k = 1;

		F = FCalc(NumF, x1, x2, x3);

		if (NumF == 1)//Gradients
		{
			Fdx1 = 2 * x1 - 2;
			Fdx2 = 2 * x2 - 4;
		}
		if (NumF == 2)
		{
			Fdx1 = 4 * x1 - 2 * x2 + 2;
			Fdx2 = -2 * x1 + 2 * x2 - 2;
		}
		if (NumF == 6)
		{
			Fdx1 = 2 * x1 - 0.2 * x2 - 2.2;
			Fdx2 = 2 * x2 - 0.2 * x1 + 2.2;
		}
		if (NumF == 7)
		{
			Fdx1 = 10 * x1 - 9 * x2 + 1;
			Fdx2 = 8.15 * x2 - 9 * x1;
		}

		int i;
		TableOpen(flag);
		TableOutput2(flag, k, x1, x2, Fdx1, Fdx2, F);

		x1new = x1 - 10 * Eps;
		x2new = x2 - 10 * Eps;

		while ((abs(x1 - x1new) > Eps) && (abs(x2 - x2new) > Eps))
		{
			x1new = x1;
			x2new = x2;
			h1 = 0.001 * abs(Fdx1);
			h2 = 0.001 * abs(Fdx2);
			x1 = x1 - h1 * Fdx1;
			x2 = x2 - h2 * Fdx2;
			if (NumF == 1)//Gradients
			{
				Fdx1 = 2 * x1 - 2;
				Fdx2 = 2 * x2 - 4;
			}
			if (NumF == 2)
			{
				Fdx1 = 4 * x1 - 2 * x2 + 2;
				Fdx2 = -2 * x1 + 2 * x2 - 2;
			}
			if (NumF == 6)
			{
				Fdx1 = 2 * x1 - 0.2 * x2 - 2.2;
				Fdx2 = 2 * x2 - 0.2 * x1 + 2.2;
			}
			if (NumF == 7)
			{
				Fdx1 = 10 * x1 - 9 * x2 + 1;
				Fdx2 = 8.15 * x2 - 9 * x1;
			}
			F = FCalc(NumF, x1, x2, x3);
			k++;
			TableOutput2(flag, k, x1, x2, Fdx1, Fdx2, F);
		}
		TableClose(flag);
		cout << endl;
		cout << "Minimum:  " << " M(" << x1 << "; " << x2 << ") " << "   F = " << F << "\n";
	}

	if ((NumF == 3) || (NumF == 4))
	{
		int flag = 3;
		double F, Fdx1, Fdx2, Fdx3;
		double x1new, x2new, x3new;
		double h1 = 0.1;
		double h2 = 0.1;
		double h3 = 0.1;
		int k = 1;

		F = FCalc(NumF, x1, x2, x3);

		if (NumF == 3)
		{
			Fdx1 = 2 * x1 - 2 * x2 - 1;
			Fdx2 = 4 * x2 - 2 * x1;
			Fdx3 = 2 * x3 + 2;
		}
		if (NumF == 4)
		{
			Fdx1 = 2 * x1 - x2 + 1;
			Fdx2 = 2 * x2 - x1;
			Fdx3 = 2 * x3 - 2;
		}

		int i;
		TableOpen(flag);
		TableOutput3(flag, k, x1, x2, x3, Fdx1, Fdx2, Fdx3, F);

		x1new = x1 - 10 * Eps;
		x2new = x2 - 10 * Eps;
		x3new = x3 - 10 * Eps;

		while ((abs(x1 - x1new) > Eps) && (abs(x2 - x2new) > Eps) && (abs(x3 - x3new) > Eps))
		{
			x1new = x1;
			x2new = x2;
			x3new = x3;
			h1 = 0.01 * abs(Fdx1);
			h2 = 0.01 * abs(Fdx2);
			h3 = 0.01 * abs(Fdx3);
			x1 = x1 - h1 * Fdx1;
			x2 = x2 - h2 * Fdx2;
			x3 = x3 - h3 * Fdx3;
			if (NumF == 3)
			{
				Fdx1 = 2 * x1 - 2 * x2 - 1;
				Fdx2 = 4 * x2 - 2 * x1;
				Fdx3 = 2 * x3 + 2;
			}
			if (NumF == 4)
			{
				Fdx1 = 2 * x1 - x2 + 1;
				Fdx2 = 2 * x2 - x1;
				Fdx3 = 2 * x3 - 2;
			}
			F = FCalc(NumF, x1, x2, x3);
			k++;
			TableOutput3(flag, k, x1, x2, x3, Fdx1, Fdx2, Fdx3, F);
		}
		TableClose(flag);
		cout << endl;
		cout << "Minimum:  " << " M(" << x1 << "; " << x2 << "; " << x3 << ") " << "   F = " << F << "\n";
	}
	return 0;
}

double FCalc(int NumF, double x1, double x2, double x3)
{
	switch (NumF)
	{
	case(1):
		return pow(x1, 2) + pow(x2, 2) - 2 * x1 - 4 * x2 + 5;
		break;
	case(2):
		return 2 * pow(x1, 2) - 2 * x1 * x2 + pow(x2, 2) + 2 * x1 - 2 * x2;
		break;
	case(3):
		return pow(x1, 2) + 2 * pow(x2, 2) + pow(x3, 2) - 2 * x1 * x2 - x1 + 2 * x3;
		break;
	case(4):
		return pow(x1, 2) + pow(x2, 2) + pow(x3, 2) - x1 * x2 + x1 - 2 * x3;
		break;
	case(6):
		return pow(x1, 2) + pow(x2, 2) - 0.2 * x1 * x2 - 2.2 * x1 + 2.2 * x2 + 2.2;
		break;
	case(7):
		return 5 * pow(x1, 2) + 4.075 * pow(x2, 2) - 9 * x1 * x2 + x1 + 2;
		break;
	};
}

void TableOpen(int flag)
{
	int i;
	int j;
	switch (flag)
	{
	case(2):
		//-------------------------КРЫШКА ТАБЛИЦЫ С 2 ПЕРЕМЕННЫМИ
		//------------------------------------------------------верхняя крышка таблицы
		cout << char(218);
		for (i = 0; i < 5; i++)
			cout << char(196); cout << char(194);
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196); cout << char(194);
		}
		for (i = 0; i < 15; i++)
			cout << char(196); cout << char(191) << endl;
		//--------------------------------------------------------------------шапка таблицы
		cout << char(179) << setw(5) << "K"
			<< char(179) << setw(10) << "x1"
			<< char(179) << setw(10) << "x2"
			<< char(179) << setw(10) << "dF/dx1"
			<< char(179) << setw(10) << "dF/dx2"
			<< char(179) << setw(15) << "F" << char(179) << endl;
		cout << char(195);

		for (i = 0; i < 5; i++)
			cout << char(196); cout << char(197);
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196); cout << char(197);
		}
		for (i = 0; i < 15; i++)
			cout << char(196); cout << char(180) << endl;
		break;
	case(3):
		//-------------------------КРЫШКА ТАБЛИЦЫ С 3 ПЕРЕМЕННЫМИ
		//------------------------------------------------------верхняя крышка таблицы
		cout << char(218);
		for (i = 0; i < 5; i++)
			cout << char(196); cout << char(194);
		for (j = 0; j < 6; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196); cout << char(194);
		}
		for (i = 0; i < 15; i++)
			cout << char(196); cout << char(191) << endl;
		//--------------------------------------------------------------------шапка таблицы
		cout << char(179) << setw(5) << "K"
			<< char(179) << setw(10) << "x1"
			<< char(179) << setw(10) << "x2"
			<< char(179) << setw(10) << "x3"
			<< char(179) << setw(10) << "dF/dx1"
			<< char(179) << setw(10) << "dF/dx2"
			<< char(179) << setw(10) << "dF/dx3"
			<< char(179) << setw(15) << "F" << char(179) << endl;
		cout << char(195);

		for (i = 0; i < 5; i++)
			cout << char(196); cout << char(197);
		for (j = 0; j < 6; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196); cout << char(197);
		}
		for (i = 0; i < 15; i++)
			cout << char(196); cout << char(180) << endl;
		break;
	};
}

void TableOutput2(int flag, int k, double x1, double x2, double Fdx1, double Fdx2, double F)
{
	//------------------------------------------вывод 2 переменные
	cout << char(179) << setw(5) << k;
	cout << char(179) << setw(10) << setprecision(4) << x1
		<< char(179) << setw(10) << setprecision(4) << x2;
	cout << char(179) << setw(10) << setprecision(4) << Fdx1
		<< char(179) << setw(10) << setprecision(4) << Fdx2
		<< char(179) << setw(15) << setprecision(10) << fixed << F
		<< char(179) << endl;
	cout << char(179) << setw(6);
	cout << char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(16) << setprecision(10)
		<< char(179) << endl;
}

void TableOutput3(int flag, int k, double x1, double x2, double x3, double Fdx1, double Fdx2, double Fdx3, double F)
{
	//------------------------------------------вывод 3 переменные
	cout << char(179) << setw(5) << k;
	cout << char(179) << setw(10) << setprecision(4) << x1
		<< char(179) << setw(10) << setprecision(4) << x2
		<< char(179) << setw(10) << setprecision(4) << x3
		<< char(179) << setw(10) << setprecision(4) << Fdx1
		<< char(179) << setw(10) << setprecision(4) << Fdx2
		<< char(179) << setw(10) << setprecision(4) << Fdx3
		<< char(179) << setw(15) << setprecision(10) << fixed << F
		<< char(179) << endl;
	cout << char(179) << setw(6);
	cout << char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(11) << setprecision(4)
		<< char(179) << setw(16) << setprecision(10)
		<< char(179) << endl;
}

void TableClose(int flag)
{
	int i;
	int j;
	switch (flag)
	{
	case(2):
		//----------------------------------------------крышка 2 переменные
		cout << char(192);
		for (i = 0; i < 5; i++)
			cout << char(196);
		cout << char(193);
		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196);
			cout << char(193);
		}
		for (i = 0; i < 15; i++)
			cout << char(196);
		cout << char(217);
		cout << endl;
		break;
	case(3):
		//----------------------------------------------крышка 3 переменные
		cout << char(192);
		for (i = 0; i < 5; i++)
			cout << char(196);
		cout << char(193);
		for (j = 0; j < 6; j++)
		{
			for (i = 0; i < 10; i++)
				cout << char(196);
			cout << char(193);
		}
		for (i = 0; i < 15; i++)
			cout << char(196);
		cout << char(217);
		cout << endl;
		break;
	}
}