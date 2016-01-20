/*
318. Maximum Product of Word Lengths

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words 
do not share common letters. You may assume that each word will contain only lower case letters. If no such 
two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) return 0;
        sort(words.begin(), words.end(), [](string a, string b) { return a.size() < b.size() ;});
        vector<int> encwords(words.size(), 0);
        for (int i = 0; i < encwords.size(); i++) {
            encwords[i] = str2int(words[i]);
        }
        int res = 0;
        for (int l = 0, r = encwords.size() - 1; l < r; r--) {
            int lastl = -1;
            for (int i = l; i < r; i++) {
                if (!(encwords[i] & encwords[r])) {
                    lastl = i;
                }
            }
            if (lastl != -1) {
                res = max(res, (int)words[lastl].size() * (int)words[r].size());
                l = lastl + 1;
            }
        }
        return res;
    }
private:
    int str2int(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res |= 1 << (s[i] - 'a');
        }
        return res;
    }
};
