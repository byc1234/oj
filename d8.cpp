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
    unordered_map<string, string> dict;
    for (int i =0 ; i < n; i++) {
        string name, number;
        cin >> name >> number;
        dict[name] = number;
    }
    string name;
    while (cin >> name) {
        auto it = dict.find(name);
        if (it != dict.end()) cout << name << "=" << it->second << endl;
        else cout << "Not found" << endl;
    }
    return 0;
}

