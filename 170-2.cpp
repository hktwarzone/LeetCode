/*
170. Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); 
add(3); 
add(5);
find(4) // return true
find(7) // return false

*/

class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        m[number]++;
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        if (s.count(value) > 0) return true;
        for (auto kv : m) {
            int t = value - kv.first;
            if ((t != kv.first && m.find(t) != m.end()) || (t == kv.first && kv.second > 1)) {
                s.insert(value);
                return true;
            }
        } 
        return false;
    }
private:
    unordered_map<int, int> m;
    unordered_set<int> s;
};
