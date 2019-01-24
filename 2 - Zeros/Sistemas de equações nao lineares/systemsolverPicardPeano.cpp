#include <iostream>
#include <cmath> 

using namespace std;

double g1(double x, double y)
{
	return (sqrt((x*y+5*x-1)/2));
}

double g2(double x, double y)
{
	return (sqrt(x+3*log(x)));
}

int main()
{
	int iterationCounter = 0;
	double x0 = 4, y0 = 4; //guess
	
	double x1 = g1(x0, y0);
	double y1 = g2(x0, y0);

	while ((abs(x1 - x0) >= pow(10, -5)) && (abs(y1 - y0) >= pow(10, -5)))
	{
		x0 = x1;
		y0 = y1;

		iterationCounter++;

		x1 = g1(x0, y0);
		y1 = g2(x0, y0);
	}

	cout << "{ x = " << x1 << ", y = " << y1 << "}" << endl;
	cout << "Number of iterations = " << iterationCounter << endl;
}