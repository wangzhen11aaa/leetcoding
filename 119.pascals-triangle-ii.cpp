/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.38%)
 * Likes:    558
 * Dislikes: 180
 * Total Accepted:    228K
 * Total Submissions: 502.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //vector<int> res;
        vector<int> previous_row;

        if(rowIndex <= 0) return {1};
        if(rowIndex == 1) return {1,1};
        if(rowIndex == 2) return {1,2,1};
        previous_row = {1,1};
        if(rowIndex >= 3) {
            //int previous_row_index = 1;
            vector<int> _tmp;
            for(auto r = 3 ; r <= rowIndex+1; r++){
                //vector<int> _tmp(r,0);
                _tmp.push_back(previous_row[0]);
                //_tmp[0] = ret[r-2][0];
                //_tmp[r-1] = ret[r-2][r-2];
                for(auto i = 1; i < r - 1; i++)
                {
                    _tmp.push_back(previous_row[i-1]+previous_row[i]);
                }
                _tmp.push_back(previous_row[r-2]);
                previous_row = _tmp;
                _tmp = {};
            }
        }
        return previous_row;
    }
};
// @lc code=end

