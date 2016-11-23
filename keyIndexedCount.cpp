#include <iostream>
#include <vector>

using namespace std;

void sort(vector<char> &input, vector<char> &output, int R) {
  vector<int> count(R+1, 0);
  for (auto c : input) {
    count[c+1]++;
  }
  for (int i = 0; i < R; i++) {
    count[i+1] += count[i];
  }
  for (int i = 0; i < input.size(); i++) {
    output[count[input[i]]++] = input[i];
  }
}

int main() {
  string word = "dacffbdbfbea";
  vector<char> vs(word.begin(), word.end());  
  vector<char> ans(word.length(), ' ');
  sort(vs, ans, 256);
  for (auto c : ans) cout << c << endl;
}
