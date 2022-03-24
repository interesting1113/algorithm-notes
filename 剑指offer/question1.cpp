// 找出数组中重复的数字

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (nums[i] < 0 || nums[i] >= n) return -1;
        }
        for (int i = 0; i < n; i ++) {
            while (i != nums[i] && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
        if (nums[i] != i && nums[nums[i]] == nums[i]) return nums[i];
        }
        return -1;
    }
};