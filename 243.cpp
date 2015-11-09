/*
Shortest Word Distance
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> w1;
        vector<int> w2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) w1.push_back(i);
            if (words[i] == word2) w2.push_back(i);
        }
        int p1 = 0;
        int p2 = 0;
        int res = INT_MAX;
        while(p1 < w1.size() && p2 < w2.size()) {
            res = min(res, abs(w1[p1] - w2[p2]));
            if (w1[p1] < w2[p2]) p1++;
            else p2++;
        }
        return res;
    }
};
