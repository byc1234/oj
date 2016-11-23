    bool isPowerOfThree(int n) {
        double number = log10(n)/log10(3);
        return (number - (int) number) == 0;
    }

