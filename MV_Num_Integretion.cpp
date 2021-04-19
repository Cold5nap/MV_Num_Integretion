#include <iostream>
#include <conio.h>
#include <math.h> // добавляем математические функции
using namespace std;

int kol_obr;

double perv(double x)
{
	return (1. / 4) * ((x * x * x * x - 1) * log(x * x + 1)) - (1. / 4) * (((x * x * x * x) / 2) + x * x);
}

double gauss(double a, double b, double eps)
{
	int n = 1, k = 1;;
	double h, x, s = 0, INT1, INT2 = 1, INT;
	do
	{
		INT1 = INT2;
		k += 2;
		h = (b - a) / k;//шаг интегрирования
		x = a + 0.5 * h;
		for (int j = 2; j < k; j++)
			s += (x * x * x) * log(x * x + 1);
		INT2 = h * s;
	} while (abs(INT2 - INT1) > eps);
	return INT2;
}

double y(double x)
{
	kol_obr++;
	return (x * x * x) * log(x * x + 1);
}

double f(double x)
{
	return 16 * x / (pow(x, 8) + 1);
}

double eps1( double a, double b, double h) {
	double derivative = 128 * pow(b, 7) * (16 * pow(b, 8) / (pow(b, 8) + 1) - 9) / ((pow(b, 8) + 1) * (pow(b, 8) + 1));
	double eps = derivative / 24 * (b - a) * h*h;
	return eps;
}

double eps2(double a, double b, double h) {
	double derivative = 128 * pow(b, 7) * (16 * pow(b, 8) / (pow(b, 8) + 1) - 9) / ((pow(b, 8) + 1) * (pow(b, 8) + 1));
	double eps = derivative / 12 * (b - a) * h * h;
	return eps;
}

double eps3(double a, double b, double h) {
	double derivative = 768 * pow(b, 5) * (-63 - 2944 * pow(b, 16) / pow((1 + pow(b, 8)) , 2) + 1064 * pow(b, 8) / (1 + pow(b,8)) + 2048 * pow(b, 24) / pow(1 + pow(b,8) , 3)) / pow((1 + pow(b, 8)) ,2);
	double eps = (b - a) *pow(h,4)* derivative/2880;
	return eps;
}

int main()
{
	//метод гаусса
	double a = 0, b = 1, eps, prib_gauss, prv, perv;
	eps = 0.01;
	cout << "Gaus" << gauss(a, b, eps) << endl;

	system("pause");
}