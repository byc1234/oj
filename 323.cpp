/*
323: Number of Connected Components in an Undirected Graph 

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
#include <iostream>
#include <vector>

using namespace std;

int numOfConn(int n, vector<pair<int, int> >& conn) {
  vector<int> nums(n, 0);
  int cnt = 1;
  for (pair<int, int> c : conn) {
     int cur = c.first;
     int next = c.second;
     nums[cur] = next; 
  }
}

int main() {
  vector<pair<int, int> > conn;
  conn.push_back(make_pair(0,1));
  conn.push_back(make_pair(1,2));
  conn.push_back(make_pair(3,4));
  cout << numOfConn(5, conn) << endl;
  vector<pair<int, int> > conn1;
  conn1.push_back(make_pair(0,1));
  conn1.push_back(make_pair(1,2));
  conn1.push_back(make_pair(2,3));
  conn1.push_back(make_pair(3,4));
  cout << numOfConn(5, conn1) << endl;
}
