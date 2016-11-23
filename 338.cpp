/*
0 1 
  1 2 
  1 2 2 3 
  1 2 2 3 2 3 3 4 1  
*/

class Solution {
public:
    int bitCnt(int num) {
        int cnt = 0;
        for (int i = 0; i < 32 && num; i++) {
            cnt += (num & 0x1);
            num >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; i++) {
            ans.push_back(bitCnt(i));
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= num; i++) {
            ans.push_back(ans[i/2] + (i&1));
        }
        return ans;
    }
};
