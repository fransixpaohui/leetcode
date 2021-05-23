/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 * 
 * use vector<int> temp(matrix[0]) or vector<int>tmep=matrix[0] to initialize
 */

// @lc code=start
class Solution {
   public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<int> temp(matrix[0]);
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = matrix[i].size() - 1; j >= 0; j--) {
                if (j > 0 && matrix[i][j] != temp[j - 1]) return false;
            }
            temp=matrix[i];
        }
        return true;
    }
};
// @lc code=end
