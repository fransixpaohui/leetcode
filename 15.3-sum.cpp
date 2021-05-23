/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 * 
 * 数组排序后的首尾双指针用法值得注意
 * 
 * vector<int> triplet={nums[i],nums[front],nums[back]} 这种vector的赋值方式总是忘记
 * 
 * 带*的语句作用是为了防止无限循环，至于去重在第一重for循环之后的if语句
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i], front = i + 1, back = nums.size() - 1;
            if(i>0 && nums[i]==nums[i-1]) continue;
            while (front < back) {
                if (nums[front] + nums[back] < target) {
                    front++;
                } else if (nums[front] + nums[back] > target) {
                    back--;
                } else {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    ans.push_back(triplet);
                    //*
                    while(front<back && nums[front]==triplet[1]) front++;
                    //*
                    while(back>front && nums[back]==triplet[2]) back--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
