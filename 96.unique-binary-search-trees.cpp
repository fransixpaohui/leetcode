/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    /*
     * 列式构造dp关系
     */
    int numTrees(int n)
    {
        vector<int> count(n + 1); //count[i]用于表示共i个数的BST个数
        count[0] = 1; //方便计算
        count[1] = 1;
        for (int i = 2; i <= n; i++) { //i表示总共有i个节点
            for (int j = 1; j <= i; j++) { //j表示以j为节点
                count[i] += count[j - 1] * count[i - j];
            }
        }
        return count[n];
    }
};
// @lc code=end
