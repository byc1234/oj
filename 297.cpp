/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serialize(TreeNode *node, string &str) {
        if (node == nullptr) {
            str += " #";
            return;
        }
        ostringstream oss;
        oss << " " << node->val;
        str += oss.str();
        serialize(node->left, str);
        serialize(node->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        serialize(root, str);
        return str;
    }

    void deserialize(TreeNode *&node, deque<string> &tokens) {
        if (tokens.empty()) {
            return;
        }
        string token = tokens.front();
        tokens.pop_front();
        if (token == "#") {
            node = nullptr;
            return;
        }
        istringstream iss(token);
        int val;
        iss >> val;
        node = new TreeNode(val);
        deserialize(node->left, tokens);
        deserialize(node->right, tokens);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> tokens;
        istringstream iss(data);
        while (iss) {
            string token;
            iss >> token;
            tokens.push_back(token);
        }
        TreeNode *node;
        deserialize(node, tokens);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
