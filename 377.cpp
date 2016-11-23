/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        int sum = 0;
        for (auto num : nums) {
            sum += combinationSum4(nums, target - num);
        }
        return sum;
    }


*/

#include <iostream>
#include <vector>

using namespace std;

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i >= num) {
cout << "i:" << i << ", num:" << num << ", dp[i]:" << dp[i] << ", dp[i-num]: " << dp[i-num] << endl;
                   dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  cout << combinationSum4(nums, 4) << endl;
}
