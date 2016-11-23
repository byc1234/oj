#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *l, TreeNode *r) : left(l), right(r), val(x) {}
};

void print(TreeNode *node) {
  if (node == nullptr) return;
  cout << node->val << endl;
  print(node->left);
  print(node->right);
}

pair<bool, int> findLargestBSTSub(TreeNode *node, int minVal, int maxVal) {
  if (node == nullptr) {
     return make_pair(true, 0);
  }
  pair<bool, int> left = findLargestBSTSub(node->left, minVal, node->val);
  pair<bool, int> right = findLargestBSTSub(node->right, node->val, maxVal);
cout << "left.first: " << left.first
     << " right.first: " << right.first
     << " left.second: " << left.first
     << " right.second: " << right.second
     << " node->val: " << node->val
     << " minVal: " << minVal
     << " maxVal: " << maxVal
     << endl;
  if (left.first && right.first && node->val >= minVal && node->val <= maxVal) {
    return make_pair(true, left.second + right.second + 1); 
  } 
  return make_pair(false, max(left.second, right.second));
}

int main() {
  TreeNode *one = new TreeNode(1, nullptr, nullptr);
  TreeNode *eight = new TreeNode(8, nullptr, nullptr);
  TreeNode *seven = new TreeNode(7, nullptr, nullptr);
  TreeNode *five = new TreeNode(5, one, eight);
  TreeNode *fifteen = new TreeNode(15, nullptr, seven);
  TreeNode *ten = new TreeNode(10, five, fifteen);
  cout << "-------" << endl;
  cout << findLargestBSTSub(ten, INT_MIN, INT_MAX).second << endl;
}

