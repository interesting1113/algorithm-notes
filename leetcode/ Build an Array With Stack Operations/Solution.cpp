class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int end = target[target.size() - 1];
        vector<string> res;
        int idx = 0;
        for (int i = 1; i <= end; i ++) {
            if (i != target[idx]) {
                res.push_back("Push");
                res.push_back("Pop");
            } else {
                res.push_back("Push");
                idx ++;
            }
        }

        return res;
    }
};