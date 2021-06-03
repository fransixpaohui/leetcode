/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
     * 递归算法
     */
    vector<int>res;
    void recursive(TreeNode* root){
        if(!root){
            return;
        }
        recursive(root->left);
        res.push_back(root->val);
        recursive(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        recursive(root);
        return res;
    }
    
    /*
     * 非递归算法
     */
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        while (root || !st.empty()) {  //root 为当前节点
            while (root) {  //将当前节点的左孩子入栈，并更新左节点
                st.push(root);
                root = root->left;
            }
            root = st.top();
            res.push_back(root->val);   //访问栈头节点
            st.pop();
            root = root->right; //更新当前节点为栈头节点的右孩子
        }
        return res;
    }
};
// @lc code=end
