#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        B.push_back(a);
    }
    unordered_map<int, int> ms;
    for (auto i : A) {
        ms[i]++;
    }
    int cnt = 0;
    for (auto i : B) {
        if (ms[i]) {
            cnt++;
            ms[i]--;
            if (ms[i] == 0) ms.erase(i);
        }
    }
    if (cnt == n) cnt--;
    if (!ms.empty()) cnt++;
    cout << cnt << endl;
    return 0;
}

