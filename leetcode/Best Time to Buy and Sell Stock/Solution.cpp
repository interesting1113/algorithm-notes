class Solution {
public:
    int res = 0;
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i ++) {
            res = max(res, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return res;
    }
};