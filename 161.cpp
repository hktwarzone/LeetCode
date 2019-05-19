/*
161. One Edit Distance

Given two strings S and T, determine if they are both one edit distance apart.

Example 1:

Input: s = "aDb", t = "adb" 
Output: true
Example 2:

Input: s = "ab", t = "ab" 
Output: false
Explanation:
s=t ,so they aren't one edit distance apart

*/

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        if (s.size() > t.size()) swap(s, t);
        int s_size = s.size();
        int t_size = t.size();
        if (s_size == t_size - 1) {
            for (int i = 0; i < s_size; i++) {
                if (s[i] != t[i]) {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
            return true;
        }
        else if (s_size == t_size) {
            int diff = 0;
            for (int i = 0; i < s_size; i++) {
                if (s[i] != t[i]) diff++;
                if (diff > 1) return false;
            }
            return (diff == 1);
        }
        return false;
    }
};
