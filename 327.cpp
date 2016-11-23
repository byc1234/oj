/*
Thanks for those contributing excellent ideas to this problem. Here is a quick summary of solutions based on either divide and conquer or binary indexed tree.

To start, we already know there is a straightforward solution by computing each range sum and checking whether it lies in [lower, upper] or not. If the number of elements is n, we have n(n+1)/2 such range sums so the naive solution will end up with O(n^2) time complexity. Now we are asked to do better than that. So what are the targeted time complexities in your mind? When I first looked at the problem, my instinct is that O(n) solution is too ambitious, so I will target at linearithmic-like (O(n(logn)^b)) solutions. To get the logarithmic part, it's natural to think of breaking down the original array, and that's where the divide-and-conquer idea comes from.

For this problem, we need some array to apply our divide and conquer algorithm. Without much thinking, we can do that directly with the input array (nums) itself. Since our problem also involves range sums and I believe you have the experience of computing range sums from prefix array of the input array, we might as well apply divide and conquer ideas on the prefix array. So I will give both the input-array based and prefix-array based divide&conquer solutions.

Let's first look at input-array based divide&conquer solution. Our original problem is like this: given an input array nums with length n and a range [lower, upper], find the total number of range sums that lie in the given range. Note the range [lower, upper] and the input array are both fixed. Therefore each range sum can be characterized by two indices i1 and i2 (i1 <= i2), such that range sum S(i1, i2) is the summation of input elements with indices going from i1 up to i2 (both inclusive). Then our problem can be redefined in terms of the value ranges of i1 and i2. For example our original problem can be restated as finding the total number of range sums lying in the given range with 0 <= i1 <= i2 <= n - 1, or in a symbolic way T(0, n-1).

Now if we break our original input array into two subarrays, [0, m] and [m+1, n-1] with m = (n-1)/2, our original problem can be divided into three parts, depending on the values of i1 and i2. If i1 and i2 are both from the first subarray [0, m], we have a subproblem T(0, m); if i1 and i2 are both from the second subarray, we have a subproblem T(m+1, n-1); if i1 is from the first subarray and i2 from the second (note we assume i1 <= i2, therefore we don't have the other case with i2 from first subarray and i1 from second), then we have a new problem which I define as C. In summary we should have:

T(0, n-1) = T(0, m) + T(m+1, n-1) + C

Now from the master theorem, the time complexity of the new problem C should be better than O(n^2), otherwise we make no improvement by applying this divide&conquer idea. So again, I will aim at linearithmic-like solutions for the new problem C: find the total number of range sums lying in the given range with each range sum starting from the first subarray and ending at the second subarray.

First let's try to compute all such range sums. The way I did it was first computing the prefix array of the second subarray and the suffix array (or "backward" prefix array if you like) of the first subarray. Then I can naively add each element in the suffix array to all elements in the prefix array to obtain all the possible range sums. Of course you end up with O(n^2) solution, as expected. So how can we approach it with better time complexity?

Here are the facts I observed: for each element e in the suffix array, we need to add it to all elements in the prefix array. But the order in which we add it doesn't matter. This implies that we can sort our prefix array. This can be done in O(nlogn) time. Now we have a sorted prefix array, do we still need to add the element e to all elements in the prefix array? The answer is no. Because our final goal is to compare the resulted range sums with the given range bounds lower and upper. It is equivalent to modifying the range bounds so we have new bounds (lower - e) and (upper - e) and leave the prefix array unchanged. Now we can compare these new bounds with the sorted prefix array, and I'm sure you can write your own binary search algorithm to do that. So for each element e in the suffix array, we can compute the modified range bounds and get the number of range sums in this new range in logn time. Therefore the total time will be O(nlogn). So in summary, our new problem C can be solved in O(nlogn) time and according to the master theorem, our original problem can be solved in O(n(logn)^2) time. The following is the complete java program:
*/

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty() || lower > upper) {
            return 0;
        }
    
        return countRangeSumSub(nums, 0, nums.size() - 1, lower, upper);
    }
    
    int countRangeSumSub(vector<int>& nums, int l, int r, int lower, int upper) {
        if (l == r) {
            return nums[l] >= lower && nums[r] <= upper ? 1 : 0;  // base case
        }
    
        int m = l + (r - l) / 2;
        vector<long> arr(r-m, 0);  // prefix array for the second subarray
        long sum = 0;
        int count = 0;
    
        for (int i = m + 1; i <= r; i++) {
            sum += nums[i];
            arr[i - (m + 1)] = sum; // compute the prefix array
        }
    
        sort(arr.begin(), arr.end());  // sort the prefix array
    
        // Here we can compute the suffix array element by element.
        // For each element in the suffix array, we compute the corresponding
        // "insertion" indices of the modified bounds in the sorted prefix array
        // then the number of valid ranges sums will be given by the indices difference.
        // I modified the bounds to be "double" to avoid duplicate elements.
        sum = 0;
        for (int i = m; i >= l; i--) {
            sum += nums[i];  
            count += findIndex(arr, upper - sum + 0.5) - findIndex(arr, lower - sum - 0.5);
        }
    
        return countRangeSumSub(nums, l, m, lower, upper) + countRangeSumSub(nums, m + 1, r, lower, upper) + count;
    }
    
    // binary search function
    int findIndex(vector<long> &arr, double val) {
        int l = 0, r = arr.size() - 1, m = 0;
    
        while (l <= r) {
            m = l + (r - l) / 2;
    
            if (arr[m] <= val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    
        return l;
    }

