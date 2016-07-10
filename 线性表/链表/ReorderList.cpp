// problem:
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You must do this in-place without altering the nodes' values.

// For example,
// Given {1,2,3,4}, reorder it to {1,4,2,3}.
// -------------------------------------------------
// solution:
// 思路：
// 1、将链表从中间切开分为leftlist 、rightlist
// 2、将rightlist逆序
// 3、两串合并

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
    void reorderList(ListNode* head) {
         if(head == NULL || head->next ==NULL) return;
         ListNode *slow = head, *fast = head;
         ListNode *prev = NULL;
         while(fast && fast->next){
             prev = slow;
             slow = slow ->next;
             fast = fast ->next ->next;
         }
         prev ->next = NULL;
         
         slow = reverse(slow);
         ListNode *cur =head;    
         while(cur && cur->next){
            //  没有考虑slow->next是否有错误
             ListNode *tmp = slow ->next;
             slow ->next = cur->next;
             cur ->next = slow;
             cur = cur->next ->next;
             slow = tmp;
            // ListNode *tmp = cur ->next;
            // cur ->next = slow;
            // slow = slow ->next;
            // cur ->next ->next = tmp;
            // cur = tmp;
         }
         cur ->next = slow;
        
    }
    ListNode *reverse(ListNode *head){
        if(head == NULL || head ->next ==NULL) return head;
        ListNode *prev=head;
        //此处犯二，next？next->next:nullptr 弄反了
        // for( ListNode*cur = head->next, *next = cur->next; cur; prev= cur, cur = next, next = next?next->next: nullptr){
        for( ListNode*cur = head->next, *next = cur->next; cur; prev= cur, cur = next, next = next?next->next: nullptr){
            cur ->next = prev;
        }
        head ->next = NULL;
        return prev;
    }

};

class Solution {
public:
    void reorderList(ListNode* head) {
    	if(head == NULL || head->next == NULL) return;

    	ListNode *slow = head, *fast = head, *prev = NULL;
    	while(fast && fast ->next){
    		prev = slow;
    		slow = slow ->next;
    		fast = fast ->next ->next;
    	}
    	prev ->next = NULL;

    	slow = reverse(slow);
    	// merge two lists
    	ListNode *cur = head;
    	while(cur ->next){
    		ListNode *tmp = cur ->next;
    		cur ->next = slow;
    		slow = slow ->next;
    		cur ->next ->next = tmp;
    		cur = tmp;
    	}
    	cur ->next = slow;
    }

    ListNode *reverse(ListNode *head){
    	if (head == NULL || head ->next == NULL) return head;
    	ListNode *prev = head;
    	for(ListNode *cur = head->next, *next=cur->next; cur ;prev = cur,cur = next,next = next? next->next:NULL ){
    		cur ->next = prev;
    	}
    	head->next = NULL;
    	return prev;
    }


};