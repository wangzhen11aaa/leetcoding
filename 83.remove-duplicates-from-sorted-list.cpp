/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.48%)
 * Likes:    940
 * Dislikes: 86
 * Total Accepted:    369.2K
 * Total Submissions: 848.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* explorer = head->next;
        ListNode* merger = head;
        int v = head->val;
        while(explorer){
            int explorer_val = explorer->val;
            if(explorer_val != v){
                merger = explorer;
                v = merger->val;
            }else{
                merger->next = explorer->next;
            }
            explorer = explorer->next;
        }
        return head;
    }
};
// @lc code=end

