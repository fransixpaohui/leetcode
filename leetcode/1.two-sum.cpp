// @before-stub-for-debug-begin

// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * 必须遍历时是往之前的节点中寻找 target - nums[i],否则下面一句会有问题，即有可能最后一个是数是两数之一
 * memoIndcice.find() != memoIndice.end()->second
 */

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> memoIndice;
        for (int i = 0; i < nums.size(); i++) {
            if (memoIndice.find(target - nums[i]) != memoIndice.end()) {
                return {i, memoIndice[target - nums[i]]};
            }
            memoIndice[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
