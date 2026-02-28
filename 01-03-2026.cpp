#include <iostream>

class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int MOD = 1e9 + 7;
        int bitLength = 0;

        for (int i = 1; i <= n; ++i) {
           
            if ((i & (i - 1)) == 0) {
                bitLength++;
            }
            
           
            ans = ((ans << bitLength) | i) % MOD;
        }

        return (int)ans;
    }
};
