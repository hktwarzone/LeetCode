/*
Alien Dictionary
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        if (words.size() == 1) return words[0];
        unordered_map<char, vector<char>> prec;
        unordered_map<char, int> ind;
        for (int i = 0; i < words.size() - 1; i++) {
            int i1 = words[i].size();
            int i2 = words[i + 1].size();
            int len = max(i1, i2);
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (j < i1 && ind.find(words[i][j]) == ind.end()) { ind[words[i][j]] = 0; }
                if (j < i2 && ind.find(words[i + 1][j]) == ind.end()) { ind[words[i + 1][j]] = 0; }
                if (j < i1 && j < i2 && words[i][j] != words[i + 1][j] && !found) {
                    prec[words[i][j]].push_back(words[i + 1][j]);
                    ind[words[i + 1][j]]++;
                    found = true;
                }
            }
        }
        queue<char> q;
        for (auto it = ind.begin(); it != ind.end(); it++) {
            if (it->second == 0) q.push(it->first);
        }
        string res;
        while(!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            if (prec.find(c) == prec.end()) continue;
            for (auto it2 = prec[c].begin(); it2 != prec[c].end(); it2++) {
                ind[*it2]--;
                if (ind[*it2] == 0) q.push(*it2);
            }
        }
        for (auto it = ind.begin(); it != ind.end(); it++) {
            if (it->second > 0) return "";
        }
        return res;
    }
};
