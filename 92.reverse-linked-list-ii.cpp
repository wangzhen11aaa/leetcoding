/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.35%)
 * Likes:    1569
 * Dislikes: 109
 * Total Accepted:    224.6K
 * Total Submissions: 615.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==nullptr || m==n || m > n) return head;
        int delta=n-m;
        ListNode *backer, *explorer, *m_iterator;
        ListNode dummy(0), *ret=&dummy;
        explorer=backer=nullptr;
        for(m_iterator=head; m_iterator && n > 0; m_iterator=m_iterator->next,m--,n--){
            if(m==2) backer=m_iterator;
            if(n==1) {explorer=m_iterator->next; break;}
        }
        if(backer==nullptr){
            return reverse(head, m_iterator, explorer);
        }
        ListNode *reversed_list_head = reverse(backer->next, m_iterator, explorer);
        backer->next=reversed_list_head;
        return head;
       
    }
    // ListNode* reverse(ListNode *p, int _delta, ListNode *_explorer){
    //         ListNode dummy(0), *ret=&dummy;
    //         ListNode * it = p->next;
    //         p->next=_explorer;
    //         ret->next=p;
    //         ListNode *tmp;
    //         while(_delta>0){
    //             tmp=it->next;
    //             it->next=ret->next;
    //             ret->next=it;
    //             it=tmp;
    //             _delta--;
    //         }
    //         return dummy.next;
    //     }
    ListNode* reverse(ListNode *p, ListNode *q, ListNode *_explorer){
            ListNode dummy(0), *ret=&dummy;
            ListNode * it = p->next;
            p->next=_explorer;
            ret->next=p;
            ListNode *tmp;
            while(it!=_explorer){
                tmp=it->next;
                it->next=ret->next;
                ret->next=it;
                it=tmp;
            }
            return dummy.next;
        }
};
// @lc code=end

