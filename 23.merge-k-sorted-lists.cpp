/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.65%)
 * Likes:    2845
 * Dislikes: 186
 * Total Accepted:    439.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
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
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) return l2;
        else if (NULL == l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int len = lists.size();
        while (len > 1) {
            for (int i = 0; i < len / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        
        return lists.front();
    }
};
// class Solution {
// public:
//     //  * [
//     //  * 1->4->5,
//     //  * 1->3->4,
//     //  * 2->6
//     //  * ]
//     // Find the list which contains the mimimum num among the lists.
//     // Use list found above, and insert element. Insert one element per time. Fix one list.
//     // Guarantee the increasing order. Use min-head (size: n-1) insert 
//   ListNode *mergeKLists(vector<ListNode *> &lists) {
//     if(lists.empty()){
//         return nullptr;
//     }
//     while(lists.size() > 1){
//         lists.push_back(mergeTwoLists(lists[0], lists[1]));
//         lists.erase(lists.begin());
//         lists.erase(lists.begin());
//     }
//     return lists.front();
// }
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//     if(l1 == nullptr){
//         return l2;
//     }
//     if(l2 == nullptr){
//         return l1;
//     }
//     if(l1->val <= l2->val){
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     }
//     else{
//         l2->next = mergeTwoLists(l1, l2->next);
//         return l2;
//     }
// }
// };

