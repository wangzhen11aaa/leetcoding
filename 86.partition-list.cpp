/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode node1{0}, node2{0};
        ListNode *p1=&node1, *p2 = &node2;
        while(head){
            if(head->val<x){p1->next=head;p1 = p1->next;}
            else{p2->next=head;p2=p2->next;}
            head=head->next;
        }
        p2->next=nullptr;
        p1->next=node2.next;
        return node1.next;
    //     if(head==nullptr){return head;}
    //     ListNode * p, *q, *tmp, *pre_q;
    //     ListNode *new_head=nullptr;
    //     p=nullptr;
    //     q=head;
    //     if(q->val<x) {new_head=head; p=head;}
    //     pre_q=q;
    //     q=q->next;
    //     while(q){
    //         if(q->val >=x) {pre_q=q; q=q->next;}
    //         else{
    //             tmp=q->next;
    //             //pre_q->next=tmp;
    //             if(new_head==nullptr) {new_head=q; p=q; new_head->next=head; pre_q->next=tmp;}
    //             else{
    //             if(p->next==q){
    //                p=p->next;
    //             }else{
    //                 pre_q->next=tmp;
    //                 q->next=p->next;
    //                 p->next=q;
    //                 p=p->next;
    //             }
    //         }
    //             q=tmp;
    //         }
    //     }
    //     return new_head==nullptr?head:new_head;
    // }
    }
};
// @lc code=end

