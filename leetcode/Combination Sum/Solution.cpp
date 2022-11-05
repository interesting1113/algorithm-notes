class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
    
    void dfs(vector<int>& candidates, int target, int u) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if ( u == candidates.size()) return;
        
        for (int i = 0; candidates[u] * i <= target; i ++) {
            dfs(candidates, target - candidates[u] * i, u + 1);
            path.push_back(candidates[u]);
        }
        
        for (int i = 0; candidates[u] * i <= target; i ++) {
            path.pop_back();
        }
    }
};