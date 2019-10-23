/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/description/
 *
 * algorithms
 * Easy (35.85%)
 * Likes:    2480
 * Dislikes: 246
 * Total Accepted:    350.7K
 * Total Submissions: 976.2K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * Write a program to find the node at which the intersection of two singly
 * linked lists begins.
 * 
 * For example, the following two linked lists:
 * 
 * 
 * begin to intersect at node c1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA =
 * 2, skipB = 3
 * Output: Reference of the node with value = 8
 * Input Explanation: The intersected node's value is 8 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2
 * nodes before the intersected node in A; There are 3 nodes before the
 * intersected node in B.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3,
 * skipB = 1
 * Output: Reference of the node with value = 2
 * Input Explanation: The intersected node's value is 2 (note that this must
 * not be 0 if the two lists intersect). From the head of A, it reads as
 * [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes
 * before the intersected node in A; There are 1 node before the intersected
 * node in B.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB =
 * 2
 * Output: null
 * Input Explanation: From the head of A, it reads as [2,6,4]. From the head of
 * B, it reads as [1,5]. Since the two lists do not intersect, intersectVal
 * must be 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 * 
 * 
 * 
 * 
 * Notes:
 * 
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function
 * returns.
 * You may assume there are no cycles anywhere in the entire linked
 * structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int sizeA  = 0;
    //     int sizeB = 0;
    //     ListNode* _headA = headA;
    //     ListNode *_headB = headB;
    //     while(_headA){
    //         sizeA++;
    //         _headA = _headA->next;
    //     }
    //     while(_headB){
    //         sizeB++;
    //         _headB = _headB->next;
    //     }
    //     int delta = abs(sizeA - sizeB);
    //     if(sizeA >= sizeB){
    //         _headB = headB;
    //         _headA = headA;
    //         while(delta>0){
    //             _headA = _headA->next;
    //             delta--;
    //         }
    //     }else{
    //         _headA = headA;
    //         _headB = headB;
    //         while(delta > 0){
    //             _headB = _headB->next;
    //             delta--;
    //         }
    //     }
    //     while(_headA && _headB && _headA != _headB){
    //         //cout << "_headA's val : " << _headA->val << "_headB's val :" << _headB->val;
    //         _headA = _headA->next;
    //         _headB = _headB->next;
    //     }
    //     if(!_headA || !_headB) return nullptr;
    //     return _headA;

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Time: O(m+n), Space(1)
        // Two pointers, each pointer iterate two list
        // because m+n = m+n, they will reach the interaction eventually
        if(headA == NULL || headB == NULL) return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;

        while (pa != pb) {
            if (pa){
                pa = pa->next;
            }else{
                pa = headB;
            }
            
            if (pb){
                pb = pb->next;
            }else{
                pb = headA;
            } 
        }
        return pa;
        // ListNode *reversedHead = nullptr;
        // listNode *broker = nullptr;
        // Reverse List.
        // if(sizeA <= sizeB){
        //     _headA = headA;
        //     while(_headA != nullptr){
        //         broker = _headA;
        //         broker->next = reversedHead;
        //         reversedHead=broker;
        //         _headA = _headA->next;
        //     }
        //     _headB = headB;
        //     while(_headB){
        //         reversedSizeB++;
        //         _headB = _headB->next;
        //     }
        // }else{
        //     _headB = headB;
        //     while(_headB != nullptr){
        //         broker = _headB;
        //         broker->next = reversedHead;
        //         reversedHead = broker;
        //         _headB = _headB->next;
        //     }
        //     _headA = headA;
        //     while(_headA){
        //         reversedSizeA++;
        //         _headA = _headA->next;
        //     }
        // }
    }
};
// @lc code=end

