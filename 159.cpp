/*
Longest Substring with At Most Two Distinct Characters

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) return s.size();
        int start = 0;
        int maxlen = 0;
        int prev = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) continue;
            if (prev >= 0 && s[i] != s[prev]) {
                maxlen = max(maxlen, i - start);
                start = prev + 1;
            }
            prev = i - 1;
        }
        return max(maxlen, (int)s.size() - start);
    }
};
