/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    //* 暴力解法，应该会超时
    int maxProduct(vector<int>& nums) {
        vector<int>res=nums;
        for(int i=0;i<nums.size();i++){
            int tProd=nums[i];
            for(int j=i-1;j>=0;j--){
                tProd*=nums[j];
                res[i]=max(tProd,res[i]);
                if(nums[j]==0){
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res[res.size()-1];
    }


    /*
     * dp做法，加上空间优化（滚动数组）
     * 
     * 因为存在负数，所以可以用两个状态最大最小来创建方程
     * 
     * 用minf、maxf分别表示以i为有边界的乘积的最小与最大值
     */
    int maxProduct(vector<int>& nums)
    {
        int minf = nums[0], maxf = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int mn = minf, mx = maxf;
            minf = min(mn * nums[i], min(nums[i] * mx, nums[i]));
            maxf = max(mx * nums[i], max(nums[i] * mn, nums[i]));
            ans = max(ans, maxf);
        }
        return ans;
    }
};
// @lc code=end
