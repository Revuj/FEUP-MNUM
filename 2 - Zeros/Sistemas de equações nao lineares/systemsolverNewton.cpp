double f1(double x, double y) {
	return x * x - y - 1.2;
}

double df1dx(double x, double y) {
	return 2 * x;
}

double df1dy(double x, double y) {
	return -1;
}

double f2(double x, double y) {
	return -x + y * y - 1;
}

double df2dx(double x, double y) {
	return -1;
}

double df2dy(double x, double y) {
	return 2 * y;
}


int main() {
	double x0 = 1;
	double y0 = 1;
	double xn, yn;

	for (unsigned int i = 0; i < 2; i++) {
		xn = x0 - (f1(x0, y0)*df2dy(x0, y0) - f2(x0, y0)*df1dy(x0, y0)) / (df1dx(x0, y0)*df2dy(x0, y0) - df2dx(x0, y0)*df1dy(x0, y0));
		yn = y0 - (f2(x0, y0)*df1dx(x0, y0) - f1(x0, y0)*df2dx(x0, y0)) / (df1dx(x0, y0)*df2dy(x0, y0) - df2dx(x0, y0)*df1dy(x0, y0));

		x0 = xn;
		y0 = yn;
		cout << x0 << '\t' << y0 << endl;
	}
}