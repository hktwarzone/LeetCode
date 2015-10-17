/*
Palindrome Permutation II
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> ht;
        for (int i = 0; i < s.size(); i++) {
            if (ht.find(s[i]) == ht.end()) {
                ht[s[i]] = 1;
            }
            else ht[s[i]]++;
        }
        string str;
        int count = 0;
        char single;
        for (auto it = ht.begin(); it != ht.end(); it++) {
            str += string(it->second/2, it->first);
            if (it->second & 1) {
                count++;
                single = it->first;
                if (count == 2) return res;
            }
        }
        sort(str.begin(), str.end());
        do {
           string tmp = str + (count == 0 ? "" : string(1, single)) + string(str.rbegin(), str.rend());
           res.push_back(tmp);
        }while(next_permutation(str.begin(), str.end()));
        return res;
    }
};
