    bool increasingTriplet(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        for (int n : nums) {
            if (n <= firstMin) firstMin = n;
            else if (n < secondMin) secondMin = n;
            else if (n > secondMin) return true;
        }
        return false;
    }

