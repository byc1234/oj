class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first < p2.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        for (auto e : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), e.second);
            if (it == dp.end()) dp.push_back(e.second);
            else *it = e.second;
        }
        return dp.size();
    }
};

/*

public int maxEnvelopes(int[][] envelopes) {
    if (   envelopes           == null
        || envelopes.length    == 0
        || envelopes[0]        == null
        || envelopes[0].length == 0){
        return 0;    
    }

    Arrays.sort(envelopes, new Comparator<int[]>(){
        @Override
        public int compare(int[] e1, int[] e2){
            return Integer.compare(e1[0], e2[0]);
        }
    });

    int   n  = envelopes.length;
    int[] dp = new int[n];

    int ret = 0;
    for (int i = 0; i < n; i++){
        dp[i] = 1;

        for (int j = 0; j < i; j++){
            if (   envelopes[i][0] > envelopes[j][0]
                && envelopes[i][1] > envelopes[j][1]){
                dp[i] = Math.max(dp[i], 1 + dp[j]);    
            }
        }

        ret = Math.max(ret, dp[i]);
    }
    return ret;
}


You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Given envelopes = [[4,5],[4,6],[6,7],[2,3],[1,1]] , the maximum number of envelopes you can Russian doll is 4 ([1,1] => [2,3] => [4,5] => [6,7]).


*/
