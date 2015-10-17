/*
Meeting Rooms II
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> times;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            times.push_back(make_pair(it->start, 1));
            times.push_back(make_pair(it->end, -1));
        }
        sort(times.begin(), times.end());
        int maxRoom = 0;
        int currRoom = 0;
        for (auto it = times.begin(); it != times.end(); it++) {
            currRoom += it->second;
            maxRoom = max(maxRoom, currRoom);
        }
        return maxRoom;
    }
};
