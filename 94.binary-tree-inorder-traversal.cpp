/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.27%)
 * Likes:    1985
 * Dislikes: 90
 * Total Accepted:    536.2K
 * Total Submissions: 913.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//<1> First put root node into the stack. If root node has left node, add left node into stack, else pop the item out the
// stack, If the item has right value, execute <1>. Else pop item again.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res{};
        if(root==nullptr) return res;
        vector<TreeNode*> stack;
        stack.push_back(root);
        // Store the inner node's value.
        while(stack.size()){
            // If root is not null and root has left child. 
            // No nullptr is added into the stack.
            while(root != nullptr && root->left){
                stack.push_back(root->left);
                root=root->left;
            }
            auto pivot = stack.back();
            stack.pop_back();
            // Pop the leftest child.
            res.push_back(pivot->val);
            root = pivot->right;
            // New root, if root has right child. Make the cycle go on.
            if(root){
                stack.push_back(root);
            }
        }
        return res;
    }
};

