/*
320. Generalized Abbreviation My Submissions Question

Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        recurAbbr(res, word, 0, "", 0);
        return res;
    }
private:
    void recurAbbr(vector<string>& res, string& word, int start, string curr, int count) {
        if (start == word.size()) {
            if (count > 0) curr += to_string(count);
            res.push_back(curr);
            return;
        }
        recurAbbr(res, word, start + 1, curr, count + 1);
        if (count > 0) curr += to_string(count);
        curr += word[start];
        recurAbbr(res, word, start + 1, curr, 0);
    }
};
