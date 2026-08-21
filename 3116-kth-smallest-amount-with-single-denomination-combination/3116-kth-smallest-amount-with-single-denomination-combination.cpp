#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long countAmounts(long long target, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int set_bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    set_bits++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > target) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (set_bits % 2 == 1) {
                count += target / current_lcm;
            } else {
                count -= target / current_lcm;
            }
        }

        return count;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int> filtered_coins;
        sort(coins.begin(), coins.end());
        for (int coin : coins) {
            bool redundant = false;
            for (int f : filtered_coins) {
                if (coin % f == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                filtered_coins.push_back(coin);
            }
        }

        long long low = 1;
        long long high = 1LL * filtered_coins[0] * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid, filtered_coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};