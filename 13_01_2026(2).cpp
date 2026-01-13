/**
 * Title: 3418. Reshape Data (Simulated - Horizontal Line Square Split)
 * Link: https://leetcode.com/problems/separate-squares-i/?envType=daily-question&envId=2026-01-13
 * Difficulty: Hard
 * Time Complexity: O(N * log(Range / Precision)) 
 * Space Complexity: O(1)
 */


class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 2e9, high = 0;

        for (const auto& s : squares) {
            double l = s[2];
            totalArea += l * l;
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + l);
        }

        
        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2;
            if (getAreaBelow(squares, mid) * 2 >= totalArea) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return low;
    }

private:
    double getAreaBelow(const vector<vector<int>>& squares, double yLine) {
        double area = 0;
        for (const auto& s : squares) {
            double yStart = s[1];
            double side = s[2];
            double yEnd = yStart + side;

            if (yLine <= yStart) continue;
            if (yLine >= yEnd) {
                area += side * side;
            } else {
                area += side * (yLine - yStart);
            }
        }
        return area;
    }
};

/*
problem statement:
Find the minimum y-coordinate of a horizontal line such that the total area 
of squares above and below the line are equal.

how i approached this problem:
I recognized that as the horizontal line moves upward, the area below it 
monotonically increases. This property allows for Binary Search on the 
y-coordinate. I calculated the total area first, then searched for the 
point where the 'Area Below' function reaches exactly half of the total. 
Using 100 iterations of binary search ensures the precision required 
by the problem (10^-5).

SUMMARY:
- Difficulty: Hard
- Concept: Binary Search on Answer / Geometry
- Data Structure: 2D Vector
- Efficiency: O(N * log(Range)) time and O(1) space
*/
