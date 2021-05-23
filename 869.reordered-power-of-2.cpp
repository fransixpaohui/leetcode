/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 * 
 * 利用数组v[10]获取n中0~9的这10个digit的个数
 * 然后与有符号整型数2的0~31次幂进行比较
 * 注意32位有符号整型数的大小（21亿多）
 * 注意位运算
 */

// @lc code=start
class Solution {
   public:
    vector<int> counter(int n) {
        vector<int> v(10);
        while (n) {
            v[n % 10]++;
            n /= 10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> c = counter(n);
        for(int i = 0; i < 31; i++) {
            if (counter(1 << i) == c) return true;
        }
        return false;
    }
};
// @lc code=end
