#include <iostream>

using namespace std;

const int N = 10e6 + 10; 
int n, q[N], count[N];

int main() {
    
    cin >> n;
    
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    
    int res = 0;
    
    for (int i = 0, j = 0; i < n; i ++) {
        
        count[q[i]] ++;
        
        while (j <= i && count[q[i]] > 1) {
            count[q[j]] --;
            j ++;
        }
        
        res = max(res, i - j + 1);
    }
    
    cout << res << endl;
    return 0;
}