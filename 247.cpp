/*
47. Strobogrammatic Number II 
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> strobos;
        if (n & 1) strobos = {"0", "1", "8"};
        else strobos = {""};
        vector<string> bases = {"00", "11", "69", "88", "96"};
        while (n > 1) {
            n -= 2;
            vector<string> temp;
            for (int i = 0; i < strobos.size(); i++) {
                for (int j = (n < 2) ? 1 : 0; j < bases.size(); j++) {
                    temp.push_back(bases[j].substr(0, 1) + strobos[i] + bases[j].substr(1));
                }
            }
            swap(temp, strobos);
        }
        return strobos;
    }
};
