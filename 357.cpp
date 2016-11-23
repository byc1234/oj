class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 10;
        int uniqueDigit = 9;
        int availableDigit = 9;
        while (n-- > 1 && availableDigit) {
            uniqueDigit = uniqueDigit * availableDigit;
            sum += uniqueDigit;
            availableDigit--;
        }
        return sum;
    }
};
