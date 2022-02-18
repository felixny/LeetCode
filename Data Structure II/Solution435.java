import java.util.Arrays;

public class Solution435 {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null)
            return 0;

        Arrays.sort(intervals, (a, b) -> a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]);
        int ans = 0;
        int currentEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < currentEnd) {
                ans++;
            } else {
                currentEnd = intervals[i][1];
            }

        }

        return ans;

    }
}
