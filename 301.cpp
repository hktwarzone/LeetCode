/*
301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (isValid(s)) {
            res.push_back(s);
            return res;
        }
        unordered_set<string> q;
        q.insert(s);
        while(!q.empty()) {
            unordered_set<string> next;
            for (auto it = q.begin(); it != q.end(); it++) {
                unordered_set<string> children = genChildren(*it);
                for (auto it2 = children.begin(); it2 != children.end(); it2++) {
                    if (isValid(*it2) && next.count(*it2) == 0) {
                        res.push_back(*it2);
                    }
                    next.insert(*it2);
                }
            }
            if (!res.empty()) break;
            q = next;
        }
        return res;
    }
private:
    unordered_set<string> genChildren(string s) {
        unordered_set<string> res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') {
                res.insert(s.substr(0, i) + s.substr(i + 1));
            }
        }
        return res;
    }
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return (count == 0);
    }
};
