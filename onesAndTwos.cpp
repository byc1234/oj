#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

int eval(string &str) {
    stack<int> stk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '*') {
            int val = stk.top(); stk.pop();
            int val2 = str[i+1] - '0';
            stk.push(val*val2);
            i++;
        } else if (str[i] == '+') {
            continue;
        } else {
            stk.push(str[i] - '0');
        }
    }
    int val = 0;
    while (!stk.empty()) {
        val += stk.top(); stk.pop();
    }
    return val;
}
unordered_set<string> solution(int a, int b) {
    unordered_set<string> ans;
    if (a == 0 && b == 0) {
        ans.insert("0");
    } else if (a == 0 && b != 0) {
        unordered_set<string> tAns = solution(0, b-1);
        for (auto e : tAns) {
            ans.insert("2+" + e);
            ans.insert("2*" + e);
        }
    } else if (a != 0 && b == 0) {
        unordered_set<string> tAns = solution(a-1, 0);
        for (auto e : tAns) {
            ans.insert("1+" + e);
            ans.insert("1*" + e);
        }
    } else {
        unordered_set<string> tAns1 = solution(a-1, b);
        for (auto e : tAns1) {
            ans.insert("1+" + e);
            ans.insert("1*" + e);
        }
        unordered_set<string> tAns2 = solution(a, b-1);
        for (auto e : tAns2) {
            ans.insert("2+" + e);
            ans.insert("2*" + e);
        }
        unordered_set<string> tAns3 = solution(a-1, b-1);
        for (auto e : tAns3) {
            ans.insert("1+" + e);
            ans.insert("1*" + e);
            ans.insert("2+" + e);
            ans.insert("2*" + e);
        }
    }
    return ans;
}

int solution1(int a, int b) {
    unordered_set<string> sol = solution(a, b);
    unordered_set<int> us;
    for (auto s : sol) {
        int val = eval(s);
        if (val) us.insert(val);
    }
    return us.size();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int A, B;
        cin >> A >> B;
        cout << solution1(A, B) << endl;
    }
    return 0;
}

