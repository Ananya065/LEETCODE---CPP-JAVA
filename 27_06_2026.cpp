class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int maxLen = 1;
        
        if (count.count(1)) {
            int ones = count[1];
            if (ones % 2 == 0) {
                maxLen = max(maxLen, ones - 1);
            } else {
                maxLen = max(maxLen, ones);
            }
        }
        
        for (auto& pair : count) {
            long long x = pair.first;
            if (x == 1) continue;
            
            int currentLen = 0;
            while (count.count(x) && count[x] >= 2) {
                currentLen += 2;
                x = x * x;
            }
            
            if (count.count(x) && count[x] >= 1) {
                currentLen += 1;
            } else {
                currentLen -= 1;
            }
            
            maxLen = max(maxLen, currentLen);
        }
        
        return maxLen;
    }
};
