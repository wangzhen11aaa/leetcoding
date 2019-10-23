/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.02%)
 * Likes:    1033
 * Dislikes: 50
 * Total Accepted:    246.3K
 * Total Submissions: 569.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int> &num, int target) 
//     {
//         vector<vector<int>> res;
//         sort(num.begin(),num.end());
//         vector<int> local;
//         findCombination(res, 0, target, local, num);
//         return res;
//     }
//     void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
//     {
//         if(target==0)
//         {
//             res.push_back(local);
//         }
//         else
//         {
//             for(int i = order;i<num.size();i++) // iterative component
//             {
//                 if(num[i]>target) return;
//                 if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
//                 local.push_back(num[i]),
//                 findCombination(res,i+1,target-num[i],local,num); // recursive componenet
//                 local.pop_back();
//             }
//         }
//     }
// };
class Solution {
public:
    // Fix one dimension(node), and search all results. 
    // When meet same number, just continue. For we have already had the result, and 
    // take care of the search point.
    // Only let target >= 0, then the function can be stepped into.
    void searchResult(vector<int> &_candidates, int target, int begin, vector<int> tmp_res, vector<vector<int>> &res){
        if(target==0){res.push_back(tmp_res);}
        else{
            for (int i = begin; i < _candidates.size() && _candidates[i] <= target; i++)
            {
                if(i&&(_candidates[i]==_candidates[i-1])&&i>begin) continue;
                // possibly the result can be the result.
                tmp_res.push_back(_candidates[i]);
                searchResult(_candidates, target-_candidates[i], i+1, tmp_res, res);
                tmp_res.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        //set<vector<int>> m_set;
        vector<int> _res;
        searchResult(candidates, target, 0, _res, res);
        // for (int i = 0; i < candidates.size()&&candidates[i]<=target; i++){
        //     if(i&&candidates[i]==candidates[i-1]) continue;
        //     _res.push_back(candidates[i]);
        //     searchResult(candidates, target-candidates[i], i+1, _res, res);
        //     _res.pop_back();
        // }
        //for(auto _m_set:m_set) res.push_back(_m_set);
        return res;
    }

};

