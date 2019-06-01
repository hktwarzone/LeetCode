/*
214. Shortest Palindrome

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        // find longest palindrome prefix of s
        int i = 0;
        int n = s.size();
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) i++;
        }
        // we can make sure s.substr(i) is not inside longest palindrome prefix
        // because we cannot find its corresponding char in s
        if (i == n) return s;
        string r = s.substr(i);
        reverse(r.begin(), r.end());
        return r + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};
