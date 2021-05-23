/*
 * @Author: mikey.zhaopeng
 * @Date: 2021-05-19 13:35:42
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2021-05-19 13:49:52
 */
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 * 
 * 写法很简洁，revuisive写法值得记住
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        else if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode* newNode = new ListNode((l1->val + l2->val) % 10);
        newNode->next = addTwoNumbers(l1->next, l2->next);
        if (l1->val + l2->val >= 10) {
            newNode->next = addTwoNumbers(newNode->next, new ListNode(1));
        }
        return newNode;
    }
};
// @lc code=end
