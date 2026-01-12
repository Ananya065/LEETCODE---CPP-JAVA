/**
 * Title: 1266. Minimum Time Visiting All Points
 * Link: https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12
 * Difficulty: Easy
 * Time Complexity: O(N) - We iterate through the list of points once
 * Space Complexity: O(1) - Constant extra space used
 */


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        for (int i = 0; i < points.size() - 1; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i+1][0], y2 = points[i+1][1];
            
            
            totalTime += max(abs(x2 - x1), abs(y2 - y1));
        }
        
        return totalTime;
    }
};

/*
problem statement:
Given n points, find the minimum time to visit them in order. You can move 
horizontally, vertically, or diagonally in 1 second.

how i approached this problem:
I realized that moving diagonally covers both one unit of horizontal distance 
and one unit of vertical distance simultaneously in 1 second. Therefore, the 
limiting factor is whichever distance (horizontal or vertical) is larger. 
By summing these maximum differences between every consecutive pair of points, 
we get the total minimum time.

SUMMARY:
- Difficulty: Easy
- Concept: Geometry / Chebyshev Distance
- Data Structure: 2D Vector
- Efficiency: O(N) time and O(1) space
*/
