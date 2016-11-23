class Solution {
public:
    bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void findCandiates(string &s, vector<string> &left, vector<string> &right) {
        int l = s.length();
        string rStr = string(s.rbegin(), s.rend());
        left.push_back(rStr);
        right.push_back(rStr);
        for (int i = 0; i < l; i++) {
            if (isPal(s, 0, i)) {
                string eStr = s.substr(i+1);
                left.push_back(string(eStr.rbegin(), eStr.rend()));
            }
            if (isPal(s, l-i-1, l-1)) {
                string bStr = s.substr(0, l-1-i);
                right.push_back(string(bStr.rbegin(), bStr.rend()));
            }
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        set<vector<int>> ansPairs;
        unordered_map<string, int> wToi;
        for (int i = 0; i < n; i++) wToi[words[i]] = i;
        for (int i = 0; i < n; i++) {
            vector<string> leftCand;
            vector<string> rightCand;
            findCandiates(words[i], leftCand, rightCand);
            for (string w : leftCand) {
                if (wToi.find(w) != wToi.end()) {
                    if (wToi[w] != i) {
                        vector<int> pair;
                        pair.push_back(wToi[w]);
                        pair.push_back(i);
                        ansPairs.insert(pair);
                    }
                }
            }
            for (string w : rightCand) {
                if (wToi.find(w) != wToi.end()) {
                    if (wToi[w] != i) {
                        vector<int> pair;
                        pair.push_back(i);
                        pair.push_back(wToi[w]);
                        ansPairs.insert(pair);
                    }
                }
            }
        }
        return vector<vector<int>>(ansPairs.begin(), ansPairs.end());
    }
};
