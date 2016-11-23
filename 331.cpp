/*
Some used stack. Some used the depth of a stack. Here I use a different perspective. In a binary tree, if we consider null as leaves, then

all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree. When the next node comes, we then decrease diff by 1, because the node provides an in degree. If the node is not null, we increase diff by 2, because it provides two out degrees. If a serialization is correct, diff should never be negative and diff will be zero when finished.

*/
    bool isValidSerialization(string preorder) {
        istringstream ss(input);
        string token;
        vector<string> tokens;

        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        int diff = 1;
        for (string node: tokens) {
            if (--diff < 0) return false;
            if (node != "#") diff += 2;
        }
        return diff == 0;
    }

