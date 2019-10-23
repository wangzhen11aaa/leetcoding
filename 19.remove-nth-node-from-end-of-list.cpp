/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.51%)
 * Likes:    2079
 * Dislikes: 158
 * Total Accepted:    439.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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

 // The code below will remove the nth element from head.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode *iter_head_p = head;
        while(iter_head_p) {l++; iter_head_p = iter_head_p->next;}
        auto _n = l - n;
        if(_n == 0) return head->next;
        int i = 0;
        ListNode *ret_head = head;
        ListNode *pre_node_p = NULL;
        ListNode *cur_node_p = head;
        for(; cur_node_p && i != _n; i++){
            pre_node_p = cur_node_p;
            cur_node_p = cur_node_p->next;
        }
        if(cur_node_p)
        {
            pre_node_p->next = cur_node_p->next;
        }
        return ret_head;
    }

    // // The code below will remove the nth element from head.
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(n == 0) return head->next;
    //     int i = 0;
    //     ListNode *ret_head = head;
    //     ListNode *pre_node_p = NULL;
    //     ListNode *cur_node_p = head;
    //     for(; cur_node_p && i != n; i++){
    //         pre_node_p = cur_node_p;
    //         cur_node_p = cur_node_p->next;
    //     }
    //     if(cur_node_p)
    //     {
    //         pre_node_p->next = cur_node_p->next;
    //     }
    //     return ret_head;
    // }
    // The below algorithm will remove the element from list where value is n.
    //     if(!head) return head;
    //     ListNode *ret_head_p, *pre_node_p, *iter_node_p;
    //     // Initilize the pointer.
    //     ret_head_p = pre_node_p = NULL;
    //     iter_node_p = head;
    //     while(iter_node_p){
    //         // If we encounter the val == n, then the pre_node_p will not change.
    //         if(iter_node_p->val == n){
    //             if(!pre_node_p){
    //                 iter_node_p = iter_node_p->next;
    //             }else{
    //                 pre_node_p->next = iter_node_p->next;
    //                 iter_node_p = iter_node_p->next;
    //             }
    //         }else{
    //             if(!ret_head_p) {
    //                 ret_head_p = iter_node_p;
    //                 pre_node_p = iter_node_p; 
    //             }else{
    //                 pre_node_p = pre_node_p->next;
    //             }
    //             iter_node_p = iter_node_p->next;
    //         }
    //     }
    //     return ret_head_p;
    // }
};

