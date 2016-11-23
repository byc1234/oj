/*
[LeetCode] Nested List Weight Sum 嵌套链表权重和
 

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

*/
#include <iostream>
#include <vector>

using namespace std;

struct NestedIterator {
  bool hasNext() {
    return !next.empty();
  }
  int val;
  vector<NestedIterator> next;
  NestedIterator(int v) : val(v) {}
};

int sumAll(vector<NestedIterator> & nested, int depth) {
  int sum = 0;
  for (NestedIterator iter : nested) {
     if (iter.hasNext()) sum += sumAll(iter.next, depth+1);
     else {
cout << "depth: " << depth << ", iter.val: " << iter.val << endl;
       sum += iter.val * depth;
     }
  }
  return sum;
}

int main() {
   vector<NestedIterator> nested;
   NestedIterator one(1);
   NestedIterator two(1);
   vector<NestedIterator> twoOnes;
   twoOnes.push_back(one);
   twoOnes.push_back(one);
   NestedIterator iter1(0);
   iter1.next = twoOnes;
   NestedIterator iter2(2);
   NestedIterator iter3(0);
   iter3.next = twoOnes;
   nested.push_back(iter1);
   nested.push_back(iter2);
   nested.push_back(iter3);
   cout << sumAll(nested, 1) << endl;
}
