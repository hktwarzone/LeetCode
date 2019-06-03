/*
218. The Skyline Problem

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city 
when viewed from a distance. Now suppose you are given the locations and height of all the buildings 
as shown on a cityscape photo, write a program to output the skyline formed by these 
buildings collectively.

Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings are recorded as: [ [2 9 10], [3 7 15], 
[5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that 
uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that 
the last key point, where the rightmost building ends, is merely used to mark the termination of the 
skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be 
considered part of the skyline contour.

For instance, the skyline should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], 
[24, 0] ].
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        if (buildings.empty()) return res;
        vector<pair<int, int>> timeh;
        for (auto b : buildings) {
            timeh.push_back(make_pair(b[0], -b[2]));
            timeh.push_back(make_pair(b[1], b[2]));
        }
        sort(timeh.begin(), timeh.end());
        multiset<int> h;
        h.insert(0);
        int curr_h = 0;
        int prev_h = 0;
        for (auto p : timeh) {
            if (p.second < 0) h.insert(-(p.second));
            else h.erase(h.find(p.second));
            curr_h = *h.rbegin();
            if (curr_h != prev_h) {
                res.push_back(vector<int>{p.first, curr_h});
                prev_h = curr_h;
            }
        }
        return res;
    }
};
