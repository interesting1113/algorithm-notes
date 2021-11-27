class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end()); //反转整个数组
        reverse(nums.begin(), nums.begin() + k);// 分界点左边翻转，注意右边界是不包含begin()+k这个点的
        reverse(nums.begin() + k, nums.end());////分界点右边翻转
    }
};