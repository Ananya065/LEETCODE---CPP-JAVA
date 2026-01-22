/*
 * LOGIC EXPLANATION:
 * 1. Greedy Simulation: We repeatedly identify the leftmost pair with the 
 * smallest sum as required by the problem statement.
 * 2. Vector Modification: We update the leftmost element of the pair with 
 * the sum and erase the rightmost element.
 * 3. Sorting Check: Before every operation, we verify if the array is 
 * non-decreasing. If it is, we return the count of operations.
 * 4. Constraint Handling: Since N is small (50), the O(N^2) approach of 
 * scanning and erasing is well within limits.
 */

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int operations = 0;

        while (nums.size() > 1 && !isSorted(nums)) {
            long long minSum = LLONG_MAX;
            int leftIdx = -1;

            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                long long currentSum = (long long)nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    leftIdx = i;
                }
            }

            if (leftIdx != -1) {
                nums[leftIdx] = (int)minSum;
                nums.erase(nums.begin() + leftIdx + 1);
                operations++;
            }
        }

        return operations;
    }

private:
    bool isSorted(const std::vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};

/*
 * FURTHER OPTIMIZATION & COMPLEXITY:
 * - Time Complexity: O(N^2). We potentially loop N times, and each time 
 * we perform an O(N) scan and an O(N) vector erasure.
 * - Space Complexity: O(1) beyond the input vector.
 */
