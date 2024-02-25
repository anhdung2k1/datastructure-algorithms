#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedInterval;
        sort(intervals.begin(), intervals.end());
        for(auto interval : intervals) {
            if (newInterval[0] > interval[1]) {
                mergedInterval.push_back(interval);
            } else if (newInterval[1] < interval[0]) {
                mergedInterval.push_back(newInterval);
                newInterval.assign(interval.begin(), interval.end());
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        mergedInterval.push_back(newInterval);
        return mergedInterval;
    }
};