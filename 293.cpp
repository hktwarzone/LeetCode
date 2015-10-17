class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.size() < 2) return res;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string news = s;
                news[i] = '-';
                news[i + 1] = '-';
                res.push_back(news);
            }
        }
        return res;
    }
};
