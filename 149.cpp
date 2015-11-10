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
class PairHash {
public:
    int operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        int max_point = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<pair<int, int>, int, PairHash> ht;
            int local_max = 1;
            int same_point = 0;
            for (int j = i + 1; j < points.size(); j++) {
                pair<int, int> slope;
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        same_point++;
                        continue;
                    }
                    else {
                        slope = make_pair(0, 1);
                    }
                }
                else {
                    if (points[i].y == points[j].y) {
                        slope = make_pair(1, 0);
                    }
                    else {
                        int dx = points[i].x - points[j].x;
                        int dy = points[i].y - points[j].y;
                        int sign = (dx * dy < 0) ? -1 : 1;
                        slope = reduce(make_pair(abs(dx), sign * abs(dy)));
                    }
                }
                if (ht.find(slope) != ht.end()) ht[slope]++;
                else ht[slope] = 2;
                local_max = max(local_max, ht[slope]);
            }
            max_point = max(max_point, local_max + same_point);
        }
        return max_point;
    }
private:
    int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
    pair<int, int> reduce(pair<int, int> p) {
        int g = gcd(p.first, p.second);
        return make_pair(p.first/g, p.second/g);
    }
};
