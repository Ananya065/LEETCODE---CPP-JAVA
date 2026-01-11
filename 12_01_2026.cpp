/**
 * Title: 4. Median of Two Sorted Arrays
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * Difficulty: Hard
 * Time Complexity: O(log(min(M, N))) - Binary search on the smaller array
 * Space Complexity: O(1) - Constant space used
 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
           
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                
                else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            
            else {
                low = partitionX + 1;
            }
        }

        return 0.0; 
    }
};

/*
problem statement:
Given two sorted arrays, find the median. The catch is the O(log(m+n)) constraint, 
which forbids merging the arrays.

how i approached this problem:
I used binary search to find a partition point in the smaller array. By splitting 
both arrays into two parts (left and right), I ensured that:
1. The total number of elements in the combined left part equals the right part.
2. The largest element on the left (maxLeft) is less than or equal to the 
   smallest element on the right (minRight).
The median is then either the max of the left elements (if odd total) or the 
average of the boundaries (if even total).

SUMMARY:
- Difficulty: Hard
- Concept: Binary Search on Partitions
- Data Structure: Arrays (Vectors)
- Efficiency: O(log(min(M, N))) time and O(1) space
*/
