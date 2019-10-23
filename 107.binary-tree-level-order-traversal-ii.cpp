/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (48.10%)
 * Likes:    837
 * Dislikes: 160
 * Total Accepted:    247.1K
 * Total Submissions: 513.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> tmp_res;
        if (!root)
            return tmp_res;
        vector<TreeNode *> nodesList;
        nodesList.push_back(root);
        while (!nodesList.empty())
        {
            //Iterate nodeList and get all values.
            vector<int> values_list;
            int n = nodesList.size();
            for (int i = 0; i < n; i++)
            {
                values_list.push_back(nodesList[i]->val);
                if (nodesList[i]->left)
                    nodesList.push_back(nodesList[i]->left);
                if (nodesList[i]->right)
                    nodesList.push_back(nodesList[i]->right);
            }
            nodesList.erase(nodesList.begin(), nodesList.begin() + n);
            tmp_res.push_back(values_list);
        }
        reverse(tmp_res.begin(), tmp_res.end());
        return tmp_res;
    }
};

