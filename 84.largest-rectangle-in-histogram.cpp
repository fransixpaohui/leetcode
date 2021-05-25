/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
   public:
    /*
     *（1）求出每个以heights[i]为高的最大矩形面积，取最大值
     *
     *（2）用单调栈实现，如果 height[i]<height[st.top()]
     *    就循环，对 st.top() 进行（1）中计算，
     */
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);  //* 为将单调栈中所有元素pop出
        stack<int> st;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int temp = st.top(), left, right = i;
                st.pop();
                left = st.empty() == true ? -1 : st.top();
                res = max(res, (right - left - 1) * heights[temp]);
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
