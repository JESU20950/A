#include <vector>
#include <iostream>
using namespace std;


void backtracking(const vector<string>& words, vector<bool>& binary, int zeros, int unos, int puntero){
        if (puntero == words.size()){
            cout << "{";
            bool first = true;
            for (int i = 0; i < words.size(); i++){
                    if (binary[i] and first){
                        cout << words[i];
                        first = false;
                    }else if (binary[i]){
                        cout << "," << words[i];
                    }                
            }
            cout << "}" << endl;
        }else{
            if (zeros != 0){
                binary[puntero] = false;
                backtracking (words,binary,zeros-1,unos, puntero+1);
            }
            if (unos != 0){
                binary[puntero] = true;
                backtracking (words,binary,zeros,unos-1,puntero+1);
            }
        }
        
}
int main(){
    int m;
    int unos;
    cin >> unos >> m;
    vector <string> words = vector <string> (m);
    int zeros = m-unos;
    vector <bool> binary = vector<bool> (m);
    for (int i = 0; i < words.size(); ++i){
            cin >> words[i];
    }
    backtracking(words,binary,zeros, unos, 0);
    
    
}
