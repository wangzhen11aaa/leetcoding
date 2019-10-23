/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (50.38%)
 * Likes:    1897
 * Dislikes: 173
 * Total Accepted:    290.7K
 * Total Submissions: 573.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Note:
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * Example 1:
 * 
 * 
 * Given input matrix = 
 * [
 * ⁠ [1,2,3],
 * ⁠ [4,5,6],
 * ⁠ [7,8,9]
 * ],
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [7,4,1],
 * ⁠ [8,5,2],
 * ⁠ [9,6,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Given input matrix =
 * [
 * ⁠ [ 5, 1, 9, 11],
 * ⁠ [ 2, 4, 8,10],
 * ⁠ [13, 3, 6, 7],
 * ⁠ [15,14,12,16]
 * ], 
 * 
 * rotate the input matrix in-place such that it becomes:
 * [
 * ⁠ [15,13, 2, 5],
 * ⁠ [14, 3, 4, 1],
 * ⁠ [12, 6, 8, 9],
 * ⁠ [16, 7,10,11]
 * ]
 * 
 * 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int matrix_size = matrix.size();
       cout << "matrix size" << matrix_size;
       if(matrix_size == 1) return;
       int magic_number = matrix_size - 1;
       int count = matrix_size / 2;
       cout << "count :" << count;
       int move_count = matrix_size -1;
       for(int i=0; i<count;i++){
           cout << "move count" << move_count;
           int s_i;
           s_i = i; 
           for(int j = 0; j < move_count; j++){
               int _s_i = s_i;
               int _s_j = _s_i + j;
               int to_move = matrix[_s_i][_s_j];
               for(auto c = 0; c < 4; c++){
                   //int to_replace_s_i, to_replace_s_j;
                   int to_replace_s_i = _s_j;
                   int to_replace_s_j = magic_number - _s_i;
                   int to_replace = matrix[to_replace_s_i][to_replace_s_j];
                   matrix[to_replace_s_i][to_replace_s_j] = to_move;
                   to_move = to_replace;
                   _s_i = to_replace_s_i;
                   _s_j = to_replace_s_j;
               }
           }
        move_count -= 2;

       }
    }
};

