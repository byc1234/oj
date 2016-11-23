/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]
 

If there is no valid move, return an empty list [].
*/
#include <iostream>
#include <vector>

using namespace std;

// reuse existing one instead of creating a new one all the time
// for example, str = s and updating str is easy, but try to reuse s.
vector<string> generatePossibleNextMoves(string s) {
  vector<string> ans;
  for (int i = 1; i < s.size(); i++) {
     if (s[i-1] == '+' && s[i] == '+') {
       s[i-1] = '-';
       s[i] = '-';
       ans.push_back(str);
       s[i-1] = '+';
       s[i] = '+';
     }
  }
  return ans;
}

int main() {
  string str = "++++";
  for (string s : generatePossibleNextMoves(str)) {
    cout << s << endl;
  }
}
