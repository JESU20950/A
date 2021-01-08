#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
  int x, y, n;
  while (cin >> x >> y >> n){
    set <int> s;
    set<int>::iterator it;
    int sum = 0;
    bool trobat = false;
    while (n<= 100000000 and not trobat){
      s.insert(n);
      if (n%2 == 0){
	n = n/2 + x;
      }else{
	n = 3*n + y;
      }
      it = s.find(n);
      trobat = (it != s.end());
    }
    if (n >= 100000000) cout << n << endl;
    else{
     it = s.begin();
     while(it != s.end()){
       s.erase(n);
       ++sum;
       if (n%2 == 0){
	n = n/2 + x;
       }else{
	n = 3*n + y;
       }
      it = s.find(n);
     }
     cout << sum << endl;
    }    
  }
}