class Solution {
public:
    pair<int, int> getHourMin(const string &s) {
        return make_pair(stoi(s.substr(0, 2)), stoi(s.substr(3, 2)));
    }
    int minTimeDiff(const string& time1, const string& time2) {
        int firstHour;
        int firstMin;
        int secondHour;
        int secondMin;
        tie(firstHour, firstMin) = getHourMin(time1);
        tie(secondHour, secondMin) = getHourMin(time2);
        int diffMin = 0;
        if (firstHour > secondHour) {
            diffMin = (firstHour-secondHour)*60 + firstMin - secondMin;
        } else if (secondHour > firstHour) {
            diffMin = (secondHour-firstHour)*60 + secondMin - firstMin;
        } else {
            if (firstMin > secondMin) {
                diffMin = firstMin - secondMin;
            } else {
                diffMin = secondMin - firstMin;
            }
        }
        if (diffMin > 12*60) {
            diffMin = 24*60 - diffMin;
        }
        return diffMin;
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int diffMin = INT_MAX;
        for (int i = 0; i < (n-1); i++) {
            diffMin = min(diffMin, minTimeDiff(timePoints[i], timePoints[i+1]));
        }
        diffMin = min(diffMin, minTimeDiff(timePoints[n-1], timePoints[0]));
        return diffMin;
    }
};

