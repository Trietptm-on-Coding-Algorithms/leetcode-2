// problem:
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Note: Do not modify the linked list.

// Follow up:
// Can you solve it without using extra space?

// ------------------------
// solution: 
 http://www.cnblogs.com/hiddenfox/p/3408931.html 

在网上搜集了一下这个问题相关的一些问题，思路开阔了不少，总结如下：
1. 环的长度是多少？
2. 如何找到环中第一个节点（即Linked List Cycle II）？
3. 如何将有环的链表变成单链表（解除环）？
4. 如何判断两个单链表是否有交点？如何找到第一个相交的节点？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 思路错误原因:并不是追上的地方就是环的开始位置

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(true){
        	if (!fast  || !fast->next)
        	{
        		return NULL; //遇到null，说明不存在环
        	}
        	slow = slow ->next;
        	fast = fast ->next ->next;
        	if(slow == fast) break; //第一次相遇在Z点
        }
        
        slow = head; //从头开始走
        while(slow != fast){
        	slow = slow ->next;
        	fast = fast ->next;
        }
        return slow;

    }
};