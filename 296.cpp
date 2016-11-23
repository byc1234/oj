/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

Hint:

Try to solve it in one dimension first. How can this solution apply to the two dimension case?

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int minTotalDistance(vector<vector<int> >& grid) {
  vector<int> ii, jj;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
       if (grid[i][j]) {
         ii.push_back(i);
         jj.push_back(j);
       } 
    }
  } 
  nth_element(ii.begin(), ii.begin() + ii.size()/2, ii.end());
  nth_element(jj.begin(), jj.begin() + jj.size()/2, jj.end());
  int sum = 0;
  int iMedian = ii[ii.size()/2];
  int jMedian = jj[jj.size()/2];
  for (int i : ii) sum += abs(i - iMedian);
  for (int j : jj) sum += abs(j - jMedian);
  return sum;
}

int main() {
  vector<vector<int> > grid(3, vector<int>(5, 0));
  grid[0][0] = 1;
  grid[0][4] = 1;
  grid[2][2] = 1;
  cout << minTotalDistance(grid) << endl;
}
