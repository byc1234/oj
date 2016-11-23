#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, vector<int> &buf, int left, int mid, int right) {
  if (left >= right) return;
  for (int i = left; i <= right; i++) buf[i] = nums[i];
  int i = left; 
  int i1 = left;
  int i2 = mid+1;
  while (i1 <= mid && i2 <= right) {
     if (buf[i1] <= buf[i2]) nums[i++] = buf[i1++];
     else nums[i++] = buf[i2++]; 
  }
  while (i1 <= mid) nums[i++] = buf[i1++];
  while (i2 <= right) nums[i++] = buf[i2++];
}

void mergeSort(vector<int> &nums, vector<int> &buf, int left, int right) {
  if (left >= right) return;
  int mid = left + (right-left)/2;
  mergeSort(nums, buf, left, mid);
  mergeSort(nums, buf, mid+1, right);
  merge(nums, buf, left, mid, right); 
}

int main() {
  vector<int> nums;
  for (int i = 0; i < 10; i++) nums.push_back(rand() % 100);
  for (auto n : nums) cout << n << " ";
  cout << endl;
  vector<int> buf(nums.size(), 0);
  mergeSort(nums, buf, 0, nums.size() - 1);
  for (auto n : nums) cout << n << " ";
  cout << endl;
}
