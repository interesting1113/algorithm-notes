class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i ++) {
            // 长度为基数的时候
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            // (r - 1) - (l + 1) - 1
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);

            // 长度为偶数的时候
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l --, r ++;
            // (r - 1) - (l + 1) - 1
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};