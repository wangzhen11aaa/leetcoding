/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.93%)
 * Likes:    1446
 * Dislikes: 151
 * Total Accepted:    303.4K
 * Total Submissions: 572.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive create the tree.
// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int size = nums.size();
//         TreeNode * root = nullptr;
//         if(size == 0) return root;
//         else if(size == 1) return new TreeNode(nums[0]);
//         else{
//             root = constructTree(0, size - 1, nums);
//         }
//         return root;
//     }
//     TreeNode* constructTree(int start, int end, vector<int>& nums){
//         TreeNode *root = new TreeNode(0);
//         //int mid = (start + end) / 2;
//         if(start >= end) return nullptr;
//        // if(start > end) {root->val = nums[start]; return root;}
//         else{
//             int mid = (start+end)/2;
//             root->val = nums[mid];
//             root->left = constructTree(start, mid, nums);
//             root->right = constructTree(mid+1, end, nums);
//             return root;
//         }
//     }
// };
class Solution {
public:
    TreeNode* venom = nullptr;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return go(nums,0,nums.size());
    }
    
    TreeNode* go(vector<int>& nums,int start,int end){
        if (start >= end){
            return venom;
        }
        int middle = (start + end)/2;
        
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = go(nums,start,middle);
        root->right = go(nums,middle+1,end);
        
        return root;
    }
};
// @lc code=end

