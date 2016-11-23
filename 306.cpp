class Solution {
public:
    string add(string &num1, string &num2) {
        istringstream iss1(num1);
        long n1;
        iss1 >> n1;
        istringstream iss2(num2);
        long n2;
        iss2 >> n2;
        ostringstream oss;
        oss << n1 + n2;
        return oss.str();
    }
    
    bool validate(string num1, string num2, string remain) {
        if (num1.length() > 1 && num1[0] == '0') return false;
        if (num2.length() > 1 && num2[0] == '0') return false;
        string sum = add(num1, num2);
        if (sum == remain) return true;
        if (remain.length() <= sum.length() || sum != remain.substr(0, sum.length())) return false;
        return validate(num2, sum, remain.substr(sum.length()));
    }
    bool isAdditiveNumber(string num) {
        int half = num.length();
        for (int i = 1; i <= half; i++) {
            for (int j = 1; j <= (half-i); j++) {
                if (validate(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
};
