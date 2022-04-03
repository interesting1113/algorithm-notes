class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            // l + r 逐步操作可能会导致int溢出
            // int mid = (long long)l + r >> 1;
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == target) return r;
        return -1;
    }
};