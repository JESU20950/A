#include <iostream>
#include <vector> 
using namespace std;

int select_aux(int k, const vector<int>& v1, const vector<int>& v2, int v1_begin, int v1_end, int v2_begin, v2_end){
	
}	
int select(int k, const vector<int>& v1, const vector<int>& v2){
 	return select_aux(k, v1, v2, 0, v1.size(), 0, v2.size());
}

int main(){
  int n;
  cin >> n;
  vector<int> v1(n);
  int m;
  cin >> m;
  vector<int> v2(m);
  for (int i = 0; i<n; ++i){
    cin >> v1[i];
  }
  for (int i = 0; i<m; ++i){
    cin >> v2[i];
  }
  int k;
  cin >> k;
  cout << select(k, v1, v2) << endl;
}
