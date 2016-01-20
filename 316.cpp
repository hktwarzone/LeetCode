/*
316. Remove Duplicate Letters

Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once 
and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ht(26, 0);
        vector<bool> st(26, false);
        for (int i = 0; i < s.size(); i++) {
            ht[s[i] -  'a']++;
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (st[s[i] - 'a']) {
                ht[s[i] - 'a']--;
                continue;
            }
            while (!res.empty() && res.back() > s[i] && ht[res.back() - 'a'] > 1) {
                ht[res.back() - 'a']--;
                st[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            st[s[i] - 'a'] = true;
        }
        return res;
    }
};
