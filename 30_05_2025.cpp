class Solution {
public:
    int minElement(std::vector<int>& nums) {
        int min_sum = INT_MAX;
        
        for (int num : nums) {
            int current_sum = 0;
            
      
            while (num > 0) {
                current_sum += num % 10;
                num /= 10;
            }
            
           
            if (current_sum < min_sum) {
                min_sum = current_sum;
            }
        }
        
        return min_sum;
    }
};
