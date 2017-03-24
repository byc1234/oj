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

    void traverse(TreeNode *node, int &val) {

        if (node == nullptr) return;

        traverse(node->right, val);

        val += node->val;

        node->val = val;

        traverse(node->left, val);

    }

    TreeNode* convertBST(TreeNode* root) {

        TreeNode *ans = root;

        int val = 0;

        traverse(ans, val);

        return ans;

    }

};
