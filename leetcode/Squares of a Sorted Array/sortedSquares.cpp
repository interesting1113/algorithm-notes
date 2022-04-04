class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i = 0, j = n - 1, k = n - 1;
        while (i <= j) {
            // 因为平方后不一定有序，所以直接比较交换
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k] = nums[i] * nums[i];
                i ++, k --;
            } else {
                res[k] = nums[j] * nums[j];
                j --, k --;
            }
        }
        return res;
    }
};