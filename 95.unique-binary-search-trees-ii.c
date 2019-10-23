/*
 * @lc app=leetcode id=95 lang=c
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

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void printNode(struct TreeNode *node) {
  if (!node) {
    printf(" null");
    return;
  }
  printf(" %d", node->val);
  if (node->left) printNode(node->left);
  else printf(" null");
  if (node->right) printNode(node->right);
  else printf(" null");
  return;
}

int catalan(int n) {
  if (n <= 1) return 1;
  return 2*(2*n-1)*catalan(n-1)/(n+1);
}

struct TreeNode *copy(struct TreeNode *head) {
  if (!head) {
    //printf("*** copy received haed == NULL!!! ***\n");
    return NULL;
  }
  struct TreeNode *dup = malloc(sizeof(struct TreeNode));
  dup->val = head->val;
  if (head->left) dup->left = copy(head->left);
  else dup->left = NULL;
  if (head->right) dup->right = copy(head->right);
  else dup->right = NULL;
  return dup;
}

struct TreeNode **getSubTrees(int n, int *size, int val) {
  //printf("getSubTrees entered with n = %d, val = %d\n", n, val);
  struct TreeNode **array;
  if (n == 1) {
    *size = 1;
    array = malloc(sizeof(struct TreeNode*));
    array[0] = malloc(sizeof(struct TreeNode));
    array[0]->val = val;
    array[0]->left = NULL;
    array[0]->right = NULL;
    //printf("returning with n = %d, val = %d\n", n, val);
    return array;
  }
  int Cn = catalan(n), Cn_1 = catalan(n-1);
  struct TreeNode **lArray, **rArray;
  int lSize, rSize;
  array = malloc(sizeof(struct TreeNode*) * Cn);
  for (int i = 0; i < Cn; ++i) {
    array[i] = malloc(sizeof(struct TreeNode));
    //array[i]->val = val;
  }
  lArray = getSubTrees(n-1, &lSize, val);
  rArray = getSubTrees(n-1, &rSize, val+1);
  //printf("CHECK: lSize = %d, rSize = %d, Cn_1 = %d\n", lSize, rSize, Cn_1);
  for (int i = 0; i < lSize; ++i) {
    array[i]->val = val+n-1;
    array[i]->left = lArray[i];
    array[i]->right = NULL;
    array[Cn-1-i]->val = val;
    array[Cn-1-i]->left = NULL;
    array[Cn-1-i]->right = rArray[i];
  }
  int l = lSize;
  struct TreeNode *lCopy, *rCopy;
  for (int i = 1; i < n-1; ++i) {
    lArray = getSubTrees(n-1-i, &lSize, val);
    rArray = getSubTrees(i, &rSize, val+n-i);
    for (int j = 0; j < lSize; ++j) {
      for (int k = 0; k < rSize; ++k) {
        array[l]->val = val+n-1-i;
        lCopy = copy(lArray[j]);
        //printf("assigning array[%d]->left = copy of lArray[%d] (%d)  &lArray[%d] = %p, &lCopy = %p\n", l, j, lArray[j]->val, j, &(lArray[j]), &lCopy);
        array[l]->left = lCopy;
        //array[l]->left = copy(lArray[j]);
        rCopy = copy(rArray[k]);
        //printf("assigning array[%d]->right = copy of rArray[%d] (%d)  &rArray[%d] = %p, &rCopy = %p\n", l, k, rArray[k]->val, k, &(rArray[k]), &rCopy);
        array[l++]->right = rCopy;
        //array[l++]->right = copy(rArray[k]);
      }
    }
  }
  //printf("CHECK: l = %d, Cn - Cn_1 = %d\n", l, Cn - Cn_1);
  *size = Cn;
  //printf("returning with n = %d, val = %d, size = %d\n", n, val, *size);
  return array;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode **generateTrees(int n, int *returnSize) {
  if (!n) {
    *returnSize = 0;
    return NULL;
  }
  struct TreeNode **array = getSubTrees(n, returnSize, 1);
  //printf("generateTrees: *returnSize = %d\n", *returnSize);
  /*for (int i = 0; i < *returnSize; ++i) {
    printf("%d   ", i);
    printNode(array[i]);
    printf("\n");
  }*/
  return array;
}

