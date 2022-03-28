// 斐波那契数列
class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1) return n;

        int first = 0, second = 1;
        for (int i = 0; i < n; i ++){

            int sum = first + second;
            first = second;
            second = sum;
        }
        return first;
    }
};