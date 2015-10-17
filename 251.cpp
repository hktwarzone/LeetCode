/*
Flatten 2D Vector
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        int n = vec2d.size();
        for (int i = 0; i < n; i++) {
            start.push_back(vec2d[i].begin());
            end.push_back(vec2d[i].end());
        }
        curr = 0;
        while (!start.empty() && start[curr] == end[curr]) {
            curr++;
        }
    }

    int next() {
        int res = *start[curr]++;
        while (start[curr] == end[curr]) {
            curr++;
        }
        return res;
    }

    bool hasNext() {
        return (!start.empty() && curr < start.size());
    }
private:
    vector<vector<int>::iterator> start;
    vector<vector<int>::iterator> end;
    int curr;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
