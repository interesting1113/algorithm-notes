#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int v[N]; // 体积
int w[N]; // 价值
int f[N][N]; // f[i][j], j体积下前i个物品的最大价值

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (j < v[i]) {
                f[i][j] = f[i - 1][j];
            } else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]); 
            }

        }
    }
    cout << f[n][m] << endl;
    return 0;
}
