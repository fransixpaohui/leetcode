/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>sum(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i>0) sum[i]=sum[i-1]+nums[i];
            else sum[i]=nums[i];
        }
        map<int,int>memo;
        memo[0]=1;
        int res=0;
        for(int i=0;i<sum.size();i++){
            res+=memo[sum[i]-k];
            memo[sum[i]]++;
        }
        return res;
    }
};
// @lc code=end

