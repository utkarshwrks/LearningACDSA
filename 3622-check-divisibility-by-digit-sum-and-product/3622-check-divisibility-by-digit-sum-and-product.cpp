class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1;
        int num = n;

        while (n > 0) {
            int digit = n % 10;
            digitSum += digit;
            digitProduct *= digit;
            n /= 10;
        }

        int result = digitSum + digitProduct;

        return num % result == 0;
    }
};