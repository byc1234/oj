/*
212. Word Search II   My Submissions QuestionEditorial Solution
Total Accepted: 19430 Total Submissions: 99318 Difficulty: Hard
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.


*/
#include <iostream>
#include <vector>

using namespace std;


    struct TrieNode {
        vector<TrieNode*> next;
        string word;
        TrieNode() {
            next = vector<TrieNode*>(26,0);
        }
    };
    
    void dfs(vector<vector<char> >& board, int i, int j, TrieNode* p, vector<string> res) {
        char c = board[i][j];
        if(c == '#' || p->next[c - 'a'] == nullptr) return;
        p = p->next[c - 'a'];
        if (!p->word.empty()) {   // found one
            res.push_back(p->word);
            p->word = "";     // de-duplicate
        }
    
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j ,p, res); 
        if(j > 0) dfs(board, i, j - 1, p, res);
        if(i < board.size() - 1) dfs(board, i + 1, j, p, res); 
        if(j < board[0].size() - 1) dfs(board, i, j + 1, p, res); 
        board[i][j] = c;
    }

     TrieNode* buildTrie(vector<string> words) {
        TrieNode* root = new TrieNode();
        for(string w : words) {
            TrieNode* p = root;
            for(char c : w) {
                int i = c - 'a';
                if(p->next[i] == nullptr) p->next[i] = new TrieNode();
                p = p->next[i];
           }
           p->word = w;
        }
        return root;
    }


    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

int main() {
 vector<char> row1;
 row1.push_back('o');
 row1.push_back('a');
 row1.push_back('a');
 row1.push_back('n');
 vector<char> row2;
 row2.push_back('e');
 row2.push_back('t');
 row2.push_back('a');
 row2.push_back('e');
 vector<char> row3;
 row3.push_back('i');
 row3.push_back('h');
 row3.push_back('k');
 row3.push_back('r');
 vector<char> row4;
 row4.push_back('i');
 row4.push_back('f');
 row4.push_back('l');
 row4.push_back('v');
 vector<vector<char> > board;
 board.push_back(row1);
 board.push_back(row2);
 board.push_back(row3);
 board.push_back(row4);
 vector<string> words;
 words.push_back("oath");
 words.push_back("pea");
 words.push_back("eat");
 words.push_back("rain");
 for (auto w : findWords(board, words)) cout << w << endl;
}
