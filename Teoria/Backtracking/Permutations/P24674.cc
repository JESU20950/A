#include <iostream>
#include <vector>
using namespace std;

void escriure_permutacions(const vector<string>& paraules, int indexaomplir,
vector<bool>& usat, vector<string>& resultat){
    if (indexaomplir == resultat.size()){
     cout << "(";
     cout << resultat[0];
     for (int i = 1; i<resultat.size(); ++i) cout << "," << resultat[i];
     cout << ")" << endl;
    }else{
     for (int i = 0; i< paraules.size(); ++i){
      if (not usat[i]){
          resultat[indexaomplir] = paraules[i];
          usat[i] = true;
          escriure_permutacions(paraules,indexaomplir+1, usat,resultat);
          usat[i] = false;
      }
     }  
    }
    
    
    
}

int main(){
 int n;
 cin >> n;
 vector<string> paraules(n);
 for (int i = 0; i<n; ++i) cin >> paraules[i]; 
 
 vector<string>resultat(n);
 vector<bool> usat(n,false);
 escriure_permutacions(paraules, 0, usat, resultat);
}
