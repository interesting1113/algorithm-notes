class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(0, 1, n, k);
        return ans;
    }

    void dfs(int u, int start, int n, int k) {
        if (u == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; i ++) {
            path.push_back(i);
            dfs(u + 1, i + 1, n, k);
            path.pop_back();
        }
    }
};