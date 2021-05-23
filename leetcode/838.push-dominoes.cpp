/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 *
 * 这题思路用stack记录每个要倒的点，从右往左进行区间判断，有四种情况，以及最后的左边倒
 *
 * 带*的注释表明第一次提交失误
 *
 */
//! leetcode插件在输入字符串测试点时有问题，目前不知道格式

// @lc code=start
class Solution {
   public:
    string pushDominoes(string dominoes) {
        stack<int> s;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] != '.') s.push(i);
        }
        //定义边界boundary，定义区域控制state=1表示出现了左右边界
        int boundary = dominoes.size() - 1, state = 0;
        while (!s.empty()) {
            //如果只出现向右倒
            if (state == 0 && dominoes[s.top()] == 'R') {
                for (int i = s.top(); i <= boundary; i++) {
                    dominoes[i] = 'R';
                }
                boundary = s.top() - 1;
            }
            //左右边界都出现
            else if (state == 1 && dominoes[s.top()] == 'R') {
                int rr, ll;
                if ((s.top() + boundary) % 2 == 0) {
                    rr = (s.top() + boundary) / 2 - 1;
                    ll = (s.top() + boundary) / 2 + 1;
                } else {
                    rr = (s.top() + boundary) / 2;
                    ll = (s.top() + boundary) / 2 + 1;
                }
                for (int i = s.top(); i <= rr; i++) {
                    dominoes[i] = 'R';
                }
                for (int i = ll; i <= boundary; i++) {
                    dominoes[i] = 'L';
                }
                state = 0;
                boundary = s.top() - 1;
            }
            //出现了左边界，向开始有向左倒
            else if (state == 0 && dominoes[s.top()] == 'L') {
                boundary = s.top();
                state = 1;
            }
            //*区间左边倒
            else if (state == 1 && dominoes[s.top()] == 'L') {
                for (int i = s.top(); i < boundary; i++) {
                    dominoes[i] = 'L';
                }
                boundary = s.top();
            }
            s.pop();
        }
        //最后出现了向左倒
        if (state == 1) {
            for (int i = 0; i <= boundary; i++) {
                dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};
// @lc code=end
