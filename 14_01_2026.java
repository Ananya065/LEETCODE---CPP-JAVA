/**
 * Title: Separate Squares II (Union Area Version)
 * Difficulty: Hard
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

import java.util.*;

class Solution {
    private static class Event implements Comparable<Event> {
        int x1, x2, y, type;
        Event(int x1, int x2, int y, int type) {
            this.x1 = x1; this.x2 = x2; this.y = y; this.type = type;
        }

        @Override
        public int compareTo(Event other) {
            if (this.y != other.y) return Integer.compare(this.y, other.y);
            return Integer.compare(other.type, this.type);
        }
    }

    private static class SegmentTree {
        int[] count;
        double[] len;
        Integer[] xCoords;

        SegmentTree(Integer[] xCoords) {
            this.xCoords = xCoords;
            int n = xCoords.length;
            count = new int[8 * n];
            len = new double[8 * n];
        }

        void update(int node, int start, int end, int L, int R, int val) {
            if (xCoords[end] <= L || xCoords[start] >= R) return;
            if (xCoords[start] >= L && xCoords[end] <= R) {
                count[node] += val;
            } else {
                int mid = (start + end) / 2;
                update(node * 2, start, mid, L, R, val);
                update(node * 2 + 1, mid, end, L, R, val);
            }
            
            if (count[node] > 0) {
                len[node] = (double)xCoords[end] - xCoords[start];
            } else if (end - start > 1) {
                len[node] = len[node * 2] + len[node * 2 + 1];
            } else {
                len[node] = 0;
            }
        }
    }

    public double separateSquares(int[][] squares) {
        List<Event> events = new ArrayList<>();
        TreeSet<Integer> xSet = new TreeSet<>();
        for (int[] s : squares) {
            int x1 = s[0], y1 = s[1], l = s[2];
            events.add(new Event(x1, x1 + l, y1, 1));
            events.add(new Event(x1, x1 + l, y1 + l, -1));
            xSet.add(x1);
            xSet.add(x1 + l);
        }
        Collections.sort(events);
        Integer[] xCoords = xSet.toArray(new Integer[0]);
        int m = xCoords.length;
        SegmentTree st = new SegmentTree(xCoords);

        List<double[]> slices = new ArrayList<>();
        double totalArea = 0;

        for (int i = 0; i < events.size() - 1; i++) {
            Event e = events.get(i);
            st.update(1, 0, m - 1, e.x1, e.x2, e.type);
            
            double h = (double)events.get(i + 1).y - e.y;
            if (h > 0) {
                double w = st.len[1];
                slices.add(new double[]{e.y, events.get(i + 1).y, w});
                totalArea += w * h;
            }
        }

        double targetArea = totalArea / 2.0;
        double currentArea = 0;

        for (double[] slice : slices) {
            double yStart = slice[0];
            double yEnd = slice[1];
            double width = slice[2];
            double sliceArea = width * (yEnd - yStart);

            if (currentArea + sliceArea >= targetArea - 1e-11) {
                if (width == 0) return yStart;
                double areaNeeded = targetArea - currentArea;
                return yStart + (areaNeeded / width);
            }
            currentArea += sliceArea;
        }

        return events.get(events.size() - 1).y;
    }
}

/*
SUMMARY:
- Logic: Used a vertical sweep-line with a Segment Tree to calculate union area in horizontal "slices."
- Optimization: By pre-calculating slice widths, we avoid expensive re-calculations.
- Accuracy: Returns the minimum Y-value by checking slice boundaries and using linear interpolation.
*/
