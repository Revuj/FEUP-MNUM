#include <iostream>
#include <cmath>
#include <iomanip>

//Funcao para calculo do minimo
//double f(double x, double y) {
//	return y * y - 2 * x * y - 6 * y + 2 * x * x + 12;
//}
//
//double dfdx(double x, double y) {
//	return -2 * y + 4 * x;
//}
//
//double dfdy(double x, double y) {
//	return 2 * y - 2 * x - 6;
//}

//Funcao para calculo do maximo
double f(double x, double y) {
	return 2 * x * y + 2 * x - x * x - 2 * y * y;
}

double dfdx(double x, double y) {
	return 2 * y + 2 - 2 * x;
}

double dfdy(double x, double y) {
	return 2 * x - 4 * y;
}

void maximo(double x0, double y0, double h) {

	double x1 = x0 + h * dfdx(x0, y0);
	double y1 = y0 + h * dfdy(x0, y0);

	while (abs(x1 - x0) > pow(10, -3) || abs(y1 - y0) > pow(10, -3)) {
		std::cout << "loop" << std::endl;
		if (f(x1, y1) > f(x0, y0))
			h *= 2;
		else  if (f(x1, y1) < f(x0, y0))
			h *= 0.5;


		x0 = x1;
		y0 = y1;

		x1 = x0 + h * dfdx(x0, y0);
		y1 = y0 + h * dfdy(x0, y0);

	}
	std::cout << "Maximo:" << std::setprecision(5) << std::fixed << "( " << x1 << ", " << y1 << ", " << f(x1, y1) << ")" << std::endl;
}

void minimo(double x0, double y0, double h) {
	
	double x1 = x0 - h * dfdx(x0, y0);
	double y1 = y0 - h * dfdy(x0, y0);

	while (abs(x1 - x0) > pow(10, -3) || abs(y1 - y0) > pow(10, -3)) {

		if (f(x1, y1) < f(x0, y0))
			h *= 2;
		else  if (f(x1, y1) > f(x0, y0))
			h *= 0.5;

		x0 = x1;
		y0 = y1;

		x1 = x0 - h * dfdx(x0, y0);
		y1 = y0 - h * dfdy(x0, y0);

	}
	std::cout << "Minimo:" << std::setprecision(5) << std::fixed << "( " << x1 << ", " << y1 << ", " << f(x1, y1) << ")" << std::endl;
}

int main() {
	//valores iniciais para o minimo
	//double x0 = 1;
	//double y0 = 1;
	//double h0 = 1;

	//valores iniciais para o maximo
	double x0 = -1;
	double y0 = 1;
	double h0 = 1;

//	minimo(x0, y0, h0);
	maximo(x0, y0, h0);
}