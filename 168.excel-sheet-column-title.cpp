/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.64%)
 * Likes:    847
 * Dislikes: 170
 * Total Accepted:    186.9K
 * Total Submissions: 630K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        int N = 26;
        if(n <= 0) return "";
        string res;
        int tmp;
        int co = 1;
        while(n >0){
            cout << n << endl;
            tmp = n%N;
            if(tmp==0){
                res = 'Z' + res;//insert(0, 'Z'.tostring());
                n-=26*co;
            }else{
                res = (char)(tmp-1+'A') + res; //res.insert(0, tmp - 1 + 'A');
                cout << res << endl;
                n-=tmp*co;
            }
            //co*=26;
            if(n<N && n>0) res = char(n-1+'A')+res;
            n/=N;
            //res = tmp
        }
        return res;
    }
};
// @lc code=end

