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
                if (a[0] == '0' && i > 1) continue;
                string b = num.substr(i, j);
                if (b[0] == '0' && j > 1) continue;
                string c = num.substr(i + j);
                if (c[0] == '0' && c.size() > 1) continue;
                if (additive(a, b, c)) return true;
            }
        }
        return false;
    }
private:
    bool additive(string a, string b, string c) {
        string aplusb = bigAdd(a, b);
        if (aplusb == c) return true;
        if (aplusb.size() >= c.size() || aplusb != c.substr(0, aplusb.size())) return false;
        return additive(b, c.substr(0, aplusb.size()), c.substr(aplusb.size()));
    }
    string bigAdd(string& a, string& b) {
        int indexa = a.size() - 1;
        int indexb = b.size() - 1;
        string res;
        int carry = 0;
        while(indexa >= 0 || indexb >= 0 || carry > 0) {
            int sum = carry; 
            if (indexa >= 0) sum += (a[indexa--] - '0');    
            if (indexb >= 0) sum += (b[indexb--] - '0');
            carry = sum / 10;
            res = to_string(sum % 10) + res;
        }
        return res;
    }
};
