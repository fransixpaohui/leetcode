/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
   public:
    bool traval(vector<vector<char>>& b, string w, int k,
                vector<vector<bool>>& memo, int i, int j) {
        if(k==w.size()-1){
            if(b[i][j]==w[k]){
                return true;
            }else{
                return false;
            }
        }
        if(w[k]!=b[i][j]){
            return false;
        }
        memo[i][j] = true;
        if (j < b[0].size()-1 && !memo[i][j + 1]) {
            if (traval(b, w, k + 1, memo, i, j + 1)) {
                return true;
            }
        }
        if (j > 0 && !memo[i][j - 1]) {
            if (traval(b, w, k + 1, memo, i, j - 1)) {
                return true;
            }
        }
        if (i < b.size()-1 && !memo[i + 1][j]) {
            if (traval(b, w, k + 1, memo, i + 1, j)) {
                return true;
            }
        }
        if (i > 0 && !memo[i - 1][j]) {
            if (traval(b, w, k + 1, memo, i - 1, j)) {
                return true;
            }
        }
        memo[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        vector<vector<bool>> memo(b.size(), vector<bool>(b[0].size()));
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < b[0].size(); j++) {
                if (traval(b, w, 0, memo, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
