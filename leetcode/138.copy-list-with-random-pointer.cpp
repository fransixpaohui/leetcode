/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 * 深拷贝 ：复件与原件毫无联系，即复件改变不改变原件
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> memo;
        Node *temp = head, *deepNode = new Node(0), *tempDeep = deepNode;
        while (temp) {
            tempDeep->next = new Node(temp->val);
            memo[temp] = tempDeep->next;
            tempDeep = tempDeep->next;
            temp = temp->next;
        }
        temp = head;
        tempDeep = deepNode->next;
        while (temp) {
            tempDeep->random = memo[temp->random];
            temp = temp->next;
            tempDeep = tempDeep->next;
        }
        return deepNode->next;
    }
};
// @lc code=end
