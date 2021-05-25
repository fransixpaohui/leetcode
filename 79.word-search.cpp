/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 * 
 * 写的还是挺费劲的，但是一遍出来了
 */

// @lc code=start
class Solution {
   public:
    bool traval(vector<vector<char>>& b, string w, int k, vector<vector<bool>>& memo, int i, int j) {
        if(k==w.size()-1){          //递归终点判断
            if(b[i][j]==w[k]){
                return true;
            }else{
                return false;
            }
        }
        if(w[k]!=b[i][j]){          //*不满足递归条件，返回
            return false;
        }
        memo[i][j] = true;
        if (j < b[0].size()-1 && !memo[i][j + 1]) {
            if (traval(b, w, k + 1, memo, i, j + 1)) {     //以下类似结构是为了直接返回true，而不返回false，以继续遍历
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
