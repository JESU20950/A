#include <vector>
#include <iostream>
using namespace std;


int main(){
    int w, h, c;
    cin >> w >> h >> c;
    vector <vector<int> >  numbers(h,vector <int> (w));
    for (int i = 0; i< w; ++i){
        for(int j = 0; j<h; ++j){
                cin >> numbers[i][j];
        }
    }
    
    vector <vector <int> >  memory(h, vector <int>(w-c+1,0));
    for (int i = 0; i <h; ++i){
        for (int j = 0; j< c; ++j){
            memory[i][0] = memory[i][0] + numbers[i][j];
        }
        for (int j = 1; j < w-c+1; j++){
            memory[i][j] = memory[i][j-1] - numbers[i][j-1] + numbers[i][j+c-1];
        }
    }
    
    vector< vector <int>  > memory2(h-c+1, vector<int>(w-c+1,0));
    for (int j = 0; j < w-c+1; ++j){
        for (int i = 0; i < c; ++i){
          memory2[0][j] = memory2[0][j] + memory[i][j];
        }
        for (int i = 1; i < h-c+1; ++i){
          memory2[i][j] = memory2[i-1][j] - memory[i-1][j] + memory[i+c-1][j]; 
        }
    }
    int max = memory2[0][0];
    int maxi = 0;
    int maxj = 0;
    for (int i = 0; i < h-c+1; ++i){
        for(int j = 0; j< w-c+1; ++j){
           if (memory2[i][j] > max){
                max = memory2[i][j];
                maxi = i;
                maxj = j;
           }
        }
    }
    cout << maxi << " " << maxj << endl;
}
