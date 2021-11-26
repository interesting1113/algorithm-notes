class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res;
        for (int i = 0; i < numRows; i ++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += 2 * numRows - 2) {
                    res += s[j];
                }
            } else {
                for (int k = i, j = 2 * numRows - 2 - i; k < s.size() || j < s.size(); k += 2 * numRows - 2, j += 2 * numRows - 2) {
                    if (k < s.size()) res += s[k];
                    if (j < s.size()) res += s[j];
                }
            }
        }
        return res;
    }
};