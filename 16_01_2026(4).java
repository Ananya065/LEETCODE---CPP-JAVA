
/*
 * LOGIC EXPLANATION:
 * We simulate writing the string on a grid with 'numRows'. We move down until we 
 * hit the bottom, then "bounce" and move up until we hit the top. 
 * Instead of tracking columns, we just append characters to the corresponding row.
 *
 * DATA STRUCTURES:
 * 1. List<StringBuilder>: Stores a StringBuilder for each row to handle efficient appending.
 * 2. boolean goingDown: A toggle to track if the current row index should increase or decrease.
 * 3. int currRow: The current row index we are writing to.
 */

class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < Math.min(numRows, s.length()); i++) {
            rows.add(new StringBuilder());
        }

        int currRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows.get(currRow).append(c);
            
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            currRow += goingDown ? 1 : -1;
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}

/*
 * FURTHER OPTIMIZATION:
 * Time Complexity: O(n) - We visit each character in the string once.
 * Space Complexity: O(n) - We store all characters in the List of StringBuilders.
 *
 * MATHEMATICAL OPTIMIZATION (O(1) Extra Space):
 * You can avoid using the List/StringBuilders by calculating the index of characters 
 * for each row directly. The distance between characters in the first and last rows 
 * is always (2 * numRows - 2). For middle rows, there is an extra character 
 * at an offset of (cycle - 2 * currentRowIndex).
 */
