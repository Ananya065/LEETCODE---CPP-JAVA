class Solution {
public:
    long long gcdOfOddEvenSums(int n) {
        long long sumOdd = (long long)n * n;
        long long sumEven = (long long)n * (n + 1);
        return std::gcd(sumOdd, sumEven);
    }
};