#include <iostream>
#include <stack>
using namespace std;

bool palindrom(){
    stack <int> s;
    int n;
    int nombre;
    cin >> n;
    for (int i = 0; i<n/2; ++i){
        cin >> nombre;
        s.push(nombre);
    }
    if (n%2 != 0) cin >> nombre;
    for (int i = 0; i<n/2; ++i){
        cin >> nombre;
        if (s.top() != nombre) return false;
        s.pop();
    }
    return true;
        
}



int main(){
    if (palindrom()) cout << "SI" << endl;
    else cout << "NO" << endl;
}
 
