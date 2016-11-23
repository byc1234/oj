#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
   vector<int> nums;
   nums.push_back(10);
   nums.push_back(20);
   nums.push_back(30);
   auto itr = lower_bound(nums.begin(), nums.end(), 1);
   cout << *itr  << endl;
}
