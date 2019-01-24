#include <iostream>
#include <iomanip>

using namespace std;

//dz/dx = x + y + z
double dz(double x, double y, double z) {
	return x + y + z;
}

//dy/dx = x * y - z
double dy(double x, double y, double z) {
	return x * y - z;
}

/* Euler
x1 = x0 + h
y1 = y0 + h * dy(x0,y0,z0)
z1 = z0 + h * dz(x0,y0,z0)
QC = ~2
E'' = S'' - S'
*/
void euler(double a, double b, double h) {
	//n deve ser um double.
	double n = (b - a) / h;

	double xn, yn, zn;
	//condições iniciais
	double xa = 0, ya = 0, za = 0;

	for (unsigned int i = 0; i < n; i++) {
		xn = xa + h;
		yn = ya + h * dy(xa, ya, za);
		zn = za + h * dz(xa, ya, za);

		xa = xn;
		ya = yn;
		za = zn;
	}

	cout << "( " << xn << ", " << yn << ", " << zn << ")" << endl;
}


/* Range kutta 4th order
x1 = x0 + h
y1 = y0 + 1 / 6 * dy1 + 1 / 3 * dy2 + 1 / 3 dy3 + 1 / 6 dy4
z1 = y0 + 1 / 6 * dz1 + 1 / 3 * dz2 + 1 / 3 dz3 + 1 / 6 dz4
QC = ~16
E'' = (S'' - S') / 15
*/
void rk4(double a, double b, double h) {
	//n deve ser um double. 
	double n = (b - a) / h;

	double xn, yn, zn;
	//condições iniciais
	double xa = 0, ya = 0, za = 0;

	//o calculo destas variaveis tem de ser feito alternadamente, pois, por exemplo, dz2 requer o valor de dy1
	double dy1, dy2, dy3, dy4;
	double dz1, dz2, dz3, dz4;

	for (unsigned int i = 0; i < n; i++) {
		dy1 = h * dy(xa, ya, za);
		dz1 = h * dz(xa, ya, za);

		dy2 = h * dy(xa + h / 2.0, ya + dy1 / 2.0, za + dz1 / 2.0);
		dz2 = h * dz(xa + h / 2.0, ya + dy1 / 2.0, za + dz1 / 2.0);

		dy3 = h * dy(xa + h / 2.0, ya + dy2 / 2.0, za + dz2 / 2.0);
		dz3 = h * dz(xa + h / 2.0, ya + dy2 / 2.0, za + dz2 / 2.0);

		dy4 = h * dy(xa + h, ya + dy3, za + dz3);
		dz4 = h * dz(xa + h, ya + dy3, za + dz3);

		xn = xa + h;
		yn = ya + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;
		zn = za + dz1 / 6.0 + dz2 / 3.0 + dz3 / 3.0 + dz4 / 6.0;

		xa = xn;
		ya = yn;
		za = zn;
	}

	cout << "( " << xn << ", " << yn << ", " << zn << ")" << endl;
}

int main() {
	//intervalo dado no enunciado
	double a = 0.0;
	double b = 1.0;

	//step à nossa escolha
	double h = 0.01;
	double h1 = h / 2;
	double h2 = h1 / 2;

	cout << "Euler: " << endl;
	cout << "Results:" << endl;
	euler(a, b, h);



	cout << endl;

	cout << "Range Kutta (4th order): " << endl;
	rk4(a, b, h);
}