%%%%%%#include <iostream>

using namespace std;

double resultado[3];

double dz(double x, double y, double z)
{
	return x - 3 * z - 2 * y;
}

double dy(double x, double y, double z)
{
	return z;
}

void printResultado()
{
	cout << "( " << resultado[0] << ", " << resultado[1] << ", " << resultado[2] << " )" << endl;
}
//======================================================
//=======================EULER==========================
//======================================================

void euler(double a, double b, double h)
{
	double n = (b - a) / h;

	//condição inicial
	double xa = 0.0;
	double ya = 1.0;
	double za = 1.0;

	double xn = 0.0;
	double yn = 0.0;
	double zn = 0.0;

	for (size_t i = 0; i < n; i++)
	{
		xn = xa + h;
		yn = ya + h * dy(xa, ya, za);
		zn = za + h * dz(xa, ya, za);

		xa = xn;
		ya = yn;
		za = zn;
	}

	resultado[0] = xn;
	resultado[1] = yn;
	resultado[2] = zn;
}


//======================================================
//========================RK4===========================
//======================================================
void rk4(double a, double b, double h)
{
	double n = (b - a) / h;

	double xa = 0.0;
	double ya = 1.0;
	double za = 1.0;

	double xn = 0.0;
	double yn = 0.0;
	double zn = 0.0;

	double dy1, dy2, dy3, dy4;
	double dz1, dz2, dz3, dz4;

	for (size_t i = 0; i < n; i++)
	{
		xn = xa + h;

		dz1 = h * dz(xa, ya, za);
		dy1 = h * dy(xa, ya, za);

		dz2 = h * dz(xa + h / 2, ya + dy1 / 2, za + dz1 / 2);
		dy2 = h * dy(xa + h / 2, ya + dy1 / 2, za + dz1 / 2);

		dz3 = h * dz(xa + h / 2, ya + dy2 / 2, za + dz2 / 2);
		dy3 = h * dy(xa + h / 2, ya + dy2 / 2, za + dz2 / 2);

		dz4 = h * dz(xa + h, ya + dy3, za + dz3);
		dy4 = h * dy(xa + h, ya + dy3, za + dz3);

		yn = ya + dy1 / 6.0 + dy2 / 3.0 + dy3 / 3.0 + dy4 / 6.0;
		zn = za + dz1 / 6.0 + dz2 / 3.0 + dz3 / 3.0 + dz4 / 6.0;

		xa = xn;
		ya = yn;
		za = zn;
	}
	resultado[0] = xn;
	resultado[1] = yn;
	resultado[2] = zn;
}

int main()
{
	//intervalo dado no enunciado
	double a = 0.0;
	double b = 0.5;

	//step à nossa escolha
	double h = 0.05;
	double h1 = h / 2;
	double h2 = h1 / 2;

	double y2, y1, y0;
	double z2, z1, z0;

	cout << "EXERCISE 2: " << endl;
	cout << "Range Kutta (4th order): " << endl;
	cout << "Results:" << endl;
	cout << "R1 = "; rk4(a, b, h); printResultado();
	y0 = resultado[1];
	z0 = resultado[2];
	cout << "R2 = "; rk4(a, b, h1); printResultado();
	y1 = resultado[1];
	z1 = resultado[2];
	cout << "R3 = "; rk4(a, b, h2); printResultado();
	y2 = resultado[1];
	z2 = resultado[2];
	cout << "Convergence Quotients: " << endl;
	cout << "CQ_Y = " << (y1 - y0) / (y2 - y1);
	cout << endl;
	cout << "CQ_Z = " << (z1 - z0) / (z2 - z1);
	cout << endl;
	cout << "Associated errors: " << endl;
	cout << "Y ERROR = " << (y2 - y1) / 15 << endl;
	cout << "Z ERROR = " << (z2 - z1) / 15 << endl;
	cout << endl;


	/*
	cout << "EXERCISE 1" << endl;
	cout << "Range Kutta (4th order): " << endl;
	cout << "Results:" << endl;
	cout << "R1 = "; rk4(a, b, h); printResultado();
	y2 = resultado[1];
	z2 = resultado[2];
	cout << "R2 = "; rk4(a, b, h1); printResultado();
	y1 = resultado[1];
	z1 = resultado[2];
	cout << "R3 = "; rk4(a, b, h2); printResultado();
	y0 = resultado[1];
	z0 = resultado[2];
	cout << "Convergence Quotients: " << endl;
	cout << "CQ_Y = " << (y2 - y1) / (y1 - y0);
	cout << endl;
	cout << "CQ_Z = " << (z2 - z1) / (z1 - z0);
	cout << endl;
	cout << "Associated errors: " << endl;
	cout << "Y ERROR = " << (y2 - y1) / 15 << endl;
	cout << "Z ERROR = " << (z2 - z1) / 15 << endl;
	cout << endl;
	*/
}