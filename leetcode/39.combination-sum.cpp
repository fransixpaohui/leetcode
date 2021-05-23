/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 * 
 * using recursive backtracking with a little optimaization
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> result;
    void recursive(vector<int> nums, int next, int target, vector<int> pSol) {
        if (target == 0) {
            result.push_back(pSol);
            return;
        }
        if (next == nums.size() || target < 0) {
            return;
        }
        pSol.push_back(nums[next]);
        recursive(nums, next, target - nums[next], pSol);
        pSol.pop_back();
        //* 加上这一步可以优化一倍的时间
        if (target - nums[next] <= 0) return;
        recursive(nums, next + 1, target, pSol);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> pSol;
        recursive(candidates, 0, target, pSol);
        return result;
    }
};
// @lc code=end
