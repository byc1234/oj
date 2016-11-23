/*
363. Max Sum of Rectangle No Larger Than K My Submissions QuestionEditorial Solution
Total Accepted: 319 Total Submissions: 1369 Difficulty: Hard
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Credits:


The naive solution is brute-force, which is O((mn)^2). In order to be more efficient, I tried something similar to Kadane's algorithm. The only difference is that here we have upper bound restriction K. Here's the easily understanding video link for the problem "find the max sum rectangle in 2D array": Maximum Sum Rectangular Submatrix in Matrix dynamic programming/2D kadane (Trust me, it's really easy and straightforward).

Once you are clear how to solve the above problem, the next step is to find the max sum no more than K in an array. This can be done within O(nlogn), and you can refer to this article: max subarray sum no more than k.

For the solution below, I assume that the number of rows is larger than the number of columns. Thus in general time complexity is O[min(m,n)^2 * max(m,n) * log(max(m,n))], space O(max(m, n)).

*/

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }

            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}


class Solution {
public:
// https://www.youtube.com/watch?v=yCQN096CwWM
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = INT_MIN;
        for (int left = 0; left < col; left++) {
            vector<int> sums(row, 0); // Reset by Kadane
            for (int right = left; right < col; right++) {
                for (int i = 0; i < row; i++) {
                    sums[i] += matrix[i][right];
                }

// https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
                int curMax = INT_MIN;
                set<int> accuSum;
                accuSum.insert(0);
                int curSum = 0;
                for (auto sum : sums) {
                    curSum += sum;
//  "No larger than K" ,which means it can be equal. Using lower_bound gives the possbility of having the equal case included.
                    auto it = accuSum.lower_bound(curSum - k);
                    if (it != accuSum.end()) curMax = max(curMax, curSum - *it);
                    accuSum.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};
