#include <map>
#include <iostream>
#include <string>
using namespace std;


int main(){
    map<string, int> m;
    string nom;
    string operacio;
    int n;
    map<string, int>::iterator it;
    while (cin >> nom){
     cin >> operacio;  
     it = m.find(nom);
     if (operacio == "enters"){
         if (it == m.end()){
             m.insert(make_pair(nom,0));
         }else{
             cout << nom << " is already in the casino" << endl;
         }
     }else if (operacio == "leaves"){
         if (it == m.end()){
             cout << nom << " is not in the casino"  << endl;
         }else {
             cout << nom << " has won " << it -> second << endl;
             m.erase(it);
         }
     }else {
         cin >> n;
         if (it == m.end()){
            cout << nom << " is not in the casino"  << endl;
         }else{
           it -> second = it->second + n;   
         }
     }
    }
    cout << "----------" << endl;
    it = m.begin();
    while (it !=  m.end()){
     cout << it -> first << " is winning " << it -> second << endl;
     ++it;   
    }
}

