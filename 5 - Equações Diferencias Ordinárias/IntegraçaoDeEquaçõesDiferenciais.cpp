#include <iostream>
#include <iomanip>

using namespace std;

//y' = f(x,y) = x^2 + y^2
double f(double x, double y) {
	return x * x + y * y;
}

/* Euler
x1 = x0 + h
y1 = y0 + h * f(x0,y0)
QC = ~2
E'' = S'' - S'
*/
double euler(double a, double b, double h) {
	//n deve ser um double. Neste caso, se fosse inteiro, n <-- 13 quando na realidade queremos que seja 14!
	double n = (b - a) / h;

	double xn, yn;
	//condições iniciais
	double xa = 0, ya = 0;

	for (unsigned int i = 0; i < n; i++) {
		xn = xa + h;
		yn = ya + h * f(xa, ya);

		xa = xn;
		ya = yn;
	}

	return yn;
}

double convergenceQuotientEuler(double a, double b, double h) {
	double S, S1, S2;

	S2 = euler(a, b, h);
	S1 = euler(a, b, h / 2.0);
	S = euler(a, b, h / 4.0);

	return (S2 - S1) / (S1 - S);
}

double eulerError(double a, double b, double h) {
	double S2 = euler(a, b, h);
	double S1 = euler(a, b, h * 2.0);

	return S2 - S1;
}

/* Range Kutta 2nd order
x1 = x0 + h
y1 = y' + h * f(x0 + h/2, y0 + h/2 * f(x0, y0))
QC = ~4
E'' = (S'' - S') / 3
*/
double rk2(double a, double b, double h) {
	//n deve ser um double. Neste caso, se fosse inteiro, n <-- 13 quando na realidade queremos que seja 14!
	double n = (b - a) / h;

	double xn, yn;
	//condições iniciais
	double xa = 0, ya = 0;

	for (unsigned int i = 0; i < n; i++) {
		xn = xa + h;
		yn = ya + h * f(xa + h / 2.0, ya + h / 2.0 * f(xa, ya));

		xa = xn;
		ya = yn;
	}

	return yn;
}

double convergenceQuotientRk2(double a, double b, double h) {
	double S, S1, S2;

	S2 = rk2(a, b, h);
	S1 = rk2(a, b, h / 2.0);
	S = rk2(a, b, h / 4.0);

	return (S2 - S1) / (S1 - S);
}

double rk2Error(double a, double b, double h) {
	double S2 = rk2(a, b, h);
	double S1 = rk2(a, b, h * 2.0);

	return (S2 - S1) / 3.0;
}


/* Range kutta 4th order
x1 = x0 + h
y1 = y0 + 1 / 6 * dy1 + 1 / 3 * dy2 + 1 / 3 dy3 + 1 / 6 dy4
QC = ~16
E'' = (S'' - S') / 15
*/
double rk4(double a, double b, double h) {
	//n deve ser um double. Neste caso, se fosse inteiro, n <-- 13 quando na realidade queremos que seja 14!
	double n = (b - a) / h;

	double xn, yn;
	//condições iniciais
	double xa = 0, ya = 0;

	double dy1, dy2, dy3, dy4;

	for (unsigned int i = 0; i < n; i++) {
		dy1 = h * f(xa, ya);
		dy2 = h * f(xa + h / 2.0, ya + dy1 / 2.0);
		dy3 = h * f(xa + h / 2.0, ya + dy2 / 2.0);
		dy4 = h * f(xa + h, ya + dy3);

		xn = xa + h;
		yn = ya + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;

		xa = xn;
		ya = yn;
	}

	return yn;
}

double convergenceQuotientRk4(double a, double b, double h) {
	double S, S1, S2;

	S2 = rk4(a, b, h);
	S1 = rk4(a, b, h / 2.0);
	S = rk4(a, b, h / 4.0);

	return (S2 - S1) / (S1 - S);
}

double rk4Error(double a, double b, double h) {
	double S2 = rk4(a, b, h);
	double S1 = rk4(a, b, h * 2.0);

	return (S2 - S1) / 15.0;
}

int main() {
	//passo
	double h = 0.1;
	double h1 = h / 2.0;
	double h2 = h1 / 2.0;

	//Intervalo do integral: 0 a 1.4, em x -> S 0--->14 y' dx
	double a = 0;
	double b = 1.4;

	cout << fixed << setprecision(8);
	cout << "-------------------------------------------------" << endl;
	cout << "Euler: " << endl << endl;
	cout << "Results: " << endl;
	cout << "S = " << euler(a, b, h) << endl;
	cout << "S1 = " << euler(a, b, h1) << endl;
	cout << "S2 = " << euler(a, b, h2) << endl;
	cout << "Convergence Quotient = " << convergenceQuotientEuler(a, b, h) << endl;
	cout << "Aprox Error = " << eulerError(a, b, h2) << endl;

	cout << endl << "-------------------------------------------------" << endl;
	cout << "Range Kutta (2nd order): " << endl << endl;
	cout << "Results: " << endl;
	cout << "S = " << rk2(a, b, h) << endl;
	cout << "S1 = " << rk2(a, b, h1) << endl;
	cout << "S2 = " << rk2(a, b, h2) << endl;
	cout << "Convergence Quotient = " << convergenceQuotientRk2(a, b, h) << endl;
	cout << "Aprox Error = " << rk2Error(a, b, h2) << endl;

	cout << endl << "-------------------------------------------------" << endl;
	cout << "Range Kutta (4th order): " << endl << endl;
	cout << "Results: " << endl;
	cout << "S = " << rk4(a, b, h) << endl;
	cout << "S1 = " << rk4(a, b, h1) << endl;
	cout << "S2 = " << rk4(a, b, h2) << endl;
	cout << "Convergence Quotient = " << convergenceQuotientRk4(a, b, h) << endl;
	cout << "Aprox Error = " << rk4Error(a, b, h2) << endl;
}