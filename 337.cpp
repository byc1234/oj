/*
leetcode House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the “root.” Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that “all houses in this place forms a binary tree”. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:


     3
    / \
   2   3
    \   \ 
     3   1

     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:


     3
    / \
   4   5
  / \   \ 
 1   3   1

     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.



*/
    pair<int, int> getSumFromChild(TreeNode *node) {
        if (node == nullptr) {
            return make_pair(0, 0);
        }
        /*
f1(node) be the value of maximum money we can rob from the subtree with node as root ( we can rob node if necessary).
f2(node) be the value of maximum money we can rob from the subtree with node as root but without robbing node.

Then we have
f2(node) = f1(node.left) + f1(node.right) and
f1(node) = max( f2(node.left)+f2(node.right)+node.value, f2(node) ).
        */
        auto l = getSumFromChild(node->left);
        auto r = getSumFromChild(node->right);
        int f2 = l.second + r.second;
        int f1 = max(l.first + r.first + node->val, f2);
        return make_pair(f2, f1);
    }
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        return getSumFromChild(root).second;
    }

