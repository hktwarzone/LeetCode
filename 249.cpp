/*
249. Group Shifted Strings
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". 
We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> ht;
        for (int i = 0; i < strings.size(); i++) {
            int diff = strings[i][0] - 'a';
            string key = strings[i];
            for (int j = 0; j < strings[i].size(); j++) {
                char c = strings[i][j] - diff;
                if (c < 'a') c += 26;
                key[j] = c;
            }
            ht[key].push_back(strings[i]);
        }
        vector<vector<string>> res;
        for (auto it = ht.begin(); it != ht.end(); it++) {
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};
