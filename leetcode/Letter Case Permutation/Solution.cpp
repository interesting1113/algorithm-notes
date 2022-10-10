class Solution {
public:
    vector<string> ans;

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string& s, int u) {
        if (u == s.size()) ans.push_back(s);
        else {
            dfs(s, u + 1);
            if (!isdigit(s[u])) {
                s[u] ^= 32;
                dfs(s, u + 1);
                s[u] ^= 32;
            }
        }
    }
};