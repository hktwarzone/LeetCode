/*
340. Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxlength = 0;
        int start = 0;
        int dist = 0;
        vector<int> count(128, 0);
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]]++ == 0) dist++;
            if (dist > k) {
                while(--count[s[start++]] > 0);
                dist--;
            }
            maxlength = max(maxlength, i - start + 1);
        }
        return maxlength;
    }
};
