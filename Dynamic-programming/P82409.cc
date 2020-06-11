#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<long long> > Matrix;

long long coeficiente_binomial(const int& n, const int&k){
    Matrix coeficientes = Matrix(n+1, vector<long long> (k+1,1));
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
    while(cin >> n){
		if (n%2 == 0){
			n = n/2;
			cout << coeficiente_binomial(2*n,n)/(n+1) << endl;
		}else{
			cout << 0 << endl;
		}
	}
}
