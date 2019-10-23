/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (36.86%)
 * Likes:    1491
 * Dislikes: 126
 * Total Accepted:    154.2K
 * Total Submissions: 415.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
/*
    Generate TreeNode with range (1 to n).
    root(1)->right(2)->right(3).
    Dynamic Programming.
    When extended to 1,2,3,4, we may can use the intermediate result.

 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return _generateTree(1, n);
    }
    vector<TreeNode*> _generateTree(int s, int e){
        // Can not return {}, for we will use it in for loop.
        if(s>e) return {nullptr};
        if(s==e) return {new TreeNode(s)};
        vector<TreeNode*> trees;
        for(auto i = s; i <= e; i++){
            auto left_trees  = _generateTree(s, i-1);
            auto right_trees = _generateTree(i+1, e);
            for(auto& l : left_trees)
                for(auto& r: right_trees){
                    auto t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    trees.push_back(t);
                }
        }
        return trees;
    }
};

// vector<TreeNode*> genTreesUtil(int beg, int end) {
// 	if (end < beg) return { nullptr };
// 	if (end == beg) return { new TreeNode(beg) };

// 	vector<TreeNode*> trees;
// 	for (int i = beg; i <= end; ++i) {

// 		auto leftTrees = genTreesUtil(beg, i - 1);
// 		auto rightTrees = genTreesUtil(i + 1, end);

// 		for (auto& l : leftTrees)
// 			for (auto& r : rightTrees) {
// 				auto t = new TreeNode(i);
// 				t->left = l;
// 				t->right = r;

// 				trees.push_back(t);
// 			}
// 	}

// 	return trees;
// }

// vector<TreeNode*> generateTrees(int n) {
// 	if (n == 0) return {};
// 	return genTreesUtil(1, n);
// }

