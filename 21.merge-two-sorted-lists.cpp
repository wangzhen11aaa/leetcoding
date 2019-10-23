/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.50%)
 * Likes:    2564
 * Dislikes: 371
 * Total Accepted:    662.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    // If l1.val <= l2.val insert the element into l1.
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *r_head = (l1->val <= l2->val)?l1:l2;

        ListNode *insert_list_p = (r_head == l1)?l1:l2;
        ListNode *pre_insert_list_p = NULL;
        ListNode *select_list_p = (r_head == l1)?l2:l1;
        // Insert the 
        while(insert_list_p && select_list_p){
            if(insert_list_p->val <= select_list_p->val) 
            {
                pre_insert_list_p = insert_list_p;
                insert_list_p = insert_list_p->next;
            }
            else
            {
                ListNode * tmp_node_p = select_list_p;
                select_list_p = select_list_p->next;
                tmp_node_p->next=insert_list_p;
                pre_insert_list_p->next=tmp_node_p;
                pre_insert_list_p = tmp_node_p;
            }
        }
        if(select_list_p){
            pre_insert_list_p->next = select_list_p;
        }
        return r_head;
    }
    //     ListNode *l1_iter_node_p, *l2_iter_node_p, *ret_header;
    //     l1_iter_node_p = l1;
    //     l2_iter_node_p = l2;
    //     while(l1_iter_node_p && l2_iter_node_p){
    //         if(l1_iter_node_p->val > l2_iter_node_p->val){
    //             ListNode * tmp_pointer = l2_iter_node_p;
    //             l2_iter_node_p = l2_iter_node_p->next;
    //             tmp_pointer->next = l1_iter_node_p;
    //             l1_iter_node_p=tmp_pointer;
    //         }else{
    //             ret_header = l1_iter_node_p;
    //             ListNode *tmp_pointer = l2_iter_node_p;
    //             l2_iter_node_p = l2_iter_node_p->next;
    //             tmp_pointer->next = l1_iter_node_p->next;
    //             l1_iter_node_p = tmp_pointer;
    //             l1_iter_node_p = 
    //         }
    //     }
    // }
};

