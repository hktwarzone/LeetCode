/*
352. Data Stream as Disjoint Intervals 
Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far 
as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]

Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
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
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (find(val) == -1) {
            parent[val] = val;
            mergep(val);
            if (find(val + 1) != -1) mergep(val + 1);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto it = last.begin(); it != last.end(); it++) {
            res.push_back(Interval(it->first, it->second));
        }
        return res;
    }
private:
    unordered_map<int, int> parent;
    map<int, int> last;
    int find(int id) {
        if (parent.find(id) != parent.end()) {
            int p = parent[id];
            while(parent[p] != p) {
                p = parent[p];
            }
            int c = id;
            while(parent[c] != c) {
                int tmp = parent[c];
                parent[c] = p;
                c = tmp;
            }
            return p;
        }
        return -1;
    }
    void mergep(int a) {
        int p = find(a - 1);
        if (p == -1) {
            last[a] = a;
            return;
        }
        else {
            parent[a] = p;
            if (last.find(a) == last.end()) {
                last[p] = a;
            }
            else {
                last[p] = last[a];
                last.erase(a);
            }
        }
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
