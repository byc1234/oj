#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
   int tmp = nums[i];
   nums[i] = nums[j];
   nums[j] = tmp;
}

int partition(vector<int>& nums, int left, int right) {
   int i = left;
   int j = right + 1;
   while (true) {
      while (nums[++i] < nums[left]) {
         if (i == right) break;
      }
      while (nums[left] < nums[--j]) {
         if (j == left) break;
      }
      if (i >= j) break;
      swap(nums, i, j);
   }
   swap(nums, left, j);
   return j;
}

void quick(vector<int> &nums, int left, int right) {
   if (left >= right) return;
   int p = partition(nums, left, right);
   quick(nums, left, p-1);
   quick(nums, p+1, right);
}

int main() {
   vector<int> nums;
   for (int i = 0; i < 10; i++) {
      nums.push_back(rand());
   }
   for (auto n : nums) cout << n << " ";
   cout << endl;

   quick(nums, 0, nums.size()-1);
   
   for (auto n : nums) cout << n << " ";
   cout << endl;
}
