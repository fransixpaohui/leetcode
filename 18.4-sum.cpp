/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * 开始以为有两个两个相加的算法，时间复杂度为O(n^2)，看题解都是用三数之和
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> res;
    void threeSum(vector<int>& nums, int i, int target) {
        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int head = j + 1, tail = nums.size() - 1, temp = target - nums[j];
            while (head < tail) {
                if (nums[head] + nums[tail] == temp) {
                    vector<int> tempRes = {nums[i], nums[j], nums[head],
                                           nums[tail]};
                    res.push_back(tempRes);
                    while (nums[head] == tempRes[2] && head < tail) {
                        head++;
                    }
                    while (nums[tail] == tempRes[3] && tail > head) {
                        tail--;
                    }
                } else if (nums[head] + nums[tail] < temp) {
                    head++;
                } else if (nums[head] + nums[tail] > temp) {
                    tail--;
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            threeSum(nums, i, target - nums[i]);
        }
        return res;
    }
};
// @lc code=end
