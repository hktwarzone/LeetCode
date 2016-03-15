/*
336. Palindrome Pairs 
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation 
of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.empty()) return res;
        unordered_map<string, int> ht;
        for (int i = 0; i < words.size(); i++) {
            ht[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                if (isPalin(words[i], 0, j - 1)) {
                    string tmp = words[i].substr(j);
                    reverse(tmp.begin(), tmp.end());
                    if (ht.find(tmp) != ht.end() && ht[tmp] != i) {
                        res.push_back(vector<int>{ht[tmp], i});
                    }
                }
                if (isPalin(words[i], j, words[i].size() - 1)) {
                    string tmp = words[i].substr(0, j);
                    reverse(tmp.begin(), tmp.end());
                    if (ht.find(tmp) != ht.end() && ht[tmp] != i && tmp.size() != words[i].size()) {
                        res.push_back(vector<int>{i, ht[tmp]});
                    }
                }
            }
        }
        return res;
    }
private:
    bool isPalin(string& s, int start, int end) {
        while(start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};
