/*
163. Missing Ranges

Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example 1

Input:
nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99
Output:
["2", "4->49", "51->74", "76->99"]
Explanation:
in range[0,99],the missing range includes:range[2,2],range[4,49],range[51,74] and range[76,99]
Example 2

Input:
nums = [0, 1, 2, 3, 7], lower = 0 and upper = 7
Output:
["4->6"]
Explanation:
in range[0,7],the missing range include range[4,6]

*/

class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> result;
        int64_t left = lower;
        int64_t right = 0;
        if (!nums.empty()) {
            addString(left, (int64_t)nums[0] - 1, result);
            for (int i = 0; i < nums.size() - 1; i++) {
                left = (int64_t)nums[i] + 1;
                right = (int64_t)nums[i + 1] - 1;
                addString(left, right, result);
            }
            left = (int64_t)nums[nums.size() - 1] + 1;
        }
        addString(left, upper, result);
        return result;
    }
private:
    void addString(int64_t left, int64_t right, vector<string>& result) {
        string tmp;
        if (left < right) {
            tmp += to_string(left);
            tmp += "->";
            tmp += to_string(right);
        }
        else if (left == right) {
            tmp += to_string(left);
        }
        if (!tmp.empty()) result.push_back(tmp);
    }
};
