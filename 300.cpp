#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS2(vector<int> & nums) {
  int n = nums.size();
  vector<int> dp(n, 1);
  int res = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
       if (nums[j] < nums[i]) {
         dp[i] = max(dp[i], dp[j]+1);
       }
    }
    res = max(res, dp[i]);
  }
  for (auto n : dp) cout << "dp:" << n << endl;
  return res;
}

int lengthOfLIS(vector<int> &nums) {
  vector<int> res;
  for (auto n : nums) {
    auto itr = lower_bound(res.begin(), res.end(), n);
    if (itr == res.end()) {
     res.push_back(n);
    }
    else {
     *itr = n;
    }
  }
  for (auto n : res) cout << "res:" << n << endl;
  return res.size();
}

int main() {
  vector<int> nums;
  nums.push_back(10);
  nums.push_back(9);
  nums.push_back(2);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(7);
  nums.push_back(101);
  nums.push_back(18);
  cout << lengthOfLIS(nums) << endl;
  cout << lengthOfLIS2(nums) << endl;
}
