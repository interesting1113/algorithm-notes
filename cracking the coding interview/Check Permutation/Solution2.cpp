class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> map(128, 0);
        if (s1.size() != s2.size()) return false;

        for (int i = 0; i < s1.size(); i ++) {
            map[s1[i]] ++;
        }

        for (int j = 0; j < s2.size(); j ++) {
            map[s2[j]] --;
            if (map[s2[j]] < 0) return false;
        }

        return true;
    }
};