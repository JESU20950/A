#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; 
    int k = 1;
    while(cin >> n){
        cout << '#' << k << endl;
        vector<int> data = vector<int> (n);
        cin >> data[0];
        for (int i = 1; i<n; ++i){
            cin >> data[i];
            data[i] = data[i-1]+data[i];
        }
        int n_elements;
        cin >> n_elements;
        for (int i = 0; i<n_elements; ++i){
                int d1, d2;
                cin >> d1 >> d2;
                if (d1 < d2){
                    if (d2-1 <0) d2 = 1;
                    cout << data[d2-1]-data[d1-2] << endl;
                }else{
                    if (d1-1 <0) d1 = 1;
                    cout << data[d1-1]-data[d2-2] << endl;
                }
        }
        k++;
    }
}

