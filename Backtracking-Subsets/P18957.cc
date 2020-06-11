#include <iostream>
#include <vector>
using namespace std;

void backtracking(const vector<string >& words, vector<bool>& binary, int puntero){
    if (puntero == binary.size()){
        cout << "{";
        bool first = true;
        for (int i = 0; i<binary.size(); ++i){
            if (binary[i] and first){
                cout << words[i];
                first = false;
            }else if (binary[i]){
                cout << "," << words[i];
            }
        }
        cout << "}" << endl;
    }else{
        binary[puntero] = false;
        backtracking(words,binary, puntero+1);
        binary[puntero] = true;
        backtracking(words,binary,puntero+1);
    }
}

int main(){
    int n;
    cin >> n;
    vector <string> words = vector<string> (n);
    for (int i = 0; i < n; ++i){
        cin >> words[i];
    }
    vector <bool> binary = vector<bool> (n);
    backtracking(words, binary, 0);
}
