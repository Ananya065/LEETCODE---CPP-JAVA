#include <vector>
#include <set>
#include <numeric>

class Solution {
    long long sum = 0;
    int k_needed;
    std::multiset<int> left, right;

    void balance() {
        while (left.size() < k_needed && !right.empty()) {
            int val = *right.begin();
            sum += val;
            left.insert(val);
            right.erase(right.begin());
        }
        while (left.size() > k_needed) {
            int val = *left.rbegin();
            sum -= val;
            right.insert(val);
            left.erase(prev(left.end()));
        }
    }

    void add(int val) {
        if (!left.empty() && val < *left.rbegin()) {
            sum += val;
            left.insert(val);
        } else {
            right.insert(val);
        }
        balance();
    }

    void remove(int val) {
        auto it = left.find(val);
        if (it != left.end()) {
            sum -= val;
            left.erase(it);
        } else {
            right.erase(right.find(val));
        }
        balance();
    }

public:
    long long minimumCost(std::vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k_needed = k - 1; 
        sum = 0;
        left.clear();
        right.clear();

        for (int i = 1; i <= dist + 1; ++i) {
            add(nums[i]);
        }

        long long minTotalCost = nums[0] + sum;

        for (int i = 2; i <= n - (k_needed); ++i) {
            remove(nums[i - 1]);
         
            if (i + dist < n) {
                add(nums[i + dist]);
            }
            minTotalCost = std::min(minTotalCost, nums[0] + sum);
        }

        return minTotalCost;
    }
};
