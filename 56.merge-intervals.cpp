/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.52%)
 * Likes:    2591
 * Dislikes: 204
 * Total Accepted:    417.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals[0].empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &vec1, const vector<int> &vec2) {
            // if (vec1[0] < vec2[0]) {
            //     return true;
            // }
            // else if(vec1[0] == vec2[0]) {
            //     return vec1[1] < vec2[1];
            // }
            // else {
            //     return false;
            // }
            return vec1[0] <= vec2[0]? (vec1[0]<vec2[0]? true:vec1[1]<vec2[1]):false;
        });
        vector<vector<int>> res;
        vector<int> vec = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(max(vec[0], intervals[i][0]) <= min(vec[1], intervals[i][1])) {
                vec[0] = min(vec[0], intervals[i][0]);
                vec[1] = max(vec[1], intervals[i][1]);
            }
            else {
                res.push_back(vec);
                vec = intervals[i];
            }
        }
        res.push_back(vec);
        return res;
    }
};
// Sort is a must-do thing.
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if(intervals.size() == 1) return intervals;
//         vector<vector<int>> res{};
//         set<vector<int>> _set{};
//         while(intervals.size() > 1){
//             vector<int> x = intervals.back();
//             intervals.pop_back();
//             for(auto interval: intervals){
//                 _set.insert(interval);
//             }
//             cout << "After seting set, _set's size : " << _set.size();
//             for(auto interval: intervals){
//                 if(x[0] <= interval[0] && interval[0] <= x[1] || interval[0] <= x[0] && x[0] <= interval[1]){
//                     x[0] = min(x[0], interval[0]);
//                     x[1] = max(x[1], interval[1]);
//                     _set.erase(interval);
//                 }
//             }
//             res.push_back(x);
//             cout << "Before setting, intervals 's size : " << intervals.size();

//             intervals = {};
//             for(auto _s: _set)
//                 intervals.push_back(_s);
//             cout << "After setting, intervals 's size : " << intervals.size();

//             _set = {};
//         }
//         if(intervals.size() != 0)
//             res.push_back(intervals.back());
//         return res;
//     }
// };

// @lc code=end
// 
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if(intervals.size() == 1) return intervals;
//         vector<vector<int>> res{};
//         set<vector<int>> _set{};
//         while(intervals.size() > 1){
//             vector<int> x = intervals.back();
//             intervals.pop_back();
//             for(auto interval: intervals){
//                 _set.insert(interval);
//             }
//             for(auto interval: intervals){
//                 if(x[0] <= interval[0] && interval[0] <= x[1] || interval[0] <= x[0] && x[0] <= interval[1]){
//                     x[0] = min(x[0], interval[0]);
//                     x[1] = max(x[1], interval[1]);
//                     _set.erase(interval);
//                 }
//             }
//             res.push_back(x);
//             intervals = {};
//             for(auto _s: _set)
//                 intervals.push_back(_s);
//             _set = {};
//         }
//         res.push_back(intervals.back());
//         return res;
//     }
// };




