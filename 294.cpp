class Solution {
public:
    bool canWin(string s) {
        if (s.size() < 2) return false;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string news = s;
                news[i] = '-';
                news[i + 1] = '-';
                if (!canWin(news)) return true;
            }
        }
        return false;
    }
};
