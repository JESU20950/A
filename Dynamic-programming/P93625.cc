#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;

int coeficiente_binomial(const int& n, const int&k){
    Matrix coeficientes = Matrix(n+1, vector<int> (k+1,1));
    for (int i = 1; i<coeficientes.size(); ++i){
		for (int j = 1; j<coeficientes[0].size(); ++j){
				if (i != j){
					coeficientes[i][j] = coeficientes[i-1][j-1] + coeficientes[i-1][j]; 
				}
		}
	}
    return coeficientes[n][k];
}
int main(){
    int n;
    int k;
    while (cin >> n >> k){
		cout << coeficiente_binomial(n,k) << endl;
	}
}
