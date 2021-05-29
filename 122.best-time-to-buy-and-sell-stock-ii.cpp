/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    /*
     * 如果在 i 处可买入，且后续有多个卖出时机，一定是在最大的那个点卖出时赚的最多
     * 
     * 买入点的更新：如果在买入点和卖出点之间存在一个点比买入点还低，那么可以更新买入点为该点
     * 
     * 卖出点的寻找：在其后升序的可卖出点中能找到一点，使得其后的一个点小于该点，则该点为卖出点
     */
    int maxProfit(vector<int>& prices)
    {
        int s = 0, profit = 0;
        while (s < prices.size() - 1) {
            int e = s;
            while (e < prices.size()) {
                //* 这种e的求法使得e一定会是set中所求的卖出点
                if (e < prices.size() - 1 && prices[e + 1] > prices[e]) {
                    e++;
                } else {
                    break;
                }
            }
            //* 在set集中更新s值
            if (e < prices.size() && prices[e] - prices[s] < 0) {
                s = e;
                continue;
            }
            profit += prices[e] - prices[s];
            s = e + 1;
        }
        return profit;
    }
};
// @lc code=end
