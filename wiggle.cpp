#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wiggle(vector<int> &nums) {
  int n = nums.size();
  nth_element(nums.begin(), nums.begin()+n/2, nums.end());
  int median = nums[n/2];
  int s = 0;
  int e = nums.size() - 1;
  vector<int> temp(nums.size(), 0);
  while (s < e) {
    if (nums[i] < median) temp[i++] = nums[i];  
    else temp[j--] = nums[i];
  }
  while (s <= n/2) nums[s++] = median; 
  while (e > n/2) nums[e--] = median; 
  int mid = 
  int last = nums.size();
  for (int i = 0; i < nums.size(); i++) {
    if (i % 2 == 0) {
      temp[i] = nums[--mid];
    } else {
      temp[i] = nums[--last];
    }
  }
  swap(nums, temp);
}

int main() {
  int arr[] = { 1, 6, 3, 4, 2, 5 };
  vector<int> vi(arr, arr + 6);
  for (int i : vi) cout << i;
  cout << endl;
  wiggle(vi);
  for (int i : vi) cout << i;
  cout << endl;
}
