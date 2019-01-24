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
	double ynSum1 = 0, ynSum2 = 0;
	double h, n, xi, xf;


	cout << "n steps ? "; cin >> n; ///n must be pair;
	xi = 0;
	xf = acos(-1);

	h = (xf - xi) / (2*n);


	/*alternativa
	for (double i = xi + h; i <= xf-h; i = i + 2*h) 
	{
		ynSum1 += f(i);
	}
	*/
	for (int i = 1; i < 2*n - 1; i = i + 2)
	{
		ynSum1 += f(h*i);
	}

	/*alternativa
	for (double i = xi + 2*h; i <= xf-2*h; i = i + 2*h)
	{
		ynSum2 += f(i);
	}
	*/
	for (int i = 2; i < 2*n - 2; i = i + 2)
	{
		ynSum2 += f(h*i);
	}

	integrate = (h / 3) * (f(xi) + 4 * ynSum1 + 2 * ynSum2 + f(xf));

	cout << "Integrate = " << integrate;
}

