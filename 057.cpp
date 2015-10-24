/*
Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals.back().end < newInterval.start) {
            intervals.push_back(newInterval);
            return intervals;
        }
        if (intervals[0].start > newInterval.end) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        int n = intervals.size();
        int smaller = -1;
        if (intervals[0].end < newInterval.start) {
            int left = 0;
            int right = n - 1;
            while(left < right) {
                int mid = left + (right - left + 1) / 2;
                if (intervals[mid].end < newInterval.start) { left = mid; }
                else { right = mid - 1; }
            }
            smaller = left;
        }
        int larger = n;
        if (intervals[n - 1].start > newInterval.end) {
            int left = 0;
            int right = n - 1;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if (intervals[mid].start > newInterval.end) { right = mid; }
                else { left = mid + 1; }
            }
            larger = left;
        }
      
        vector<Interval> res;
        for (int i = 0; i <= smaller; i++) {
            res.push_back(intervals[i]);
        }
        if (smaller + 1 == larger) {
            res.push_back(newInterval);
        }
        else {
            res.push_back(Interval(min(newInterval.start, intervals[smaller + 1].start), max(newInterval.end, intervals[larger - 1].end)));
        }
        for (int i = larger; i < n; i++) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
