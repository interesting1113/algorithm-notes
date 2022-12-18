#include <iostream>

using namespace std;

const int N = 10;
int n;
int path[N];
bool state[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i ++) printf("%d ", path[i]);
        puts("");
        return;
    }
    
    for (int i = 1; i <= n; i ++) {
        if (!state[i]) {
            path[u] = i;
            state[i] = true;
            dfs(u + 1);
            path[u] = 0;
            state[i] = false;
        }
    }
}

int main() {
    
    scanf("%d", &n);
    
    dfs(0);
    
    return 0;
}