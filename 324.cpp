/*

leetcode Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?


Explanation

First I find a median using nth_element. That only guarantees O(n) average time complexity and I don't know about space complexity. I might write this myself using O(n) time and O(1) space, but that's not what I want to show here.

This post is about what comes after that. We can use three-way partitioning to arrange the numbers so that those larger than the median come first, then those equal to the median come next, and then those smaller than the median come last.

Ordinarily, you'd then use one more phase to bring the numbers to their final positions to reach the overall wiggle-property. But I don't know a nice O(1) space way for this. Instead, I embed this right into the partitioning algorithm. That algorithm simply works with indexes 0 to n-1 as usual, but sneaky as I am, I rewire those indexes where I want the numbers to actually end up. The partitioning-algorithm doesn't even know that I'm doing that, it just works like normal (it just uses A(x) instead of nums[x]).

Let's say nums is [10,11,...,19]. Then after nth_element and ordinary partitioning, we might have this (15 is my median):

index:     0  1  2  3   4   5  6  7  8  9
number:   18 17 19 16  15  11 14 10 13 12
I rewire it so that the first spot has index 5, the second spot has index 0, etc, so that I might get this instead:

index:     5  0  6  1  7  2  8  3  9  4
number:   11 18 14 17 10 19 13 16 12 15
And 11 18 14 17 10 19 13 16 12 15 is perfectly wiggly. And the whole partitioning-to-wiggly-arrangement (everything after finding the median) only takes O(n) time and O(1) space.

If the above description is unclear, maybe this explicit listing helps:

Accessing A(0) actually accesses nums[1].
Accessing A(1) actually accesses nums[3].
Accessing A(2) actually accesses nums[5].
Accessing A(3) actually accesses nums[7].
Accessing A(4) actually accesses nums[9].
Accessing A(5) actually accesses nums[0].
Accessing A(6) actually accesses nums[2].
Accessing A(7) actually accesses nums[4].
Accessing A(8) actually accesses nums[6].
Accessing A(9) actually accesses nums[8].

Props to apolloydy's solution, I knew the partitioning algorithm already but I didn't know the name. And apolloydy's idea to partition to reverse order happened to make the index rewiring simpler.
*/

#include <vector>
#include <iostream>

using namespace std;

void wiggleSort(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}

void wiggleSort2(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums.size(), 0);
        int s = (nums.size() + 1) >> 1; 
        int t = nums.size();
cout << "s:" << s  << endl;
        for (int i = 0; i < nums.size(); i++) {
            temp[i] = (i & 1) == 0 ?  nums[--s] : nums[--t] ;
        }

        for (int i = 0; i < nums.size(); i++)
            nums[i] = temp[i];
    }

void wiggleSort3(vector<int> & nums) {
        vector<int> temp = nums;
        nth_element(temp.begin(), temp.begin() + nums.size()/2, temp.end());
for (int i : temp) cout << i << endl;
cout << "ljkasdjkfkasdjfl" << endl;
        int mid_index = (temp.size() + 1) >> 1;
        int medium = temp[mid_index];
        int s = 0;
        int t = temp.size() - 1;
/*
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < medium)
                temp[s++] = nums[i];
            else if (nums[i] > medium)
                temp[t--] = nums[i];
        }
 
        while (s < mid_index) temp[s++] = medium;
        while (t >= mid_index) temp[t--] = medium;
 
*/
        t = nums.size();
        for (int i = 0; i < nums.size(); i++)
            nums[i] = (i & 1) == 0 ? temp[--s] : temp[--t];
    }
 
int main() {
//(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
//(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//  int arr[] = {1, 5, 1, 1, 6, 4}; 
  int arr[] = {1, 2, 3, 4, 5, 6}; 
  vector<int> vec(arr, arr+6);
  wiggleSort3(vec);
  for (int i : vec) cout << i << endl;

cout << "---------" << endl;
/*
  vector<int> vec2(arr, arr+6);
  wiggleSort2(vec2);
  for (int i : vec2) cout << i;
  cout << endl;
*/
}
/*
public class Solution {
    public void wiggleSort(int[] nums) {
        Arrays.sort(nums);
        int[] temp = new int[nums.length];
        int s = (nums.length + 1) >> 1, t = nums.length;
        for (int i = 0; i < nums.length; i++) {
            temp[i] = (i & 1) == 0 ?  nums[--s] : nums[--t] ;
        }

        for (int i = 0; i < nums.length; i++)
            nums[i] = temp[i];
    }
}

        int medium = findMedium(nums, 0, nums.length - 1, (nums.length + 1) >> 1);
        int s = 0, t = nums.length - 1 , mid_index = (nums.length + 1) >> 1;
        int[] temp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < medium)
                temp[s++] = nums[i];
            else if (nums[i] > medium)
                temp[t--] = nums[i];
        }

        while (s < mid_index) temp[s++] = medium;
        while (t >= mid_index) temp[t--] = medium;

        t = nums.length;
        for (int i = 0; i < nums.length; i++)
            nums[i] = (i & 1) == 0 ? temp[--s] : temp[--t];
   
*/
