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

//not AC
class TrieNode {
public:
    int index;
    TrieNode* children[26];
    vector<int> prefixes;
    TrieNode() {
        index = -1;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void addWord(string& s, int& si) {
        TrieNode* curr = root;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (curr->children[s[i] - 'a'] == NULL) {
                curr->children[s[i] - 'a'] = new TrieNode();
            }
            if (isPalin(s, 0, i - 1)) curr->children[s[i] - 'a']->prefixes.push_back(si);
            curr = curr->children[s[i] - 'a'];
        }
        curr->index = si;
    }
    void findWord(string& s, int& si, vector<vector<int>>& res) {
        TrieNode* curr = root;
        for (int i = 0; i < s.size(); i++) {
            curr = curr->children[s[i] - 'a'];
            if (!curr) return;
            if (curr->index > 0 && curr->index != si && i < s.size() - 1 && isPalin(s, i + 1, s.size() - 1)) {
                res.push_back(vector<int>{si, curr->index});
            }
        }
        for (int i = 0; i < curr->prefixes.size(); i++) {
            if (curr->prefixes[i] != si) {
                res.push_back(vector<int>{si, curr->prefixes[i]});
            }
        }
    }
    bool isPalin(string& s, int start, int end) {
        while(start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        if (words.empty()) return res;
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.addWord(words[i], i);
        }
        for (int i = 0; i < words.size(); i++) {
            t.findWord(words[i], i, res);
        }
        return res;
    }
};
