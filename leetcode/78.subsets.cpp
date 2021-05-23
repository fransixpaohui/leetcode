/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 * 
 * recursive complate
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> res;
    void recursive(vector<int> nums, int i, vector<int> pSol) {
        res.push_back(pSol);
        for (int j = i; j < nums.size(); j++) {
            pSol.push_back(nums[j]);
            recursive(nums, j+1, pSol); 
            pSol.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> pSol;
        recursive(nums, 0, pSol);
        return res;
    }
};
// @lc code=end
