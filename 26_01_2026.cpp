/*
 * LOGIC EXPLANATION:
 * 1. Sorting: The minimum difference between any two elements must exist 
 * between two adjacent elements in a sorted array.
 * 2. Minimum Search: We perform a first pass (or track during the scan) 
 * to find what the actual global minimum absolute difference is.
 * 3. Collection: We collect all adjacent pairs [arr[i], arr[i+1]] 
 * whose difference matches that minimum.
 */

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        std::vector<std::vector<int>> result;
        int minDiff = INT_MAX;
        
        for (int i = 0; i < (int)arr.size() - 1; ++i) {
            int currentDiff = arr[i+1] - arr[i];
            
            if (currentDiff < minDiff) {
                minDiff = currentDiff;
                result.clear();
                result.push_back({arr[i], arr[i+1]});
            } else if (currentDiff == minDiff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }
        
        return result;
    }
};
