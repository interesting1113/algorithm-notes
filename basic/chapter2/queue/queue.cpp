#include <iostream>

using namespace std;

const int N = 100010;
int q[N], hh, tt = -1;

int main() {
    
    int m, x;
    
    cin >> m;
    
    while (m --) {
        
        string op;
        
        cin >> op;
        
        if (op == "push") {
            cin >> x;
            q[++ tt] = x;
        } else if (op == "query") {
            cout << q[hh] << endl;
        } else if (op == "pop") {
            hh ++;
        } else if (op == "empty") {
            if (hh <= tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        } 
    }
    return 0;
}