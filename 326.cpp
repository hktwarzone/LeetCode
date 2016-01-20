/*
326. Power of Three 
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        double m = log(n)/log(3);
	    return (pow(3, int(m)) == n || pow(3, int(m + 1)) == n);
    }
};
