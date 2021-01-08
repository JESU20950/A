#include <cmath>
#include <iostream>
#include <vector>
using namespace std;



vector<bool> column;
vector<bool> diagonal1;
vector<bool> diagonal2;

int diag1(int x, int y){
	if ((x-y) >= 0) return x-y;
	else return column.size()+(y-x);
}
int diag2(int x, int y){
        return x+y;
}

 
int backtracking(int pos){
        if (pos == column.size()){ 
		return 1;
	}
        int sum = 0;
        for (int i = 0; i<column.size(); ++i){
                if(not column[i] and not diagonal1[diag1(i,pos)] and not diagonal2[diag2(i,pos)]){
			column[i] = true;
	     		diagonal1[diag1(i,pos)] = true;
			diagonal2[diag2(i,pos)] = true;
			int pos_aux = pos+1;	
                        sum = sum + backtracking(pos_aux);
			column[i] = false;
			diagonal1[diag1(i,pos)] = false;
                        diagonal2[diag2(i,pos)] = false;
                }
        }       
        return sum;
}

int main(){
	int n;
	cin >> n;
	column = vector<bool> (n, false);
	diagonal1 = vector<bool> (2*n-1, false);
	diagonal2 = vector<bool> (2*n-1, false);
	cout << backtracking(0) << endl;
}




