/*
Given the string s, the greedy choice (i.e., the leftmost letter in the answer) is the smallest s[i], s.t. the suffix s[i .. ] contains all the unique letters. (Note that, when there are more than one smallest s[i]'s, we choose the leftmost one. Why? Simply consider the example: "abcacb".)

After determining the greedy choice s[i], we get a new string s' from s by

removing all letters to the left of s[i],
removing all s[i]'s from s.
We then recursively solve the problem w.r.t. s'.

The runtime is O(26 * n) = O(n).
*/
#include <iostream>
#include <vector>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> cand(256, 0);
    vector<bool> visited(256, false);
    for (char c : s)
        cand[c]++;
    string result = "0";
    for (char c : s) {
        cand[c]--;
        if (visited[c]) continue;
        while (c < result.back() && cand[result.back()]) {
cout << "c: " << c << ", result.back() : " << result.back() << endl;
            visited[result.back()] = false;
            result.pop_back();
        }
        result += c;
        visited[c] = true;
    }
    return result.substr(1);
}

int main() {
   string str = "bcabc";
   cout << removeDuplicateLetters(str) << endl;
}
