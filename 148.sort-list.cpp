/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
/**
 * Merge-sort
 * 
 * */
class Solution {
public:
    //Merge Two parts of lists.
    ListNode* merge(ListNode* p1, ListNode* p2){
        ListNode dummy(0), *curr = &dummy;
        while(p1 != NULL && p2 != NULL){
            if(p1->val > p2->val){
                curr->next = p2;
                p2 = p2->next;
            }
            else{
                curr->next = p1;
                p1 = p1->next;
            }
            curr = curr->next;
        }
        if(p1 != NULL)
            curr->next = p1;
        else if(p2 != NULL)
            curr->next = p2;
        return dummy.next;
        // ListNode *curr, *head;
        // if(p1 && p2){
        //     head = p1->val<=p2->val?p1:p2;
        //     curr = head;
        //     if(head==p1) p1=p1->next;
        //     else p2=p2->next;
        //     while(p1!=nullptr && p2!=nullptr){
        //         if(p1->val > p2->val){
        //             curr->next=p2;
        //             p2=p2->next;
        //         }else
        //         {
        //             curr->next=p1;
        //             p1=p1->next;
        //         }
        //         curr=curr->next;
        //     }
        //     if(p1!=nullptr){
        //         curr->next=p1;
        //     }else if(p2!=nullptr){
        //         curr->next=p2;
        //     }
        //     return head;
        // }else{
        //     return p1!=nullptr?p1:p2;
        // }
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head, *p2 = head->next;
        // Split the List into two parts. Each is exact 1/2 length of the total length.
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
            if(p2->next != NULL)
                p2 = p2->next;
        }
        p2 = p1->next;
        p1->next = NULL; 
        p2 = sortList(p2);
        p1 = sortList(head);
        head = merge(p1, p2);
        return head;
    }
};
// @lc code=end

