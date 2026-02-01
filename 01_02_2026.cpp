class Solution {
public:
    int minimumCost(std::vector<int>& nums) {

        int firstCost = nums[0];
        

        std::vector<int> remainder(nums.begin() + 1, nums.end());
        std::sort(remainder.begin(), remainder.end());

        return firstCost + remainder[0] + remainder[1];
    }
};
