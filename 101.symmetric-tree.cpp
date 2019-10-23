/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.29%)
 * Likes:    2596
 * Dislikes: 56
 * Total Accepted:    454.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkSymmetric(root->left, root->right);
    }
    bool checkSymmetric(TreeNode* left_child, TreeNode* right_child){
        if(left_child == nullptr && nullptr ==right_child) return true;
        if(left_child&&!right_child || !left_child&&right_child) return false;
        else{
            return (left_child->val == right_child->val) && checkSymmetric(left_child->left, right_child->right) && checkSymmetric(left_child->right, right_child->left); 
        }
    }
    // int preLeftTraverse(TreeNode * root){
    //     if(!root) return 0;
    //     else {
    //         preLeftTraverse(root->left);
    //         preLeftTraverse(root->right);
    //         return root->val;
    //     }
    // }
    // int preRightTraverse(TreeNode *root){
    //     if(!root) return 0;
    //     else{
    //         preRightTraverse(root->right);
    //         preRightTraverse(root->left);
    //         return root->val;
    //     }
    // }
};

