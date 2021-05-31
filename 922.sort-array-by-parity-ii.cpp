/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int i = 0,j = nums.size() - 1;
        while (i < nums.size() && j > 0) {
            if (nums[i] % 2 == 1 && nums[j] % 2 == 0) {
                swap(nums[i], nums[j]);
                i += 2;
                j -= 2;
            } else if (nums[i] % 2 == 0 && nums[j] % 2 == 0) {
                i += 2;
            } else if (nums[i] % 2 == 1 && nums[j] % 2 == 1) {
                j -= 2;
            } else if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
                i += 2;
                j -= 2;
            }
        }
        return nums;
    }
};
// @lc code=end
