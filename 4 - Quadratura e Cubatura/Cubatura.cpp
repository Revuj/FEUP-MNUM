#include <iostream>

using namespace std;

double f(double x, double y)
{
	return x * y;
}

double simpsonCubature()
{
	double a(4), A(12); //intervalo em x
	double nx = 16; //numero de intervalos em x
	double b(3), B(8); //intervalo em y
	double ny = 10; //numero de intervalos em y
	double hx, hy;
	double sum0(0); //soma dos valores de f nos vértices
	double sum1(0); //soma dos valores de f nos centros
	double sum2(0); //soma dos valores de f nos pontos médios dos lados
	double v1, v2, v3, v4; //vertices do quadrado
	double center; //centro do quadrado
	double mid1, mid2, mid3, mid4; //pontos médios dos lados
	double integrate(0);


	hx = (A - a) / (double)nx; //step on x = 0.5
	hy = (B - b) / (double)ny; //step on y = 0.5
	
	for (double x = a; x <= A - hx; x += hx)
	{
		for (double y = b; y <= B - hy; y += hy)
		{

			v1 = f(x, y);
			v2 = f(x, y + hy);
			v3 = f(x + hx, y + hy);
			v4 = f(x + hx, y);

			sum0 = v1 + v2 + v3 + v4;

			mid1 = f(x, y + hy/2.0);
			mid2 = f(x + hx/2.0, y + hy);
			mid3 = f(x + hx, y + hy/2.0);
			mid4 = f(x + hx/2.0, y);

			sum1 = mid1 + mid2 + mid3 + mid4;

			center = f(x + hx/2.0, y + hy/2.0);

			sum2 = center;
			

			integrate += ((hx/2) * (hy/2) / 9)* (sum0 + 4 * sum1 + 16 * sum2); //se fosse o métodos dos trapézios: 9 -> 4; 4 -> 2; 16 -> 4;

		}
	}
	return integrate;
}

int main()
{
	cout << "Integrate = " << simpsonCubature() << endl;
}