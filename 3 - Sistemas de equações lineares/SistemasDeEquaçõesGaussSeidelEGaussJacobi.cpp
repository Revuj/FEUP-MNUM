#include <iostream>

using namespace std;

/* Métodos Iterativos de resolução de Sistemas*/
/* Condições de Convergência:
	coeficientes têm de ser diagonalmente dominantes
*/

//x1 isolado
double f(double x2, double x3) {
	return (7 - x2 - x3) / 3.0;
}

//x2 isolado
double g(double x1, double x3) {
	return (4 - x1 - 2 * x3) / 4.0;
}

//x3 isolado
double h(double x1, double x2) {
	return (5 - 2 * x2) / 5.0;
}

/* GaussJacobi
Consiste em isolar uma variável por cada equação;
Substituem-se os valores iniciais nas novas equações para o cálculo das variáveis;
Repetir, segundo um critério de paragem.
*/
void gaussJacobi(double x1, double x2, double x3) {

	double xa(x1), ya(x2), za(x3);
	double xn, yn, zn;
	double iterations = 0;

	xn = f(ya, za);
	yn = g(xa, za);
	zn = h(xa, ya);

	while (abs(xn - xa) > pow(10, -5) || abs(yn - ya) > pow(10, -5) || abs(zn - za) > pow(10, -5)) {
		xa = xn;
		ya = yn;
		za = zn;

		xn = f(ya, za);
		yn = g(xa, za);
		zn = h(xa, ya);

		iterations++;
	}

	cout << "Gauss Jacobi: " << endl << "S = (" << xn << ", " << yn << ", " << zn << "); " << "Number of Iterations: " << iterations << endl;
}

/* GaussSeidel
Consiste em isolar uma variável por cada equação;
Substituem-se os valores iniciais nas novas equações para o cálculo da primeira variável.
No cálculo da segunda variável será usado o novo valor calculador da primeira variável, e assim sucessivamente
Repetir, segundo um critério de paragem.
*/
void gaussSeidel(double x1, double x2, double x3) {
	double xa(x1), ya(x2), za(x3);
	double xn, yn, zn;
	double iterations = 0;

	xn = f(ya, za);
	yn = g(xn, za);
	zn = h(xn, yn);

	while (abs(xn - xa) > pow(10, -5) || abs(yn - ya) > pow(10, -5) || abs(zn - za) > pow(10, -5)) {
		xa = xn;
		ya = yn;
		za = zn;

		xn = f(ya, za);
		yn = g(xn, za);
		zn = h(xn, yn);

		iterations++;
	}

	cout << "Gauss Seidel: " << endl << "S = (" << xn << ", " << yn << ", " << zn << "); " << "Number of Iterations: " << iterations << endl;
}
int main() {
	//3x1 + x2 + x3 = 7
	//x1 + 4x2 + 2x3 = 4
	//2x2 + 5x3 = 5

	//condições verificadas
	//3 > 1 + 1
	//4 > 1 + 2
	//5 > 2

	//condições iniciais
	double x1 = 0;
	double x2 = 0;
	double x3 = 0;

	gaussJacobi(x1, x2, x3);
	gaussSeidel(x1, x2, x3);
}