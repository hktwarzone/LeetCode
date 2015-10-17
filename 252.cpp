/*
Meeting Rooms
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start; });
        stack<Interval> st;
        for (auto it = intervals.begin(); it != intervals.end(); it++) {
            if (st.empty() || st.top().end <= it->start) {
                st.push(*it);
            }
            else return false;
        }
        return true;
    }
};
