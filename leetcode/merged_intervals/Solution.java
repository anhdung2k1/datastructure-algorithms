package leetcode.merged_intervals;

import java.util.*;

public class Solution {
    public static int[][] merge(int[][] intervals) {
        LinkedList<int[]> mergedInterval = new LinkedList<>();
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int[] interval : intervals) {
            if(interval[0] > end) {
                mergedInterval.add(new int[] {start, end});
                start = interval[0];
                end = interval[1];
            } else if (interval[1] > end) {
                end = interval[1];
            }
        }
        mergedInterval.add(new int[] {start, end});
        return mergedInterval.toArray(new int[mergedInterval.size()][]);
    }
    public static void main(String[] args) {
        
    }
}
