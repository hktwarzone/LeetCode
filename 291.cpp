/*
Word Pattern II
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        if (pattern.empty() && str.empty()) return true;
        if (pattern.empty() || str.empty()) return false;
        if (pattern.size() > str.size()) return false;
        unordered_map<char, string> ht;
        unordered_map<string, char> aht;
        return matchHelper(pattern, str, ht, aht, 0, 0);
    }
private:
    bool matchHelper(string& p, string& s, unordered_map<char, string>& ht, unordered_map<string, char>& aht, int start, int curr_p) {
        if (start == s.size() && curr_p == p.size()) return true;
        if (start == s.size() || curr_p == p.size()) return false;
        if (p.size() - curr_p > s.size() - start) return false;
        for (int i = start; i < s.size(); i++) {
            string curr = s.substr(start, i - start + 1);
            if ((ht.find(p[curr_p]) == ht.end() && aht.find(curr) == aht.end())) {
                ht[p[curr_p]] = curr;
                aht[curr] = p[curr_p];
                if (matchHelper(p, s, ht, aht, i + 1, curr_p + 1)) return true;
                ht.erase(p[curr_p]);
                aht.erase(curr);
            }
            else if ((ht.find(p[curr_p]) != ht.end() && aht.find(curr) != aht.end())) {
                if (ht[p[curr_p]] == curr && aht[curr] == p[curr_p]) {
                    if (matchHelper(p, s, ht, aht, i + 1, curr_p + 1)) return true;
                }
            }
        }
        return false;
    }
};
