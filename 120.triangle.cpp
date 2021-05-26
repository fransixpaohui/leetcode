/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 * 
 * 应该是第二次做，但还是没有用dp写，递归超时，淦！！！
 */

// @lc code=start
class Solution {
public:
    //* 利用递归做，最后一个测试点超时
    int getmin(vector<vector<int>> triangle, int total, int i, int j)
    {
        total += triangle[i][j];
        if (i == triangle.size() - 1) {
            return total;
        }
        return min(getmin(triangle, total, i + 1, j),
            getmin(triangle, total, i + 1, j + 1));
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
        return getmin(triangle, 0, 0, 0);
    }

    //* 利用dp做，但是没有空间优化
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> dp = triangle; //动态规划，dp存起点到该点的最小距离
        for (int i = 1; i < triangle.size(); i++) {
            dp[i][0] += dp[i - 1][0]; //最左边一列
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                dp[i][j] += min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
            dp[i][triangle[i].size() - 1] += dp[i - 1][triangle[i - 1].size() - 1]; //最右边一列
        }
        sort(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
        return dp[triangle.size() - 1][0];
    }

    //*由于状态转换只利用到了上面一层的因此可以将空间优化到最后一行的大小
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<int> dp(triangle.size()); //最后一行的个数与总行数相同
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            dp[triangle[i].size() - 1] = dp[triangle[i - 1].size() - 1] + triangle[i][triangle[i].size() - 1];
            for (int j = triangle[i].size() - 2; j > 0; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        sort(dp.begin(), dp.end());
        return dp[0];
    }
};
// @lc code=end
