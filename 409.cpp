class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ht;
        for (auto c : s) {
            ht[c]++;
        }
        int sum = 0;
        int maxOdd = 0;
        char maxOddChar = '#';
        for (auto e : ht) {
            if (e.second % 2 == 0)  sum += e.second;
            else {
                if (maxOdd < e.second) {
                    maxOdd = e.second;
                    maxOddChar = e.first;
                }
            }
        }
        for (auto e : ht) {
            if (e.second % 2 == 1) {
                if (e.second < maxOdd) sum += e.second - 1;
                if (e.second == maxOdd) {
                    if (e.first == maxOddChar) sum += e.second;
                    else sum += e.second - 1;
                }
            }
        }
        return sum;
    }
};
