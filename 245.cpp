/*
Shortest Word Distance III

This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        vector<int> w1;
        vector<int> w2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) w1.push_back(i);
            else if (words[i] == word2) w2.push_back(i);
        }
        int res = INT_MAX;
        if (word1 != word2) {
            int p1 = 0;
            int p2 = 0;
            while(p1 < w1.size() && p2 < w2.size()) {
                res = min(res, abs(w1[p1] - w2[p2]));
                if (w1[p1] < w2[p2]) p1++;
                else p2++;
            }
        }
        else {
            for (int i = 0; i < w1.size() - 1; i++) {
                res = min(res, abs(w1[i] - w1[i + 1]));
            }
        }
        return res;        
    }
};
