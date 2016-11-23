#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

static int comp(pair<int, int> &a, pair<int, int> &b) {
    int aSum = a.first + a.second;
    int bSum = b.first + b.second;
    if (aSum == bSum) return a.first < b.first;
    else if (aSum < bSum) return 1;
    else return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<pair<int, int>> orders;
    unordered_map<pair<int,int>, int> um;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        pair<int, int> td = make_pair(t, d);
        orders.push_back(td);
        um[td] = i;
    }
    sort(orders.begin(), orders.end(), comp);
    for (int i = 0; i < orders.size(); i++) {
        cout << um[orders[i]] + 1;
        if (i == (orders.size() - 1)) cout << endl;
        else cout << " ";
    }
    return 0;
}

