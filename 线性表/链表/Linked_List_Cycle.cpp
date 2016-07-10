// problem:
// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?
// -----------------------------------------------
// solution:
// reference： http://blog.csdn.net/qq575787460/article/details/40383731
//追及问题: 
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
    bool hasCycle(ListNode *head) {
        // ListNode *slow = *fast = head; //这种定义有问题
        ListNode *slow =head, *fast = head;
        // 因为存在环，所以就不用考虑fast
        while(fast && fast->next){
        	slow = slow ->next;
        	fast = fast ->next ->next;
        	if(fast == slow) return true; 
        }
        return false;
    }
};