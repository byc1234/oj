#include <iostream>
#include <vector>

using namespace std;

    void print(vector<int> &nums) { 
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
        cout << endl;
    } 

    int partition(vector<int>& nums, int si, int ei) {
        if (si == ei) return si;
        int pivot = ei;
        ei--;
        while (si <= ei) {
            if (nums[pivot] < nums[si]) {
                int tmp = nums[ei];
                nums[ei] = nums[si];
                nums[si] = tmp;
                ei--;
            } else {
                si++;
            }
        }
        int tmp = nums[pivot];
        nums[pivot] = nums[si];
        nums[si] = tmp;

        return si;
    }


    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        int si = 0;
        int ei = size - 1;
        int p = 0;
        while (true) {
            p = partition(nums, si, ei);
            if (p == size - k) break;
            else if (p < size - k) {
                si = p + 1;
            } else {
                ei = p - 1;
            }
        }

        return nums[p];

    }


int main() {
   //vector<int> nums{7, 6, 5, 4, 3, 2, 1};
   //cout << findKthLargest(nums, 5) << endl;
   vector<int> nums{3,1,2,4};
   cout << findKthLargest(nums, 2) << endl;
}
