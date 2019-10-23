/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.62%)
 * Likes:    5848
 * Dislikes: 1507
 * Total Accepted:    992.2K
 * Total Submissions: 3.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    //We need an carry.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // preNode used to concatenate the higher digit result.
        // header is used for return the header of the result.
        ListNode * preNode = NULL;
        ListNode * header = NULL;
        while(l1 && l2){
            // The first node will be the header.
            ListNode * _node = new ListNode((l1->val + l2->val + carry)%10);
            if (!header)
                header = _node;
            if((l1->val + l2->val + carry)/10 >=1) carry = 1;
            else carry = 0;
            if(preNode){
                preNode->next = _node;
                //Update preNode.
                preNode = _node;
            }else{
                preNode = _node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *last_part = l1?l1:l2;
        while(last_part){
            ListNode *_node = new ListNode((last_part->val + carry) %10);
            if (!header)
                header = _node;

            if((last_part->val + carry)/10 >= 1) carry = 1;
            else carry = 0;
            if(preNode){
                preNode->next = _node;
                preNode = _node;
            }else
            {
                preNode = _node;
            }
            last_part = last_part->next;
        }
        if(carry != 0){
            ListNode * _node = new ListNode(carry);
            preNode -> next = _node;
        }
        return header;
    }
};

