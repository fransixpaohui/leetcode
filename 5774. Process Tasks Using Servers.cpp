/*
 * @lc app=leetcode id=1882 lang=cpp
 *
 * [1882] Process Tasks Using Servers
 * 
 * 第一次知道优先队列priority_queue、emplace函数以及pair的初步使用
 */

// @lc code=start
class Solution {
private:
    using PII = pair<int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
    {
        int n = servers.size();
        //定义优先队列
        priority_queue<PII, vector<PII>, greater<PII>> busy; //end time : index
        priority_queue<PII, vector<PII>, greater<PII>> avai; //weight : index
        for (int i = 0; i < n; i++) {
            avai.emplace(servers[i], i);
        }
        int ts = 0, i = 0; //ts是当前时间，i是任务下标，页式任务开始下标
        vector<int> res;
        while (i < tasks.size()) {
            //更新busy队列和avai队列
            while (!busy.empty() && busy.top().first <= ts) {
                int index = busy.top().second;
                avai.emplace(servers[index], index);
                busy.pop();
            }
            //分配服务器
            while (!avai.empty() && i < tasks.size() && i <= ts) {
                int index = avai.top().second;
                busy.emplace(ts + tasks[i], index);
                res.push_back(index);
                avai.pop();
                i++;
            }
            //这一秒结束,如果没有可用服务器，那么可以跳到最快空出服务器的时间
            if (avai.empty()) {
                ts = busy.top().first;
            } else {
                ts++;
            }
        }
        return res;
    }
};
// @lc code=end