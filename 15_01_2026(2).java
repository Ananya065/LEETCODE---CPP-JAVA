/**
 * Title: Maximum Area of a Square Hole in a Grid
 * Difficulty: Medium
 * Time Complexity: O(H log H + V log V)
 * Space Complexity: O(1)
 */

import java.util.*;

class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        int maxH = getMaxGap(hBars);
        int maxV = getMaxGap(vBars);
        
        int side = Math.min(maxH, maxV);
        
        return side * side;
    }

    private int getMaxGap(int[] bars) {
        Arrays.sort(bars);
        int maxConsecutive = 1;
        int currentConsecutive = 1;
        
        for (int i = 1; i < bars.length; i++) {
            if (bars[i] == bars[i - 1] + 1) {
                currentConsecutive++;
            } else {
                currentConsecutive = 1;
            }
            maxConsecutive = Math.max(maxConsecutive, currentConsecutive);
        }
        
        return maxConsecutive + 1;
    }
}

/*
SUMMARY:
- Logic: Found the longest sequence of consecutive removable bars in both directions.
- Gap Calculation: k consecutive bars removed creates a gap of side length k + 1.
- Constraint: The result must be a square, so we take the minimum of the two max gaps.
*/
