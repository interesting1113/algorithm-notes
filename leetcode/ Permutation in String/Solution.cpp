class Solution {
public:
    unordered_map<char, int> S1, S2;

    bool check(char c) {
        if (S1.count(c) && S1[c] == S2[c]) {
            return true;
        }
        return false;
    }

    bool checkInclusion(string s1, string s2) {
        for (int i = 0; i < s1.size(); i ++) S1[s1[i]] ++;
        for (int i = 0, j = 0, cnt = 0; i < s2.size(); i ++) {
            if (check(s2[i])) cnt --;
            S2[s2[i]] ++;

            if (check(s2[i])) cnt ++;

            if (i - j >= s1.size()) {
                if (check(s2[j])) cnt --;
                S2[s2[j]] --;

                if (check(s2[j])) cnt ++;
                j ++;
            }
            if (cnt == S1.size()) return true;
        }
        return false;
    }
};

