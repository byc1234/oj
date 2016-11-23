#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void calc(vector<int> q)
{
    int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) ans++;
    }
    cout << ans << endl;
}

void swap(vector<int> &q, int i, int j) {
    int tmp = q[i];
    q[i] = q[j];
    q[j] = tmp;
}

int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
           q[q_i]--;
        }
        // your code goes here
        unordered_map<int, int> valToIdx;
        for (int i = 0; i < n; i++) {
            valToIdx[q[i]] = i;
        }
        int count = 0;
        bool chaotic = false;
        for (int i = n-1; i > -1; i--) {
            int idx = valToIdx[i];
            if (i == idx) continue;
            if (i - idx > 2) {
                chaotic = true;
                break;
            }
            while (idx != i) {
cout << "idx:" << idx << ", i:" << i << endl;
                swap(q, idx, idx+1);
                valToIdx[q[idx]] = idx;
                valToIdx[q[idx+1]] = idx + 1;
                idx++;
                count++;
            }
for (auto n : q) cout << "n:" << n << endl;
        }
        if (chaotic) 
          cout << "Too chaotic"  << endl;
        else
          cout << count << endl;
    }
    return 0;
}


