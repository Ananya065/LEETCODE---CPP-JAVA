#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> bestBeforePeak(n, numeric_limits<long long>::min());
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                long long prev = (i - 1 > 0 && nums[i - 1] > nums[i - 2]) ? bestBeforePeak[i - 1] : 0;
                bestBeforePeak[i] = max((long long)nums[i - 1], prev + nums[i - 1]);
            }
        }

        vector<long long> bestAfterValley(n, numeric_limits<long long>::min());
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                long long next = (i + 1 < n - 1 && nums[i + 1] < nums[i + 2]) ? bestAfterValley[i + 1] : 0;
                bestAfterValley[i] = max((long long)nums[i + 1], next + nums[i + 1]);
            }
        }

        long long maxSum = numeric_limits<long long>::min();

        for (int i = 1; i < n - 2; i++) {
            if (bestBeforePeak[i] == numeric_limits<long long>::min()) continue;
            
            long long currentDecSum = nums[i];
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j] < nums[j - 1]) {
                    currentDecSum += nums[j];
                    if (bestAfterValley[j] != numeric_limits<long long>::min()) {
                        long long total = bestBeforePeak[i] + currentDecSum + bestAfterValley[j];
                        if (total > maxSum) maxSum = total;
                    }
                } else {
                    break;
                }
            }
        }

        return maxSum;
    }
};
