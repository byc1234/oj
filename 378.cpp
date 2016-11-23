/*
378. Kth Smallest Element in a Sorted Matrix  QuestionEditorial Solution  My Submissions
Total Accepted: 552
Total Submissions: 1285
Difficulty: Medium
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0], right = matrix[n-1][n-1];
		int mid = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return le;
    }
};
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct mycomparison {
  vector<vector<int> > matrix;
  mycomparison(vector<vector<int> > m) {
     matrix = m;
  }
// A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
     return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
  }
};

int kthSmallest(vector<vector<int> >& matrix, int k) {
  mycomparison comp(matrix);
  priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> que(comp);
  que.push(make_pair(0,0));
  int count = 0;
  int n = matrix.size();
  while (true) {
    pair<int, int> p = que.top();
    que.pop();
cout << "p.first:" << p.first << ", p.second:" << p.second << endl;
    if (++count == k) {
       return matrix[p.first][p.second]; 
    }
    if (p.first == 0 && p.second + 1 < n) {
       que.push(make_pair(0, p.second+1)); 
cout << "1- p.first:" << p.first << ", p.second:" << p.second+1 << endl;
    }
    if (p.first + 1 < n) {
       que.push(make_pair(p.first+1, p.second)); 
cout << "2- p.first:" << p.first+1 << ", p.second:" << p.second << endl;
    }
  }
  pair<int, int> p = que.top();
  return matrix[p.first][p.second];
}

int kthSmallest2(vector<vector<int> >& matrix, int k) {
  int n = matrix.size();
  int left = matrix[0][0];
  int right = matrix[n-1][n-1];
  while (left < right) {
    int mid = (left + right) >> 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
       int countInRow = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
       count += countInRow;
    }
    if (count < k) {
       left = mid + 1;
    } else {
       right = mid;
    }
  }
  return left;
}

void printMatrix(vector<vector<int> >& matrix) {
  int n = matrix.size();
  mycomparison comp(matrix);
  priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> que(comp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
       que.push(make_pair(i,j));
    }
  }
  while (!que.empty()) {
     pair<int, int> p = que.top();
     que.pop();
cout << "p.first:" << p.first+1 << ", p.second:" << p.second << " val: " << matrix[p.first][p.second] << endl;
  } 
}

int main() {
  vector<vector<int> > matrix;
  vector<int> row1;
  row1.push_back(1);
  row1.push_back(5);
  row1.push_back(9);
  vector<int> row2;
  row2.push_back(10);
  row2.push_back(11);
  row2.push_back(13);
  vector<int> row3;
  row3.push_back(12);
  row3.push_back(13);
  row3.push_back(15);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);

  vector<vector<int> > matrix2;
  vector<int> m2row1;
  m2row1.push_back(1);
  m2row1.push_back(2);
  vector<int> m2row2;
  m2row2.push_back(3);
  m2row2.push_back(3);
  matrix2.push_back(m2row1);
  matrix2.push_back(m2row2);

printMatrix(matrix);
//  cout << kthSmallest2(matrix, 8) << endl;
//  cout << kthSmallest(matrix2, 2) << endl;
}

