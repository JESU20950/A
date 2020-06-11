#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


typedef vector< vector<long long int> > Matrix;
unsigned long long K = pow(10, 8)+7;

Matrix product(const Matrix& a, const Matrix& b){
	Matrix result = Matrix(2,vector<long long int> (2));
	for (int i = 0; i<2; ++i){
		for (int j  = 0; j<2; ++j){
			result[i][j] = 0;
			for (int k = 0; k<2; ++k){
				result[i][j] = (result[i][j]%K + (a[i][k]*b[k][j])%K);
			}
		}
	}
	return result;
}
Matrix exponentiation(const Matrix& a, int n){
		if (n == 1){
			return a;
		}
		if (n%2 == 0){
			Matrix result = exponentiation(a,n/2);
			return product(result,result);
		}
		if (n%2 != 0){
			Matrix result = exponentiation(a,n/2);
			return product(product(result,result),a);
		}
}


void fibonacci_v1(){
//Coste n
   int n;
   while(cin >> n){
            long long F1 = 0;
            long long F2 = 1;
            for (int i = 0; i<n-1; ++i){
                int F3 = (F1+F2);
                F1= F2%K;
                F2= F3%K;
            }
            cout << F2 << endl;
   }    
}

void fibonacci_v2(){
//Coste log(n)
   int n;
   while(cin >> n){
	   if (n == 0){
		   cout << 0 << endl;
	   }else if(n == 1){
		   cout << 1 << endl;
	   }else{
		   Matrix base = Matrix(2,vector<long long int> (2));
		   base[0][0] = 1;
		   base[0][1] = 1;
		   base[1][0] = 1;
		   base[1][1] = 0;
		   Matrix result = exponentiation(base,n-1);
		   cout << result[0][0] << endl;
	   }
   }    	
}
int main(){
	fibonacci_v1();
}

