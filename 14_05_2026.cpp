class Solution {
public:
    bool isGood(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return false;

      
        int n = 0;
        for (int num : nums) {
            n = max(n, num);
        }

      
        if (len != n + 1) {
            return false;
        }

     
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

 
        for (int i = 1; i < n; ++i) {
            if (counts[i] != 1) return false;
        }

        if (counts[n] != 2) return false;

        return true;
    }
};
