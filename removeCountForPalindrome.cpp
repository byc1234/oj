#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPal(string w) {
    int n = w.length();
    for (int i = 0; i < n/2; i++) {
        if (w[i] != w[n-1-i]) return false;
    }
    return true;
}

int countForPal(string &w) {
    int idx = -1;
    int l = 0;
    int r = w.length() - 1;
    while (l < r) {
        if (w[l] == w[r]) {
            r--;
            l++;
        } else {
            if (w[l+1] == w[r] && w[l] != w[r-1]) {
                idx = l;
                break;
            } else if (w[l] == w[r-1] && w[l+1] != w[r]) {
                idx = r;
                break;
            } else {

            }
        }
    }
    return idx;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }
    for (auto w : words) {
        cout << countForPal(w) << endl;
    }
    return 0;
}

