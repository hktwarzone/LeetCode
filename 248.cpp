/*
248. Strobogrammatic Number III 
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.

*/

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        if (!compare(low, high)) return 0;
        vector<string> bases = {"00", "11", "69", "88", "96"};
        int count = 0;
        vector<string> strobos = {"", "0", "1", "8"};
        for (int i = 0; i < strobos.size(); i++) {
            stroboHelper(bases, low, high, strobos[i], count);
        }
        return count;
    }
private:
    void stroboHelper(vector<string>& bases, string low, string high, string t, int& count) {
        if (!compare(t, high)) return;
        if (compare(low, t) && compare(t, high)) {
            if (t.size() == 1 || t.size() > 1 && t[0] != '0') count++;
        }
        for (int i = 0; i < bases.size(); i++) {
            stroboHelper(bases, low, high, bases[i].substr(0, 1) + t + bases[i].substr(1), count);
        }
    }
    bool compare(string s, string t) {
        if (s.size() != t.size()) return (s.size() < t.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < t[i]) return true;
            else if (s[i] > t[i]) return false;
        }
        return true;
    }
};
