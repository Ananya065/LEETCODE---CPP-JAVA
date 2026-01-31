/*
 * LOGIC EXPLANATION:
 * 1. Boundary Check: If the target is greater than or equal to the last element,
 * the circular property means the answer is the first element.
 * 2. Binary Search: We use low and high pointers to find the insertion point.
 * 3. Upper Bound: If letters[mid] is less than or equal to target, we move right.
 * Otherwise, we move left.
 */

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        
     
        if (target >= letters[n - 1]) {
            return letters[0];
        }

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] <= target) {
                // If current char is not greater than target, look in the right half
                low = mid + 1;
            } else {
                // If current char is greater, it's a candidate, but look for smaller ones on the left
                high = mid - 1;
            }
        }

        return letters[low];
    }
}
