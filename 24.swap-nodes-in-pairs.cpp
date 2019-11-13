/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy(0),*ret=&dummy;
        ListNode *p1, *p2, *cover;
        p1=head;
        // Initial state the cover pointer with nullptr;
        cover = nullptr;
        while(p1!=nullptr && p1->next!=nullptr){
            p2=p1->next;
            ListNode* explorer = p2->next;
            p1->next=explorer;
            p2->next=p1;
            if(cover) cover->next=p2;
            cover=p1;
            if(ret->next==nullptr) ret->next = p2;
            p1=explorer;
        }
        return ret->next;
        // We use p2 
    }
};
// @lc code=end

