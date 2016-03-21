/*
246. Strobogrammatic Number       
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> ht;
        ht['0'] = '0';
        ht['1'] = '1';
        ht['6'] = '9';
        ht['8'] = '8';
        ht['9'] = '6';
        for (int l = 0, r = num.size() - 1; l <= r; l++, r--) {
            if (ht.find(num[l]) == ht.end() || ht[num[l]] != num[r]) return false;
        }
        return true;
    }
};
