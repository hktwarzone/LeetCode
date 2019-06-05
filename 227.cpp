/*
227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
*/

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int tmp = 0;
        stack<int> t;
        char op = '+';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + (s[i] - '0');
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
                if (op == '-') tmp *= -1;
                else if (op == '*') {
                    tmp = t.top() * tmp;
                    t.pop();
                }
                else if (op == '/') {
                    tmp = t.top() / tmp;
                    t.pop();
                }
                t.push(tmp);
                op = s[i];
                tmp = 0;
            }
        }
        while(!t.empty()) {
            res += t.top();
            t.pop();
        }
        return res;
    }
};
