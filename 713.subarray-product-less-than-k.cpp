/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 * 
 * 利用双指针，right遍历整个数组，对于每一个right，都会增加right-left+1个子数组
 * 
 * 对于ABCX，left=0，X为新的right=3，会增加 X,CX,BCX,ABCX 共right-left+1=4个新的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k <= 1) {
            return 0;
        }
        int left = 0, res = 0, prod = 1;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) { //更新left
                prod /= nums[left];
                left++;
            }
            res += right - left + 1; //对于新的right会增加的子数组
        }
        return res;
    }
};
// @lc code=end
