/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * Binary Search 经典二分法，值得多做，两种模板都用到了
 * 
 * 两种模板区别在于判定条件以及右边缩减的方式不同
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int start = low;
        low = 0, high = nums.size() - 1;
        //*
        if (target <= nums[high] && target >= nums[start]) {
            low = start;
        } else {
            high = start;
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
