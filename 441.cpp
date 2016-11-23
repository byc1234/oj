class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0) return 0;
        long left = 0;
        long right = n;
        while (left <= right) {
            long mid = left + (right-left)/2;
            long v = mid*(mid+1)/2;
            if (v <= n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};
