class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
   
        long long high = 1e16; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool check(long long time, int targetHeight, const vector<int>& workerTimes) {
        long long totalReduced = 0;
        for (int w : workerTimes) {

            long long x = (-1 + sqrt(1 + 8.0 * time / w)) / 2;
            totalReduced += x;
            if (totalReduced >= targetHeight) return true;
        }
        return totalReduced >= targetHeight;
    }
};
