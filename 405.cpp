class Solution {
public:
    string toHex(int num) {
        string ans = "";
        for (int i = 0; i < 32 && num; i += 4) {
            int val = num & 0xf;
            if (val == 0) ans = '0' + ans;
            else if (val == 1) ans = "1" + ans;
            else if (val == 2) ans = "2" + ans;
            else if (val == 3) ans = "3" + ans;
            else if (val == 4) ans = "4" + ans;
            else if (val == 5) ans = "5" + ans;
            else if (val == 6) ans = "6" + ans;
            else if (val == 7) ans = "7" + ans;
            else if (val == 8) ans = "8" + ans;
            else if (val == 9) ans = "9" + ans;
            else if (val == 10) ans = "a" + ans;
            else if (val == 11) ans = "b" + ans;
            else if (val == 12) ans = "c" + ans;
            else if (val == 13) ans = "d" + ans;
            else if (val == 14) ans = "e" + ans;
            else if (val == 15) ans = "f" + ans;
            num >>= 4;
         }
         if (ans.empty()) ans = "0";
         return ans;
    }
};
