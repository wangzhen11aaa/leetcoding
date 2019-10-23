/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.96%)
 * Likes:    1741
 * Dislikes: 44
 * Total Accepted:    426K
 * Total Submissions: 852.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
// space complexity max(for i:0 to height of tree, nodes num of tree level i)
// Get a List of Nodes, which stores the list to be accessed and it is initialized to 
// root, and when it is to be out of while cyle, it will be loaded his children.
//

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<TreeNode *> nodesList;
        nodesList.push_back(root);
        while (!nodesList.empty())
        {
            //Iterate nodeList and get all values.
            vector<int> values_list;
            for (int i = 0; i < n; i++)
            {
                values_list.push_back(nodesList[i]->val);
                if (nodesList[i]->left)
                    nodesList.push_back(nodesList[i]->left) 
                if (nodesList[i]->right)
                    nodesList.push_back(nodesList[i]->right);
            }
            nodesList.erase(nodesList.begin(), nodesList.begin() + n);
            res.push_back(values_list);
        }
        return res;
    }
};

