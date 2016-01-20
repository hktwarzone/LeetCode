/*
313. Super Ugly Number 
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers 
given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int m = primes.size();
        vector<int> factors(m, 0);
        vector<int> superugly(1, 1);
        while(superugly.size() < n) {
            int min = INT_MAX;
            int minidx = -1;
            for (int j = 0; j < m; j++) {
                int tmp = superugly[factors[j]] * primes[j];
                if (tmp < min) {
                    minidx = j;
                    min = tmp;
                }
            }
            factors[minidx]++;
            if (min == superugly.back()) continue;
            else {
                superugly.push_back(min);
            }
        }
        return superugly.back();
    }
};
