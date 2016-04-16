/*
340. Longest Substring with At Most K Distinct Characters
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        if (s.size() < k) return s.size();
        vector<int> position(128, -1);
        map<int, int> startp;
        int start = 0;
        int maxlength = 0;
        position[s[0]] = 0;
        startp[0] = s[0];
        for (int i = 1; i < s.size(); i++) {
            if (startp.size() == k && position[s[i]] == -1) {
                maxlength = max(maxlength, i - start);
                start = startp.begin()->first + 1;
                position[startp.begin()->second] = -1;
                startp.erase(startp.begin());
            }
            if (position[s[i]] != -1) {
                startp.erase(startp.find(position[s[i]]));
            }
            position[s[i]] = i;
            startp[i] = s[i];
        }
        maxlength = max(maxlength, (int)s.size() - start);
        return maxlength;        
    }
};
