#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<char>& word, int zeros, int unos, int puntero){
    if (puntero == word.size()){
        cout << word[0];
        for (int i = 1; i<word.size(); ++i){
            cout << " " << word[i];
        }
        cout << endl;
        
        
    }else{
        if (zeros != 0){
            word[puntero] = '0';
            backtracking(word,zeros-1, unos, puntero+1);
        }
        if (unos != 0){
            word[puntero] = '1';
            backtracking(word,zeros, unos-1, puntero+1);
        }
    }
}


int main(){
    int n;
    int unos;
    cin >> n >> unos;
    int zeros  = n -unos;
    vector <char> word = vector<char> (n);
    backtracking(word, zeros, unos, 0);
    
}
