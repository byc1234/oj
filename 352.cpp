/*
352. Data Stream as Disjoint Intervals My Submissions QuestionEditorial Solution
Total Accepted: 732 Total Submissions: 2225 Difficulty: Hard
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?


*/
#include <set>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

set<int> vals;

struct Interval {
  int start;
  int end;
  Interval(int s, int e) : start(s), end(e) {}
};

    void addNum(int val) {
        vals.insert(val);
    }
    
    vector<Interval> getIntervals() {
        int start = INT_MIN;
        int end = INT_MIN;
        vector<Interval> ans;
        for (auto e : vals) {
            if (e > end+1) {
                if (start != INT_MIN) ans.push_back(Interval(start, end));
                start = e;
                end = e;
            } else {
                end = e;
            }
        }
        if (end != INT_MIN) ans.push_back(Interval(start, end));
        return ans;
    }

void print(vector<Interval> vals) {
  for (auto e : vals) {
    cout << "[" << e.start << "," << e.end << "], ";
  }
  cout << endl;
}

int main() {
  addNum(1);
  print(getIntervals());
  addNum(0);
  print(getIntervals());
}
