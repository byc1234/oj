/*
[LeetCode] Flatten Nested List Iterator
 

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct NestedInteger {
  int val;
  vector<NestedInteger> elements;
  NestedInteger(int v) : val(v) {}
};

struct NestedIterator {
  NestedIterator(vector<NestedInteger> &ints) {
     for (int i = ints.size() - 1; i >= 0; i--) {
        stk.push(ints[i]);
     }
  }
  bool hasNext() {
     while (!stk.empty()) {
       NestedInteger ni = stk.top();
cout << "ni: " << ni.val << endl;
       if (ni.elements.empty()) return true;
       stk.pop();
       for (int i = ni.elements.size()-1; i >= 0; i--) {
         stk.push(ni.elements[i]);
       } 
     }
     return false;
  }
  int next() {
     NestedInteger i = stk.top(); stk.pop();
     return i.val;
  }
  stack<NestedInteger> stk;
};

int main() {
  NestedInteger one(1);
  NestedInteger two(2);
  NestedInteger twoOnes(0);
  twoOnes.elements.push_back(one);
  twoOnes.elements.push_back(one);
  vector<NestedInteger> nestInts;
  nestInts.push_back(twoOnes);
  nestInts.push_back(two);
  nestInts.push_back(twoOnes);
  NestedIterator iter(nestInts);
  while (iter.hasNext()) {
    cout << iter.next() << endl;
  }
}


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    stack<NestedInteger> stk;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int i = nestedList.size() - 1;
        for (; i >= 0; i--) stk.push(nestedList[i]);
    }

    int next() {
        NestedInteger ni = stk.top(); stk.pop();
        return ni.getInteger();
    }

    bool hasNext() {
        if (stk.empty()) return false;
        while (!stk.empty()) {
            NestedInteger ni = stk.top();
            if (ni.isInteger()) return true;
            stk.pop();
            auto nil = ni.getList();
            if (!nil.empty()) {
                int i = nil.size() - 1;
                for (; i >=0; i--) stk.push(nil[i]);
            }
        }
        return !stk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
