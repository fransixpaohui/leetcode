/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 * 
 * 第一次，没写出来，对于排序数组首尾双指针的理解不够
 */

// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int head = i + 1, tail = nums.size() - 1;
            while (head < tail) {
                int tempSum = nums[i] + nums[head] + nums[tail];
                if (abs(tempSum - target) < abs(sum - target)) sum = tempSum;
                //*
                if (tempSum < target) {
                    head++;
                } else if (tempSum > target) {
                    tail--;
                } else {
                    return target;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
