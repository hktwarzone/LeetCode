/*
340. Longest Substring with At Most K Distinct Characters

Given a string, find the length of the longest substring T that contains at most k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.
*/

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        vector<int> m(128, 0);
        int count = 0;
        int result = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            if (m[s[i]] == 1) count++;
            while(count > k) {
                if (m[s[start]] == 1) count--;
                m[s[start++]]--;
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};
