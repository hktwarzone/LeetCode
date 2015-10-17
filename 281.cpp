/*
Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
*/

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        start[0] = v1.begin();
        end[0] = v1.end();
        start[1] = v2.begin();
        end[1] = v2.end();
        p = 0;
    }

    int next() {
        int res;
        if (start[0] == end[0]) { res = *start[1]++; }
        else if (start[1] == end[1]) { res = *start[0]++; }
        else {
            res = *start[p]++;
            p = (p + 1) % 2;
        }
        return res;
    }

    bool hasNext() {
        return (start[0] != end[0] || start[1] != end[1]);
    }
private:
    vector<int>::iterator start[2];
    vector<int>::iterator end[2];
    int p;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
