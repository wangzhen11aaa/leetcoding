/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.16%)
 * Likes:    865
 * Dislikes: 84
 * Total Accepted:    292.3K
 * Total Submissions: 606.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

// @lc code=start
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ret;
//         if(numRows == 0) return ret;
//         if(numRows >= 1){
//             ret.push_back({1}); 
//         //    return ret;
//         }
//         if(numRows >= 2){
//             ret.push_back({1,1});
//             //return ret;
//         }
//         if(numRows >= 3) {
//             //int previous_row_index = 1;
//             vector<int> _tmp;
//             for(auto r = 3 ; r <= numRows; r++){
//                 //vector<int> _tmp(r,0);
//                 _tmp.push_back(ret[r-2][0]);
//                 //_tmp[0] = ret[r-2][0];
//                 //_tmp[r-1] = ret[r-2][r-2];
//                 for(auto i = 1; i < r - 1; i++)
//                 {
//                     _tmp.push_back(ret[r-2][i-1]+ret[r-2][i]);
//                 }
//                 _tmp.push_back(ret[r-2][r-2]);
//                 ret.push_back(_tmp);
//                 _tmp = {};
//             }
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> sol(numRows);
        if(numRows < 1)
            return sol;
        vector<int> v(1,1);
        sol[0] = v;
        
        for(int i = 1; i < numRows; i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j = 0; j < i - 1; j++){
                v1.push_back(sol[i-1][j] + sol[i-1][j+1]);
            }
            v1.push_back(1);
            sol[i] = v1;
        }
        return sol;
    }
};
// @lc code=end

