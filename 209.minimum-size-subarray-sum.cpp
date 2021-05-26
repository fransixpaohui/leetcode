/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 * 
 * 前面前缀和加滑动窗口做得稀烂！
 * 
 * 后面滑动窗口
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        vector<int> sum(nums);
        int ans = sum.size();
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                sum[i] += sum[i - 1];
            }
        }
        if (sum[sum.size() - 1] < target) {
            return 0;
        } else if (sum[sum.size() - 1] == target) {
            return sum.size();
        } else {
            int i = 0, j = 0;
            while (j < sum.size()) {
                if (sum[j] >= target) {
                    ans = min(ans, j + 1);
                }
                if (sum[j] - sum[i] >= target) {
                    ans = min(ans, j - i);
                    i++;
                } else {
                    if (j < nums.size() - 1) {
                        j++;
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }


    int minSubArrayLen(int target, vector<int>& nums)
    {
        int start = 0, end = 0, sum = nums[0], ans = nums.size()+1;
        while (end < nums.size()) {
            while (sum >= target) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
            if (end < nums.size()) {
                sum += nums[end];
            }
        }
        if(ans==nums.size()+1) return 0;
        return ans;
    }
};
// @lc code=end
