/*
216. Combination Sum III   My Submissions QuestionEditorial Solution
Total Accepted: 30439 Total Submissions: 85343 Difficulty: Medium
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

*/
class Solution {
public:
    void combinationSum3(int k, int target, int s, vector<int> path, vector<vector<int>> &res) {
        if (k < 0) return;
        if (k == 0) {
            if (target == 0) {
                res.push_back(path);
            }
            return;
        }
        if (target < s) return;
        
        for (int i = s; i < 10; i++) {
            path.push_back(i);
            combinationSum3(k-1, target-i, i+1, path, res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        combinationSum3(k, n, 1, path, res);
        return res;
    }
};
