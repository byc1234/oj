/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int, int> diameters(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        pair<int, int> left = diameters(root->left);
        pair<int, int> right = diameters(root->right);
        return make_pair(max(left.first, right.first) + 1, max(left.first + right.first + 1, max(left.second, right.second)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        pair<int, int> diameter = diameters(root);
        return max(diameter.first, diameter.second) - 1;
    }
};

