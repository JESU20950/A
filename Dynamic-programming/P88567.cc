#include <iostream>
#include <vector>
using namespace std;

int letras(int n){
    return (n*(n+1))/2;
}
int main(){
  string palabra;
  cin >> palabra;
  vector<vector<int> > square (palabra.size(),vector <int> (palabra.size()));
  square[0][0] = letras('A'-palabra[0]+1);
  cout << square[0][0];
  for (int i = 1; i<palabra.size(); i++){
      square[0][i] = square[0][i-1] + letras('A'-palabra[i]+1);
      cout << square[0][i];
  }
  cout << endl;
  for (int i = 1; i<palabra.size(); ++i){
      cin >> palabra;
      square[i][0] = letras('A'-palabra[0]+1) + square[i-1][0];
      cout << square[i][0];
      for (int j = 1; j<palabra.size(); j++){
        square[i][j] = square[i][j-1] + square[i-1][j] + letras('A'-palabra[j]+1);
        cout << square[i][j];
      }
      cout << endl;
  }
    
}
