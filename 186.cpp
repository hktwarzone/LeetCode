/*
Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

*/

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0;
        while(i < s.size()) {
            while(s[i] == ' ') { i++; }
            int left = i;
            while(i < s.size() && s[i] != ' ') { i++; }
            int right = i - 1;
            while(left < right) {
                char tmp = s[left];
                s[left++] = s[right];
                s[right--] = tmp;
            }
        }
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};
