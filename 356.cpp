/*
356. Line Reflection
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:

Input: [[1,1],[-1,1]]
Output: true
Example 2:

Input: [[1,1],[-1,-1]]
Output: false

Follow up:
Could you do better than O(n2) ?
*/
class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int minx = INT_MAX;
        int maxx = INT_MIN;
        set<vector<int>> s;
        for (auto p : points) {
            if (p[0] < minx) minx = p[0];
            if (p[0] > maxx) maxx = p[0];
            s.insert(p);
        }
        for (int i = 0; i < points.size(); i++) {
            if (s.find(vector<int>{minx + maxx - points[i][0], points[i][1]}) == s.end()) {
                return false;
            }
        }
        return true;
    }
};
