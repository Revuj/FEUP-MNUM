#include <iostream>
#include <vector>

using namespace std;

/* Metodo de GAUSS
1) divide-se a primeira equaçao por a11, para tornar unitário o primeiro coeficiente
2) multiplica-se esta nova primeira equacao por -a21 e soma-se à segunda,
obtendo-se uma nova segunda equaçao sem a incógnita x1; em seguida multiplica-se
a nova primeira equaçao por -a31 e soma-se à terceira, obtendo-se uma nova terceira equacao,
tambem sem incógnita x1; continua-se deste modo até que, após n - 1 passos, se tenham n-1
equações sem incógnita x1
3) repita-se o processo, trabalhando agora sobre a segunda colina de coeficientes,
de modo a eliminar a incógnita x2 nas n-2 ultimas equações, e assim sucessivamente, até que
, se tudo correr bem, a última equação contém apenas a incógnita xn, com coeficiente
unitário e, portanto, resolvda; o conjunto destes passos corresponde à fase de triangularização
da matriz dos coeficientes
4) substitui-se o valor de xn assim achado na penultima equaçao (que tem apenas xn-1, xn) e
resolva-se esta em ordem a xn-1; substituem-se os valores de xn-1, xn na penultima equação e 
resolve-se esta em ordem a xn-1; continua-se deste modo até ter resolvido a primeira equação
em ordem a x1; o conjuntos destes passos corresponde à fase de substituição para trás que culmina
com a diagonalização da matriz do sistema*

Note-se de passagem que, neste processo, dividimos cada equação (depois de devidamente reduzida)
pelo seu coeficiente em posição diagonal, num total de n divisões; ora, cada divisão divide
o valor do determinante do sistema pela mesma quantidade e as outras operações (simples 
combinações lineares de linhas) não alteram o valor do determinante; além disso, o determinante
do sistema triangularizado vale uma unidade, de mode que o determinante do sistema pode ser calculado
pelo produto dos divisores utilizados, o que constitui uma regra de cálculo bem mais eficaz.
*/

void print(vector<vector<double>> A) {
	int n = A.size();
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n ; j++) {
			cout << A[i][j] << "\t";
			if (j == n - 1) {
				cout << "| ";
			}
		}
		cout << "\n";
	}
	cout << endl;
}

vector<double> gauss(vector< vector<double> > A) {
	int n = A.size();

	for (int i = 0; i<n; i++) {
		// Search for maximum in this column
		double maxEl = abs(A[i][i]);
		int maxRow = i;
		for (int k = i + 1; k<n; k++) {
			if (abs(A[k][i]) > maxEl) {
				maxEl = abs(A[k][i]);
				maxRow = k;
			}
		}

		// Swap maximum row with current row (column by column)
		for (int k = i; k<n + 1; k++) {
			double tmp = A[maxRow][k];
			A[maxRow][k] = A[i][k];
			A[i][k] = tmp;
		}

		// Make all rows below this one 0 in current column
		for (int k = i + 1; k<n; k++) {
			double c = -A[k][i] / A[i][i];
			for (int j = i; j<n + 1; j++) {
				if (i == j) {
					A[k][j] = 0;
				}
				else {
					A[k][j] += c * A[i][j];
				}
			}
		}
	}

	// Solve equation Ax=b for an upper triangular matrix A
	vector<double> x(n);
	for (int i = n - 1; i >= 0; i--) {
		x[i] = A[i][n] / A[i][i];
		for (int k = i - 1; k >= 0; k--) {
			A[k][n] -= A[k][i] * x[i];
		}
	}
	return x;
}

int main() {
	
	/*Sistema a resolver*/
	//3x - y + 2z = -1
	//x + y + z = 8
	//2x + z = 5

	double l1[] = { 3, -1, 2, -1 };
	vector<double> L1(l1, l1 + sizeof(l1) / sizeof(double));
	double l2[] = { 1, 1, 1, 8 };
	vector<double> L2(l2, l2 + sizeof(l1) / sizeof(double));
	double l3[] = { 2, 0, 1, 5 };
	vector<double> L3(l3, l3 + sizeof(l1) / sizeof(double));

	vector<vector<double>> A;
	A.push_back(L1);
	A.push_back(L2);
	A.push_back(L3);

	print(A);

	vector<double> x = gauss(A);
	cout << "Result:" << endl;
	for (unsigned int i = 0; i < x.size(); i++)
		cout << x[i] << " ";


}

