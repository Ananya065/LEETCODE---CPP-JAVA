/**
 * Title: 85. Maximal Rectangle
 * Link: http://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-11
 * Difficulty: Hard
 * Time Complexity: O(R * C) - We process each cell of the matrix once
 * Space Complexity: O(C) - We store an array of heights for one row
 */


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            
            for (int j = 0; j < cols; ++j) {
                
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            
            
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0); 
        int maxA = 0;

        for (int i = 0; i < heights.size(); ++i) {
            
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                
                int w = s.empty() ? i : i - s.top() - 1;
                maxA = max(maxA, h * w);
            }
            s.push(i);
        }
        
        heights.pop_back(); 
        return maxA;
    }
};

/*
problem statement:
Given a rows x cols binary matrix, find the largest rectangle containing 
only 1's and return its area.

how i approached this problem:
I treated each row as the base of a histogram. By iterating through the rows, 
I updated the 'height' of each column (consecutive 1s). For every row, I 
applied the 'Largest Rectangle in Histogram' algorithm using a monotonic 
stack. This allowed me to calculate the maximum area possible ending at 
each row in linear time relative to the number of columns.

SUMMARY:
- Difficulty: Hard
- Concept: Monotonic Stack / Histogram / Dynamic Programming
- Data Structure: Stack & Vector
- Efficiency: O(R * C) time and O(C) space
*/
