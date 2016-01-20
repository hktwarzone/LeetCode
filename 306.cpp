/*
306. Additive Number

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++) {
            for (int j = 1; j <= (num.size() - i) / 2; j++) {
                string a = num.substr(0, i);
                string b = num.substr(i, j);
                string c = num.substr(i + j);
                if (check(a, b, c)) return true;
            }
        }
        return false;
    }
private:
    bool check(string a, string b, string c) {
        string sum = bigAdd(a, b);
        if (sum == c) return true;
        if (sum.size() >= c.size() || sum != c.substr(0, sum.size())) return false;
        return check(b, c.substr(0, sum.size()), c.substr(sum.size()));
    }
    string bigAdd(string a, string b) {
        string c;
        int index1 = a.size() - 1;
        int index2 = b.size() - 1;
        int carry = 0;
        while (index1 >= 0 || index2 >= 0 || carry > 0) {
            int sum = carry;
            if (index1 >= 0) sum += (a[index1--] - '0');
            if (index2 >= 0) sum += (b[index2--] - '0');
            carry = sum / 10;
            sum %= 10;
            c = to_string(sum) + c;
        }
        return c;
    }
};
