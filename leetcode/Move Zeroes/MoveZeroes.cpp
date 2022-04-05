class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // k表示第二个指针
        int k = 0;
        for (int i = 0; i < nums.size(); i ++) {
            // 当i位置的值不是零的时候，将i位置的值放到k指向的位置，然后k向后移动
            if (nums[i] != 0) {
                nums[k ++] = nums[i];
            }
        }
        // 在后边补上零
        while (k < nums.size()) nums[k ++] = 0;
    }
};