/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.07%)
 * Likes:    1164
 * Dislikes: 68
 * Total Accepted:    249.4K
 * Total Submissions: 578.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<TreeNode *> nodesList;
        nodesList.push_back(root);
        bool left2right = true;
        while (!nodesList.empty())
        {
            //Iterate nodeList and get all values.
            vector<int> values_list;
            int n = nodesList.size();
            for (int i = 0; i < n; i++)
            {
                values_list.push_back(nodesList[i]->val);
                if (left2right)
                {
                    if (nodesList[i]->left)
                        nodesList.push_back(nodesList[i]->left);
                    if (nodesList[i]->right)
                        nodesList.push_back(nodesList[i]->right);
                }
                else{
                    cout << "here" << endl;
                    if (nodesList[i]->right)
                        nodesList.push_back(nodesList[i]->right);
                    if(nodesList[i]->left)
                        nodesList.push_back(nodesList[i]->left);
                }
            }
            left2right = left2right?false:true;
            nodesList.erase(nodesList.begin(), nodesList.begin() + n);
            res.push_back(values_list);
            reverse(nodesList.begin(), nodesList.end());
        }
        return res;
    }
};
