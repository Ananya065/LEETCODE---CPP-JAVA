class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

       
        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10; 
            }
        }

        int max_len = 0;

      
        for (int num : arr2) {
            while (num > 0) {
                if (prefixes.count(num)) {
                  
                    int current_len = to_string(num).length();
                    max_len = max(max_len, current_len);
                    break; 
                }
                num /= 10;
            }
        }

        return max_len;
    }
};
