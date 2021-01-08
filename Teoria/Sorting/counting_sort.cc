#include<iostream>
#include<vector>
using namespace std;

//Sort by order of appareance and value
vector <int> counting_sort(const vector<int>& v, const int max){
	vector<int> counting(max);
        for (int i = 0; i<v.size(); ++i){
                counting[v[i]] = counting[v[i]] +1;
        }       
        for (int i  = 0; i<max; ++i){
                counting[i] = counting[i] + counting[i-1];
        }
	vector<int> result(v.size());
	for (int i = v.size()-1; i>=0; --i){
		result[counting[v[i]]-1] = v[i];
		counting[v[i]] = counting[v[i]] -1;
	}
	return result;
}
int main(){
	int n;
	vector<int> v;
	cin >> n;
	v.push_back(n);
	int max = n;
	while (cin >> n){
		if (max < n){
			max = n;
		}
		v.push_back(n);
	}
	vector<int> result = counting_sort(v, max+1);
	for (int i = 0; i<result.size(); ++i){
		cout << result[i] << endl;
	}
	
}

