class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (abs(nums[i] + nums[l] + nums[r] - target) < abs(ans - target)) {
                    ans = nums[i] + nums[l] + nums[r];
                }

                if (nums[i] + nums[l] + nums[r] == target) {
                    return target;
                } else if (nums[i] + nums[l] + nums[r] < target) {
                    l ++;
                } else {
                    r --;
                }
            }
        }

        return ans;
    }
};