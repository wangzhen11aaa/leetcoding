/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k<=1) return head;
        ListNode dummy(0), *ret = &dummy;
        ListNode *p1, *p2, *cover=nullptr;
        p1=head;
        // K means that we should invoke next method k-1 times.

        while(p1 && getPivotNode(p1, k)){
            p2 = getPivotNode(p1,k);
            ListNode* explorer = p2->next;
            // revert the list between p1 and p2;
            // node1->node2->node3->...->nodek->....
            // p1                          p2
            //ListNode* p1_restore = p1;
            revertList(p1, p2);
        
            p1->next = explorer;
            if(cover) cover->next=p2;
            cover=p1;
            if(ret->next==nullptr) ret->next = p2;
            p1=explorer;
        }
        return ret->next==nullptr?head:ret->next;
    }
    void revertList(ListNode* _p1, ListNode* _p2){
        ListNode tmp(0), *_tmp = &tmp;
        while(_p1!=_p2){
            ListNode* _explorer = _p1->next;
            _p1->next=_tmp->next;
            _tmp->next=_p1;
            _p1=_explorer;
        }
        _p2->next=_tmp->next;
        _tmp->next=_p2;
        //return _tmp->next;
    }
    ListNode* getPivotNode(ListNode *t, int k){
        ListNode * curr = t;
        for(int i=k; i >1 && curr!=nullptr; i--){
            curr=curr->next;
        }
        return curr==nullptr?nullptr:curr;
    }
    // ListNode* reverseKGroup(ListNode *head, int k) {
    // ListNode* curr = head;
    // int count = 0;
    // while (curr != nullptr && count != k) { // find the k+1 node
    //     curr = curr->next;
    //     count++;
    // }
    // if (count == k) { // if k+1 node is found
    //     curr = reverseKGroup(curr, k); // reverse list with k+1 node as head
    //     // head - head-pointer to direct part, 
    //     // curr - head-pointer to reversed part;
    //     while (count-- > 0) { // reverse current k-group: 
    //         ListNode* tmp = head->next; // tmp - next head in direct part
    //         head->next = curr; // preappending "direct" head to the reversed list 
    //         curr = head; // move head of reversed part to a new node
    //         head = tmp; // move "direct" head to the next node in direct part
    //     }
    //     head = curr;
    // }
    // return head;
//}
};
// @lc code=end

