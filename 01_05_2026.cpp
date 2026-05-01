class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        long long n = nums.size();
        long long totalSum = 0;
        long long currentFn = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            currentFn += (long long)i * nums[i];
        }

        long long maxResult = currentFn;

    
        for (int i = n - 1; i > 0; --i) {
            currentFn = currentFn + totalSum - (n * (long long)nums[i]);
            if (currentFn > maxResult) {
                maxResult = currentFn;
            }
        }

        return (int)maxResult;
    }
};
