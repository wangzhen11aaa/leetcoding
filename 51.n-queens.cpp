/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (41.65%)
 * Likes:    1193
 * Dislikes: 54
 * Total Accepted:    160.8K
 * Total Submissions: 386K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> res;
       // Initial pos
       int start_column = 0;
       for(auto i = 0; i < n; i++){
           vector<int> start_pos{i, start_column};
           vector<vector<int>> positions;
           positions.push_back(start_pos);
           putQueen(positions, start_column+1, res, 1, n);
       }
    }
    void putQueen(vector<vector<int>> positions, int start_column,
    vector<vector<string>>& _res, int c, int n){
        if(c == n){
            string s;
            int _i = 0;
            for(auto pos: positions){
                _i++;
                for(auto i = 0; i < n; i++){
                    if(i != pos[0]) s+= ".";
                    else s+= "Q";
                }
                if(_i < n){
                    s += ","
                }
            }
            _res.push_back(s);
        }else{
            bool attack_flag = false;
            for(auto i = 0; i < n; i++){
                for(auto pos: positions){
                    if(attack(pos[0], pos[1], i, start_column)){
                        attack_flag = true;
                        break;
                    }
                }
                if(!attack_flag){
                    vector<int> good_pos{i, column};
                    positions.push_back(good_pos);
                    putQueen(positions, start_column + 1, _res, c+1, n);
                    positions.pop_back();
                }
            }

        }
    }
    bool attack(int x0, int y0, int x1, int y1){
        if(x0 == x1 || y0 == y1 || abs((x1-x0)/(y1-y0)) == 1) return true;
        else false;
    }
};
// @lc code=end

