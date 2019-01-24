#include <iostream>
#include <cmath>

using namespace std;

double f(double n)
{
	return sin(n);
}

int main()
{
	double integrate = 0;
	double ynSum = 0;
	double h, n, xi, xf;


	cout << "n steps ? "; cin >> n;
	cout << "xi ? "; cin >> xi;
	cout << "xf ? "; cin >> xf;

	h = (xf - xi) / n;



	for (double i = xi + h; i <= xf - h; i += h)
	{
		ynSum += f(i);
	}

	integrate = h / 2 * (f(xi) + f(xf) + 2 * ynSum);

	cout << "Integrate = " << integrate;
}