/*

186. Reverse Words in a String II

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    string reverseWords(string &str) {
        int start = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                reverse(str.begin() + start, str.begin() + i);
                start = i + 1; 
            }
        }
        reverse(str.begin() + start, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};
