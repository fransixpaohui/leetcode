/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 * 
 * 思路：先用二分法找到taget的index，再对两边进行二叉搜索分别找到最左最右index
 * 
 * 二分法，后面两个while的中二分法用法很巧妙，避免了循环，这题用了两种二分法思路，适合打基础
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, intr = -1;
        if(h<0) return {-1,-1};
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) {
                intr = mid;
                break;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                h = mid - 1;
            }
        }
        if (intr == -1) return {-1, -1};

        int l1 = 0, h1 = intr;
        while (l1 <= h1) {
            if (l1 == h1) break;
            int mid = (l1 + h1) / 2;
            if (nums[mid] < target) {
                l1 = mid + 1;
            } else if (nums[mid] == target) {
                h1 = mid;
            }
        }
        int l2 = intr, h2 = nums.size() - 1;
        while (l2 <= h2) {
            if (l2 == h2) break;
            int mid = (l2 + h2 + 1) / 2;
            if (nums[mid] > target) {
                h2 = mid - 1;
            } else if (nums[mid] == target) {
                l2 = mid;
            }
        }
        return {l1, h2};
    }
};
// @lc code=end
