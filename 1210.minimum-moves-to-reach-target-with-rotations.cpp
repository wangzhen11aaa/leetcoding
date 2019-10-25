/*
 * @lc app=leetcode id=1210 lang=cpp
 *
 * [1210] Minimum Moves to Reach Target with Rotations
 *
 * https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/description/
 *
 * algorithms
 * Hard (42.37%)
 * Likes:    68
 * Dislikes: 19
 * Total Accepted:    3K
 * Total Submissions: 7K
 * Testcase Example:  '[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]\r'
 *
 * In an n*n grid, there is a snake that spans 2 cells and starts moving from
 * the top left corner at (0, 0) and (0, 1). The grid has empty cells
 * represented by zeros and blocked cells represented by ones. The snake wants
 * to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
 * 
 * In one move the snake can:
 * 
 * 
 * Move one cell to the right if there are no blocked cells there. This move
 * keeps the horizontal/vertical position of the snake as it is.
 * Move down one cell if there are no blocked cells there. This move keeps the
 * horizontal/vertical position of the snake as it is.
 * Rotate clockwise if it's in a horizontal position and the two cells under it
 * are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r,
 * c) and (r+1, c).
 * 
 * Rotate counterclockwise if it's in a vertical position and the two cells to
 * its right are both empty. In that case the snake moves from (r, c) and (r+1,
 * c) to (r, c) and (r, c+1).
 * 
 * 
 * 
 * Return the minimum number of moves to reach the target.
 * 
 * If there is no way to reach the target, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,0,0,0,1],
 * ⁠              [1,1,0,0,1,0],
 * [0,0,0,0,1,1],
 * [0,0,1,0,1,0],
 * [0,1,1,0,0,0],
 * [0,1,1,0,0,0]]
 * Output: 11
 * Explanation:
 * One possible solution is [right, right, rotate clockwise, right, down, down,
 * down, down, rotate counterclockwise, right, down].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,0,1,1,1,1],
 * [0,0,0,0,1,1],
 * [1,1,0,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,1],
 * [1,1,1,0,0,0]]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 100
 * 0 <= grid[i][j] <= 1
 * It is guaranteed that the snake starts at empty cells.
 * 
 * 
 */

/* BFS vs DFS */
// @lc code=start
// 
class Solution {
public:
    set<vector<int>> visited;
    queue<vector<int>> q;
    void commonMoves(vector<vector<int>>& grid,vector<int> &pos)
    {
        if(pos[3]+1<grid.size()&&!grid[pos[2]][pos[3]+1]&&!grid[pos[0]][pos[1]+1]&&!visited.count({pos[0],pos[1]+1,pos[2],pos[3]+1}))     //Move right
            visited.insert({pos[0],pos[1]+1,pos[2],pos[3]+1}),q.push({pos[0],pos[1]+1,pos[2],pos[3]+1});
        if(pos[2]+1<grid.size()&&!grid[pos[2]+1][pos[3]]&&!grid[pos[0]+1][pos[1]]&&!visited.count({pos[0]+1,pos[1],pos[2]+1,pos[3]}))       //Move down
            visited.insert({pos[0]+1,pos[1],pos[2]+1,pos[3]}),q.push({pos[0]+1,pos[1],pos[2]+1,pos[3]});
    }
    void horizontal(vector<vector<int>>& grid,vector<int> &pos)
    {
        if(pos[0]+1<grid.size()&&!grid[pos[0]+1][pos[1]]&&!grid[pos[2]+1][pos[3]]&&!visited.count({pos[0],pos[1],pos[0]+1,pos[1]}))         //Rotate clockwise
            visited.insert({pos[0],pos[1],pos[0]+1,pos[1]}),q.push({pos[0],pos[1],pos[0]+1,pos[1]});
    }
    void vertical(vector<vector<int>>& grid,vector<int> &pos)
    {
        if(pos[1]+1<grid.size()&&!grid[pos[0]][pos[1]+1]&&!grid[pos[2]][pos[3]+1]&&!visited.count({pos[0],pos[1],pos[0],pos[1]+1}))      //Rotate counter-clockwise
            visited.insert({pos[0],pos[1],pos[0],pos[1]+1}),q.push({pos[0],pos[1],pos[0],pos[1]+1});
    }
    int minimumMoves(vector<vector<int>>& grid) 
    {
        vector<int> target={grid.size()-1,grid.size()-2,grid.size()-1,grid.size()-1}; 
        q.push({0,0,0,1});
        visited.insert({0,0,0,1});
        int size,moves=0;
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {
                if(q.front()==target)                             //Reached target
                    return moves;
                if(q.front()[0]==q.front()[2])                 //When snake is horizontal
                    horizontal(grid,q.front());
                else                                                   //When snake is vertical
                    vertical(grid,q.front());
		commonMoves(grid,q.front());                 //Common moves (Right and down)
                q.pop();
            }
            moves++;
        }
        return -1;
    }
};
// @lc code=end

