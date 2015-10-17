/*
Palindrome Permutation
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> ht;
        for (int i = 0; i < s.size(); i++) {
            if (ht.find(s[i]) == ht.end()) {
                ht[s[i]] = 1;
            }
            else ht[s[i]]++;
        }
        int count = 0;
        for (auto it = ht.begin(); it != ht.end(); it++) {
            if (it->second & 1) {
                count++;
                if (count == 2) return false;
            }
        }
        return true;
    }
};
