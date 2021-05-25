/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 * 
 * 第二次做，做的稀烂
 */

// @lc code=start
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int zeroE = 0, oneS = 0, twoS = nums.size() - 1;
        while (oneS <= twoS) {
            //*保证zeroE之前绝对是0
            if (nums[oneS] == 0) {
                swap(nums[zeroE++], nums[oneS++]);
            }
            //*由于与twoS交换后的nums[i]的值不确定，所以需要再判断一次
            else if (nums[oneS] == 2) {
                swap(nums[oneS], nums[twoS--]);
            }
            //*为1直接跳过 
            else {
                oneS++;
            }
        }
    }
};
// @lc code=end
