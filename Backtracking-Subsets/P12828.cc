#include <iostream>
#include <vector>
using namespace std;





void escriure_nombres_binari(vector <int>& v, int puntero){
  if (puntero == v.size()){
    cout << v[0];
    for (int i = 1; i<v.size(); ++i){
      cout << " " << v[i];
    }
    cout << endl;
    
  }else{
    v[puntero] = 0;
    escriure_nombres_binari(v, puntero+1);
    v[puntero] = 1;
    escriure_nombres_binari(v, puntero+1);
  }
}


int main(){
  int n;
  cin >> n;
  vector <int> v(n);
  escriure_nombres_binari(v,0);
}
