/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 * 
 * 心累，还是没想到用单调栈
 */

// @lc code=start
class Solution {
public:
    /* 超时 
    int sumSubarrayMins(vector<int>& arr)
    {
        int res = 0;
        int limit = (int)pow(10, 9) + 7;
        for (int i = 0; i < arr.size(); i++) {
            int min = arr[i];
            for (int j = i; j < arr.size(); j++) {
                if (min > arr[j]) {
                    min = arr[j];
                }
                if (limit - res < min) {
                    res %= limit;
                }
                res += min;
            }
        }
        return res;
    }
    */
    int sumSubarrayMins(vector<int>& arr)
    {
        arr.push_back(0);
        stack<int> st;
        int res = 0, limit = (int)pow(10, 9) + 7;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int index = st.top();
                st.pop();
                res += ((long long)arr[index] * (i - index)) % limit;
                if (st.empty()) {
                    res += ((long long)arr[index] * (i - index) * index) % limit;
                } else {
                    res += ((long long)arr[index] * (index - st.top() - 1) * (i - index)) % limit;
                }
                if (res >= limit) {
                    res %= limit;
                }
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
