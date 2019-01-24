#include <iostream>
#include <cmath>
#include <iomanip>

static const double B = (sqrt(5) - 1) / 2;
static const double A = B * B;

double f(double x) {
	return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

void maximo(double x1, double x2) {

	double x3, x4;

	while (abs(x2 - x1) > pow(10, -3)) {

		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		if (f(x3) > f(x4))
			x2 = x4;
		else if (f(x3) < f(x4))
			x1 = x3;
	}

	if (f(x1) > f(x2))
		std::cout << "Maximo: "  << std::setprecision(4) << std::fixed << "(" << f(x1) << ", " << x1 << ")" << std::endl;
	else
		std::cout << "Maximo: " << std::setprecision(4) << std::fixed << "(" << f(x2) << ", " << x2 << ")" << std::endl;
}

void minimo(double x1, double x2) {

	double x3, x4;

	while (abs(x2 - x1) > pow(10, -3)) {

		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);

		if (f(x3) < f(x4))
			x2 = x4;
		else if (f(x3) > f(x4))
			x1 = x3;
	}

	if (f(x1) < f(x2))
		std::cout << "Minimo: " << std::setprecision(4) << std::fixed << "(" << f(x1) << ", " << x1 << ")" << std::endl;
	else
		std::cout << "Minimo: " << std::setprecision(4) << std::fixed << "(" << f(x2) << ", " << x2 << ")" <<  std::endl;
}

int main() {
	//intervalo [-1, 0]
	double x1 = -1;
	double x2 = 0; 

	minimo(x1, x2);
	maximo(x1, x2);
}