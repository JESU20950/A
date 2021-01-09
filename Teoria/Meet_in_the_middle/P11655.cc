#include<iostream>
#include<vector>
#include<set>
#include <algorithm> 
using namespace std;
/*
 Given a set of n integers where n <= 40. Each of them is at most 1012, determine the maximum sum s
 ubset having sum less than or equal S where S <= 1018.
 Cost: O(2^(n/2)*n)
 */


int S;
vector<int> sum_subset(const vector<int> s){
	vector<int> result;
	for(int i = 0; i<(1<<s.size()); ++i){
		int sum = 0;
		for (int j = 0; j<s.size(); ++j){
			if ((i>>j)&0x01){
				sum+= s[j];
			}
		}
		result.push_back(sum);
	}
	return result;
}

int binary_search(const vector<int>& v, int s, int p1, int p2){
	if (p1<=p2){
		int m = (p1+p2)/2;
		if (v[m]+s<S){
			return binary_search(v, s, m+1, p2);
		}else if (v[m]+s>S){
                        return binary_search(v, s, p1, m-1);
                }else{
			return m;
		}
	}
	return -1;
}


int main(){
	cin >> S;
	int n;	
	vector <int> s;
	while(cin >> n){
		s.push_back(n);
	}
	vector <int> s1;
	for (int i = 0; i<n/2; ++i){
		s1.push_back(s[i]);
	}
	vector <int> s2;
	for (int i = n/2; i<s.size(); ++i){
		s2.push_back(s[i]);
	}
	s1 = sum_subset(s1);
	s2 = sum_subset(s2);
	sort(s1.begin(), s1.end());
	int sum = 0;
	for (int i = 0; i<s2.size(); ++i){
		int p = binary_search(s1, s2[i], 0, s1.size()-1);
		if (p != -1 and s1[p]+s2[i] > sum){
			sum = s1[p]+s2[i];
		}
	}
	cout << sum << endl;
}

	
