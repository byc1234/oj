#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> hs1, hs2;
    for (auto c : s1) {
        hs1[c]++;
    }
    for (auto c : s2) {
        if (hs1[c]) hs1[c]--;
        else hs2[c]++;
    }
    int count = 0;
    for (auto e : hs1) count += e.second;
cout << count << endl;
    for (auto e : hs2) count += e.second;
cout << count << endl;
    return 0;
}
