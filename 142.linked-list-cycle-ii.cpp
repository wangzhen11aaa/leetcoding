/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (33.68%)
 * Likes:    1757
 * Dislikes: 139
 * Total Accepted:    244.6K
 * Total Submissions: 725.5K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow-up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        int size = 0;
        ListNode* normal_explorer = head;
        // Find the normal pointer in the cyple.
        ListNode* aggressive_explorer = head->next;
        while(aggressive_explorer && aggressive_explorer->next){
            if(normal_explorer == aggressive_explorer) break;
            aggressive_explorer = aggressive_explorer->next->next;
            normal_explorer = normal_explorer->next;
        }
        int cycle_size = 1;

        if(!aggressive_explorer || !(aggressive_explorer->next)) return nullptr;
        else{
            aggressive_explorer = normal_explorer;
            normal_explorer = normal_explorer->next;
            while(normal_explorer != aggressive_explorer){
                    cycle_size++;
                    normal_explorer = normal_explorer->next;
            }
        }
        aggressive_explorer = normal_explorer = head;

        for(auto i = 0; i< cycle_size; i++){
            aggressive_explorer = aggressive_explorer->next; 
        }
        while(normal_explorer != aggressive_explorer){
            normal_explorer=normal_explorer->next;
            aggressive_explorer = aggressive_explorer->next;
        }
        return normal_explorer;
    }
};
// @lc code=end

