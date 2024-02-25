#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedInterval;
        vector<int> interval_cp;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(auto interval : intervals) {
            if (interval[0] > end) {
                mergedInterval.push_back({start, end});
                start = interval[0];
                end = interval[1];
            } else if (interval[1] > end){
                end = interval[1]; //swap the larger value
            }
        }
        // Add the interval in the last
        mergedInterval.push_back({start, end});
        return mergedInterval;
    }
};