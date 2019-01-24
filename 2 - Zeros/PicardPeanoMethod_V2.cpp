#include <iostream>
#include <cmath> 

using namespace std;

double f(double n)
{
	return (n - 2 * log(n) - 5);
}

double df(double n)
{
	return (1 - 2 * (1 / n));
}

int main()
{
	int iterationCounter = 0;
	double xn, x0;
	cout << "x0 ? "; cin >> x0;

	xn = exp((x0 - 5) / 2);

	if ((1/2) * exp((x0 - 5) / 2) >= 1)
	{
		cout << "bad" << endl;
		return 0;
	}

	while (abs(xn - x0) >= pow(10, -5))
	{
		x0 = xn;

		iterationCounter++;

		xn = exp((x0 - 5) / 2);
	}

	cout << "The root = " << xn << endl;
	cout << "Number of iterations = " << iterationCounter << endl;
}