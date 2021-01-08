#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    char c;
    priority_queue <int> q;
    int x;
    while (cin >> c){
        if (c == 'S'){
        cin >> x;
        q.push(x);
        }else if (c == 'A'){
        if (q.empty()) cout << "error!" << endl;
        else cout << q.top() << endl;
        
        }else if (c == 'R'){
            if (q.empty()) cout << "error!" << endl;
            else q.pop();
            
        }else if (c == 'I'){
            cin >> x;
            if (q.empty()) cout << "error!" << endl;
            else{
            x = q.top()+x;
            q.pop();
            q.push(x);
            }
            
            
        }else{
            cin >> x;
            if(q.empty()) cout << "error!" << endl;
            else{
            x = q.top()-x;
            q.pop();
            q.push(x);
            }
            
        }
    }
}
