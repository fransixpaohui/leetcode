/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 * 
 * sort 中 comp 条件函数需要 static
 * 
 * 非静态成员依赖于具体对象 ，而 std::sort 是全局的，无法在 sort 中调用非静态成员
 */

// @lc code=start
class Solution {
   public:
    static bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int tempS = intervals[i][0];
            int tempE = intervals[i][1];
            if (tempS > end) {　    //上个区间结束
                vector<int> temp = {start, end};
                res.push_back(temp);
                start = tempS;
                end = tempE;
            } else if (tempS == end) {  //合并无重合区间
                end = tempE;
            } else {                   //合并重合区间
                start = min(start, tempS);
                end = max(end, tempE);
            }
        }
        //* 末尾一定会有一段没考虑到
        vector<int> temp = {start, end};
        res.push_back(temp);
        return res;
    }
};
// @lc code=end
