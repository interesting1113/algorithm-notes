class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                // 如果栈顶元素的ASCII码和当前元素的ASCII码的差如果小于等于2，说明匹配
                if (stk.size() && abs(stk.top() - s[i]) <= 2) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};