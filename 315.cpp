
/*
MergeSort-based solution is a standard way to solve problems related to inverse numbers.

Here is an example to illustrate the general idea of MergeSort-based algorithm:

Now we want to consider an array

            6 4 1 8 7 5 2 9
First thing first, split the array into to subarrays:

            6 4 1 8
            7 5 2 9
and then calculate the inverse numbers within the group:

                  1 4(1) 6(1,4) 8
                  2 5(2) 7(2,5) 9
where the numbers in the parentheses are the numbers that should be counted when we calculate the inverse number. Now we need to merge these two arrays into one sorted array. The first element to be put into the sorted destination array is the "1" in the first array.

 1                  4(1) 6(1,4) 8
                  2 5(2) 7(2,5) 9               merged elements in the 2nd array = ()
The second element to merge is the "2" in the second array:

 1 2                4(1) 6(1,4) 8
                    5(2) 7(2,5) 9               merged elements in the 2nd array = (2)
The third element to merge is the "4" in the first array:

 1 2 4(1,2)              6(1,4) 8
                    5(2) 7(2,5) 9               merged elements in the 2nd array = (2)
When we merge the "4(1)", we found that "4" is actually greater than all merged elements in the second array (i.e. [2]). Therefore, we also need to consider those elements. Therefore, the numbers in the parenthese of 2 become (1)+(2) = (1,2). Next step:

 1 2 4(1,2) 5(2)         6(1,4) 8
                         7(2,5) 9               merged elements in the 2nd array = (2,5)
Next (add the inverse number of element "6" by 2)

 1 2 4(1,2) 5(2) 6(1,4,2,5)     8
                         7(2,5) 9               merged elements in the 2nd array = (2,5)
So and so forth, finally reach

 1 2 4(1,2) 5(2) 6(1,4,2,5) 7(2,5) 8(2,5,7) 9
                                                merged elements in the 2nd array = (2,5,7,9)
Additionally, when we need to count the inverse number, we do not need to record the exact elements, we only need to record the numbers. So, we can use a variable to record the number of "merged elements in the 2nd array" (for example, semilen in the code beneath) and the number of smaller elements of each element (for example, results[idx] in the code beneath).

-

Complexities:

Time: O(n log n)

Space: O(n)

-
*/
    void merge_countSmaller(vector<int>& indices, int first, int last, 
                            vector<int>& results, vector<int>& nums) {
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);
            vector<int> tmp;
            tmp.reserve(count);
            int idx1 = first;
            int idx2 = mid;
            int semicount = 0;
            while ((idx1 < mid) || (idx2 < last)) {
                if ((idx2 == last) || ((idx1 < mid) &&
                       (nums[indices[idx1]] <= nums[indices[idx2]]))) {
                    tmp.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                } else {
                    tmp.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp.begin(), tmp.end(), indices.begin()+first);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n, 0);
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }

