/*
Leetcode: Maximum Size Subarray Sum Equals k

Question :
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int maxSizeSubarraySum(vector<int> nums, int k) {
  if (nums.empty()) return 0;
  unordered_map<int, int> ht;
  ht[0] = -1;
  int n = nums.size();
  int sum = 0;
  int maxLen = INT_MIN;
  for (int i = 0; i < n; i++) {
    sum += nums[i]; 
    if (ht.find(sum) == ht.end()) {
cout << "add: sum = " << sum << " i = " << i << endl;
      ht[sum] = i;
    }
    if (ht.find(sum - k) != ht.end()) {
cout << sum - k << " " << ht[sum-k] << endl;
      maxLen = max(maxLen, i - ht[sum-k]);
    }
  }
  return (maxLen == INT_MIN) ? 0 : maxLen;
}

int main() {
   vector<int> nums;
   nums.push_back(1);
   nums.push_back(-1);
   nums.push_back(5);
   nums.push_back(-2);
   nums.push_back(3);
//   vector<int> nums{1, -1, 5, -2, 3};
//   vector<int> nums{-2, -1, 2, 1};
   cout << maxSizeSubarraySum(nums, 3) << endl;
//   cout << maxSizeSubarraySum(nums, 1) << endl;
}
