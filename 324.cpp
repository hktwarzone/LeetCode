/*
324. Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = kth_elem(nums, 0, n - 1, n / 2 + 1);
        // vector<int>::iterator nth = next(nums.begin(), n / 2); 
        // nth_element(nums.begin(), nth, nums.end());
        // int mid = *nth;
        int smaller = 0;
        int larger = n - 1;
        for (int i = 0; i <= larger;) {
            int newi = newind(i, n);
            if (nums[newi] < mid) {
                int tmp = nums[newi];
                nums[newi] = nums[newind(smaller, n)];
                nums[newind(smaller, n)] = tmp;
                smaller++; i++;
            }
            else if (nums[newi] > mid) {
                int tmp = nums[newi];
                nums[newi] = nums[newind(larger, n)];
                nums[newind(larger, n)] = tmp;
                larger--;
            }
            else i++;
        }
    }
private:
    int newind(int i, int n) {
        if (2 * i < n) return 2 * ((n - 1) / 2) - 2 * i;
        else return 2 * (n - 1 - i) + 1;
    }
    int kth_elem(vector<int>& nums, int start, int end, int k) {
        int pivotIndex = start + rand() % (end - start + 1);
        int pivot = nums[pivotIndex];
        nums[pivotIndex] = nums[end];
        nums[end] = pivot;
        int firstLarge = start;
        for (int i = start; i < end; i++) {
            if (nums[i] <= pivot) {
                int tmp = nums[firstLarge];
                nums[firstLarge++] = nums[i];
                nums[i] = tmp;
            }
        }
        int tmp = nums[firstLarge];
        nums[firstLarge] = nums[end];
        nums[end] = tmp;
        if (firstLarge - start == k - 1) return nums[firstLarge];
        else if (firstLarge - start > k - 1) return kth_elem(nums, start, firstLarge - 1, k);
        else return kth_elem(nums, firstLarge + 1, end, k - (firstLarge - start + 1));
    }
};
