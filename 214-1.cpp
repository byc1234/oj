#include <iostream>
#include <vector>

using namespace std;

    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        string kmp = s + "#" + revStr;
cout << kmp << endl;
        vector<int> pat(kmp.length(), 0);
        int j = 0;
        for (int i = 1; i < kmp.length(); i++) {
            j = pat[i-1];
            while (j > 0 && kmp[i] != kmp[j]) {
                j = pat[j-1];
            }
            pat[i] = (j += kmp[i] == kmp[j]);

        }
cout << "kmp : " << pat[kmp.length()-1] << endl;
        return revStr.substr(0, s.length() - pat[kmp.length()-1]) + s;
    }

int main() {
   cout << shortestPalindrome("ababbbabbaba") << endl;
   cout << shortestPalindrome("aabbaaa") << endl;
   cout << shortestPalindrome("aacecaaa") << endl;
}
