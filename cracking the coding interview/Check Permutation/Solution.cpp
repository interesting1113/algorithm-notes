class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> map(128, 0);
        if (s1.size() != s2.size()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        return s1 == s2;
    }
};