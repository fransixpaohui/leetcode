/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 * 
 * 递归写的，还是很慢
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    void recursive(vector<int>& temp, int k, int t, int n)
    {
        temp.push_back(t);
        if (k == 1 && n == t) {
            res.push_back(temp);
            return;
        }
        for (int i = t + 1; i <= 9; i++) {
            if (n - t < t) {
                break;
            }
            recursive(temp, k - 1, i, n - t);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        for (int i = 1; i <= 9; i++) {
            recursive(temp, k, i, n);
            temp.pop_back();
        }
        return res;
    }
};
// @lc code=end
