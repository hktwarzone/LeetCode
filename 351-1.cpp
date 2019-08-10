/*
351. Android Unlock Patterns 
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number 
of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must 
have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> state(10, false);
        int count = 0;
        for (int i = m; i <= n; i++) {
            for (int j = 1; j <= 9; j++) {
                state[j] = true;
                pattern(j, state, i, count);
                state[j] = false;
            }
        }
        return count;
    }
private:
    void pattern(int curr, vector<bool>& state, int n, int& count) {
        if (n == 1) {
            count++;
            return;
        }
        if (curr == 1) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if ((i == 3 && !state[2]) || (i == 7 && !state[4]) || (i == 9 && !state[5])) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 2) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if (i == 8 && !state[5]) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 3) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if ((i == 1 && !state[2]) || (i == 7 && !state[5]) || (i == 9 && !state[6])) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 4) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if (i == 6 && !state[5]) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 5) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 6) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if (i == 4 && !state[5]) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 7) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if ((i == 1 && !state[4]) || (i == 3 && !state[5]) || (i == 9 && !state[8])) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else if (curr == 8) {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if (i == 2 && !state[5]) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
        else {
            for (int i = 1; i <= 9; i++) {
                if (!state[i]) {
                    if ((i == 3 && !state[6]) || (i == 1 && !state[5]) || (i == 7 && !state[8])) continue;
                    state[i] = true;
                    pattern(i, state, n - 1, count);
                    state[i] = false;
                }
            }
        }
    }
};
