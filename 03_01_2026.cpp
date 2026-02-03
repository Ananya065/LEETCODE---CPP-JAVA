class Solution {
public: 
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        bool increased1 = false;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
            increased1 = true;
        }

        if (!increased1 || i == n - 1) return false;
        
        bool decreased = false;
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
            decreased = true;
        }

        if (!decreased || i == n - 1) return false;

        bool increased2 = false;
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
            increased2 = true;
        }

        return increased2 && i == n - 1;
    }
};
