    bool isSelfCrossing(vector<int>& x) {
        if (x.empty()) return false;
        if (x.size() < 4) return false;

        for (int i = 3; i < x.size(); i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;  //Fourth line crosses first line and onward
            if (i >= 4) {
                if(x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true; // Fifth line meets first line and onward
            }
            if (i >=5)
            {
                if (x[i-2] - x[i-4] >= 0 && x[i] >= x[i-2] - x[i-4] && x[i-1] >= x[i-3] - x[i-5] && x[i-1] <= x[i-3]) return true;  // Sixth line crosses first line and onward
            }
        }
        return false;
    }

