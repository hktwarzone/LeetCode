/*
269. Alien Dictionary

There is a new alien language which uses the latin alphabet. 
However, the order among letters are unknown to you. You receive a list 
of non-empty words from the dictionary, where words are sorted lexicographically 
by the rules of this new language. Derive the order of letters in this language.

Example
Example 1:

Input：["wrt","wrf","er","ett","rftt"]
Output："wertf"
Explanation：
from "wrt"and"wrf" ,we can get 't'<'f'
from "wrt"and"er" ,we can get 'w'<'e'
from "er"and"ett" ,we can get 'r'<'t'
from "ett"and"rtff" ,we can get 'e'<'r'
So return "wertf"

Example 2:

Input：["z","x"]
Output："zx"
Explanation：
from "z" and "x"，we can get 'z' < 'x'
So return "zx"
*/

// There may be multiple valid order of letters, return the smallest in normal lexicographical order

class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        unordered_map<char, vector<char>> children;
        unordered_map<char, int> referenced;
        for (int i = 0; i < words.size() - 1; i++) {
            int sa = words[i].size();
            int sb = words[i + 1].size();
            bool found = false;
            for (int j = 0; j < max(sa, sb); j++) {
                if (j < sa && referenced.find(words[i][j]) == referenced.end()) referenced[words[i][j]] = 0;
                if (j < sb && referenced.find(words[i + 1][j]) == referenced.end()) referenced[words[i + 1][j]] = 0;
                if (j < min(sa, sb) && words[i][j] != words[i + 1][j] && !found) {
                    found = true;
                    children[words[i][j]].push_back(words[i + 1][j]);
                    referenced[words[i + 1][j]]++;
                }
            }
        }
        set<char> q;
        for (auto r : referenced) {
            if (r.second == 0) {
                q.insert(r.first);
            }
        }
        string res = "";
        while(!q.empty()) {
            char t = *q.begin();
            q.erase(q.begin());
            res += t;
            for (char n : children[t]) {
                referenced[n]--;
                if (referenced[n] == 0) q.insert(n);
            }
        }
        for (auto r2 : referenced) {
            if (r2.second > 0) {
                return "";
            }
        }
        return res;
    }
};
