/*
Max Points on a Line

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        int max_point = 0;
        double slope = 0.0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> ht;
            int local_max = 1;
            int same_point = 0;
            int infinity = 1;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j].x == points[i].x) {
                    if (points[j].y == points[i].y) { same_point++; }
                    else { 
                        infinity++; 
                        local_max = max(local_max, infinity);
                    }
                    continue;
                }
                else {
                    slope = 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x);
                }
                if (ht.find(slope) != ht.end()) {
                    ht[slope]++;
                }
                else {
                    ht[slope] = 2;
                }
                local_max = max(local_max, ht[slope]);
            }
            max_point = max(max_point, local_max + same_point);
        }
        return max_point;
    }
};
