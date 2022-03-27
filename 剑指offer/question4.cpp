// 替换空格
class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for (auto x: str) {
            if (x == ' ') res += "%20";
            else res += x;
        }
        return res;
    }
};