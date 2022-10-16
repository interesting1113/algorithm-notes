class Solution {
public:
    int s[256];
    bool isUnique(string astr) {
       
        for (int i = 0; i < astr.size(); i ++) {
            if (s[astr[i] - 0] != 0) return false;
            s[astr[i] - 0] ++;
        }

        return true;

    }
};
