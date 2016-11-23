#include <vector>
#include <iostream>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> next;
    bool val;
    // Initialize your data structure here.
    TrieNode() {
       next = vector<TrieNode*>(26, nullptr);
       bool val = false;
    }
};

class Trie {
public:
    Trie() {
        root = nullptr;
    }

    // Inserts a word into the trie.
    void insert(TrieNode *&node, string word, int idx) {
        if (node == nullptr) node = new TrieNode();
        if (idx == word.length()) {
            node->val = true;
            return;
        }
        int nodeIdx = (int) (word[idx] - 'a');
        insert(node->next[nodeIdx], word, idx+1);
    }

    // Inserts a word into the trie.
    void insert(string word) {
        insert(root, word, 0);
    }

    bool search(TrieNode *&node, string word, int idx, bool prefix) {
        if (node == nullptr) return false;
        if (idx == word.length()) {
            if (prefix) return true;
            else return node->val;
        }
        int nodeIdx = (int) (word[idx] - 'a');
        return search(node->next[nodeIdx], word, idx+1, prefix);
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        return search(root, word, 0, false);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return search(root, prefix, 0, true);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
  Trie trie;
  trie.insert("app");
  trie.insert("apple");
  trie.insert("beer");
  trie.insert("add");
  trie.insert("jam");
  trie.insert("rental");
  cout << trie.search("apps") << endl;
  cout << trie.search("app") << endl;
  cout << trie.search("ad") << endl;
  cout << trie.search("applepie") << endl;
  cout << trie.search("rest") << endl;
  cout << trie.search("jan") << endl;
  cout << trie.search("rent") << endl;
  cout << trie.search("beer") << endl;
  cout << trie.search("jam") << endl;
  cout << trie.startsWith("apps") << endl;
  cout << trie.startsWith("app") << endl;
  cout << trie.startsWith("ad") << endl;
  cout << trie.startsWith("applepie") << endl;
  cout << trie.startsWith("rest") << endl;
  cout << trie.startsWith("jan") << endl;
  cout << trie.startsWith("rent") << endl;
  cout << trie.startsWith("beer") << endl;
  cout << trie.startsWith("jam") << endl;
}
