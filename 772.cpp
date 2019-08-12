/*
772. Basic Calculator III

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647]

Example
Example 1:

Input："1 + 1"
Output：2
Explanation：1 + 1 = 2
Example 2:

Input：" 6-4 / 2 "
Output：4
Explanation：4/2=2，6-2=4
*/

class Solution {
public:
    /**
     * @param s: the expression string
     * @return: the answer
     */
    int calculate(string &s) {
        int n = s.size();
        return calc(s, 0, n - 1);
    }
private:
    int calc(string& s, int start, int end) {
        char op = '+';
        long last = 0, tmp = 0, res = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + (s[i] - '0');
            }
            if (s[i] == '(') {
                int j = i, cnt = 0;
                while(i <= end) {
                    if (s[i] == '(') cnt++;
                    if (s[i] == ')') cnt--;
                    if (cnt == 0) break;
                    i++;
                }
                tmp = calc(s, j + 1, i - 1);
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == end) {
                switch(op) {
                    case '+' : last += tmp; break;
                    case '-' : last -= tmp; break;
                    case '*' : last *= tmp; break;
                    case '/' : last /= tmp; break;
                }
                if (s[i] == '+' || s[i] == '-' || i == end) {
                    res += last;
                    last = 0;
                }
                tmp = 0;
                op = s[i];
            }
        }
        return res;
    }
};
