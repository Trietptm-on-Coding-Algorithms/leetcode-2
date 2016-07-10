// problem:
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

// Return a deep copy of the list.
// -----------------------------------------
// solution:

// 深拷贝
// 1、random指向的元素没有
// 2、直接赋值指向的是原来链表中节点

// 算法：http://www.cnblogs.com/TenosDoIt/p/3387000.html 
// 1、添加元素
// 2、回复原始链表及构建新链表（链表断开重组）
// 结束条件用->next判断

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
        {
        	return NULL;
        }
        RandomListNode *result = NULL;
        RandomListNode *pold = head, *pnew = result, *poldNext = NULL;

        do{
        	poldNext = pold ->next;
        	pnew = new RandomListNode(pold->label);
        	pold -> next = pnew;
        	pnew ->next = poldNext;
        	if (result == NULL)
        	{
        		result = pnew;
        	}
        	pold = poldNext;
        }while(pold);
        //少了分号;

        //设置new list的random指针
        pold = head;
        while(pold){
        	// 忘记判断pold->random是否为空了
        	if (pold ->random)
        	{
        		pold ->next ->random = pold ->random->next;
        	}
        	
        	pold = pold ->next -> next;
        }

        // 回复old list和new list
        pold = head;
        pnew = result;
        // 通过pnew->next来结束
        while(pnew->next){
        	pold ->next = pnew ->next;
        	pold  = pold ->next;
        	pnew ->next = pold ->next;
        	pnew = pnew ->next;
        }

        pold ->next = NULL;
        pnew ->next = NULL;
        return result;
    }
};