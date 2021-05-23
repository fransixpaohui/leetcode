/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, mA = 0;
        while (i < j) {
            mA = max(mA, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return mA;
    }
};
// @lc code=end
