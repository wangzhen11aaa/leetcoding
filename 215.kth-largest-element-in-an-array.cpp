/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.44%)
 * Likes:    2584
 * Dislikes: 199
 * Total Accepted:    469.1K
 * Total Submissions: 923.5K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use heap.
        vector<int> v;
        int len = nums.size();
        // construct the min-heap for top-k problem.
        int i = 0;
        for(; i < k; i++){
            v.push_back(nums[i]);
        }
        int v_boundary = k;
        int mid = k/2;
        int p,lc, rc;
        for(; mid >=0; mid--){
            for(int i = mid; i < v_boundary;){
            p = v[i];
            lc = INT_MAX;
            rc = INT_MAX;
            if(2*i+1<v_boundary){
                lc = v[2*i+1];
            }
            if(2*i+2<v_boundary){
                rc = v[2*i+2];
            }
            int min_num = min(min(p,rc),lc);
            if(min_num == p) break;
            else if (min_num == lc){
                v[2*i+1]=p;
                v[i] = min_num;
                i=2*i+1;
            }
            else{
                v[2*i+2]=p;
                v[i]=min_num;
                i=2*i+2;
            }
        }
        }
      for (;i < len; i++){
          if(nums[i]<=v[0]) continue;
          else{
             v[0]=nums[i];
             // heapify 
             for(int j = 0; j < k; ){
                p = v[j];
                lc=INT_MAX;
                rc=INT_MAX;
                if(2*j+1<v_boundary){
                    lc = v[2*j+1];
                }
                if(2*j+2<v_boundary){
                    rc = v[2*j+2];
                }
                int min_num = min(min(p,rc),lc);
                if(min_num == p) break;
                else if (min_num == lc){
                v[2*j+1]=p;
                v[j] = min_num;
                j=2*j+1;
             }
            else{
                v[2*j+2]=p;
                v[j]=min_num;
                j=2*j+2;
             }
             }
          }
      }
    return v[0];

    }
};
// @lc code=end

