package leetcode.insert_interval;
import java.util.*;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> mergedInterval = new ArrayList<int[]>();
        // Sort 2-D in ascending
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        for (int[] interval : intervals) {
            if (interval[1] < newInterval[0]) {
                mergedInterval.add(interval);
            } else if (interval[0] > newInterval[1]) {
                mergedInterval.add(newInterval);
                newInterval = interval;
            } else {
                newInterval[0] = Math.min(newInterval[0], interval[0]);
                newInterval[1] = Math.max(newInterval[1], interval[1]);
            }
        }
        mergedInterval.add(newInterval);
        return mergedInterval.toArray(new int[mergedInterval.size()][]);
    }
}