/*
214. Shortest Palindrome   My Submissions QuestionEditorial Solution
Total Accepted: 18975 Total Submissions: 96097 Difficulty: Hard
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".


We can construct the following string and run KMP algorithm on it: (s) + (some symbol not present in s) + (reversed string)

After running KMP on that string as result we get a vector p with values of a prefix function for each character (for definition of a prefix function see KMP algorithm description). We are only interested in the last value because it shows us the largest suffix of the reversed string that matches the prefix of the original string. So basically all we left to do is to add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.

*/
#include <iostream>
#include <vector>

using namespace std;


    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;

cout << "l: " << l << endl;
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j])
                j = p[j - 1];
            p[i] = (j += l[i] == l[j]);
cout << "i: " << i << ", j: " << j << " ";
for (int ip : p) cout << ip; cout << endl;
        }

        return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
    }

int main() {
  cout << shortestPalindrome("abcd") << endl;
  cout << shortestPalindrome("aacecaaa") << endl;
  cout << shortestPalindrome("abcabcd") << endl;
}
