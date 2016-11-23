#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int arr[] = {1, 4, 3, 4, 5, 6, 7, 4 };
  vector<int> vec(arr, arr+8);
  int n = vec.size();
  nth_element(vec.begin(), vec.begin() + n/2, vec.end());
  int s = vec.size()/2;
  int l = n;
  for (int i : vec) cout << i <<  endl;
  vector<int> res(n, 0);
  for (int i = 0; i < n; i++) {
    res[i] = (i % 2 == 0) ? vec[--s] : vec[--l];
  }
  cout << "====================" << endl;
  for (int i : res) cout << i <<  endl;
}
