class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l < r) {
            int mid = l + 1ll + r >> 1;
            // //使用除法防止平方之后溢出
            if (mid <= num / mid) l = mid;
            else r = mid - 1;
        }

        return r * r == num;
    }
};