/*
Shortest Word Distance II

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and 
your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words 
word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            ht[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int p1 = 0;
        int p2 = 0;
        int res = INT_MAX;
        while(p1 < ht[word1].size() && p2 < ht[word2].size()) {
            res = min(res, abs(ht[word1][p1] - ht[word2][p2]));
            if (ht[word1][p1] < ht[word2][p2]) p1++;
            else p2++;
        }
        return res;        
    }
private:
    unordered_map<string, vector<int>> ht;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
