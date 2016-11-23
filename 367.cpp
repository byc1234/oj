/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        long long left = 1;
        long long right = num;
        while (left <= right) {
            long long mid = left + (right-left)/2;
            long long candidate = mid*mid;
            if (candidate == num) return true;
            else if (candidate > num) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
