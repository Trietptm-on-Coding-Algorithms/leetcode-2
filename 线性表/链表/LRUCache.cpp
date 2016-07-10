problem: Design and implement a data structure for Least Recently Used
(LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the
key exists in the cache, otherwise return -1. set(key, value) - Set or
insert the value if the key is not already present. When the cache
reached its capacity, it should invalidate the least recently used
item before inserting a new item.

---------------------------------------------- solution:

LRU替换的本质是替换掉最长时间没被访问的元素，set和get都算访问操作，故解决方案是cache中的元素是有序的，按照其被访问的时间排序，最新被访问的元素在头部（或尾部），替换时直接删除尾部（或头部）元素即可，如果不使用有序序列的话，那么需要记录每个元素最后被访问的时间，替换时，遍历整个序列，找到时间最久的替换掉，但是这样会超时。故应该保持序列有序。

按照题目要求，要实现get和set功能，为了满足随机存储需求我们首先想到数组，如果用链表会有O(n)的访问时间。 然而又要维护 leastused 队列，常用的放在前面，用的少的放在后面。这就要求我们要对节点有好的删除和插入操作，这个要求又让我们想到链表，因为数组的删除和插入是O(n)复杂度的。

那么我们能不能维护一个数据结构使得访问操作和插入删除操作都是O(1)复杂度的呢？答案是肯定的。即使用list保存元素，在头部插入，尾部删除，每次访问元素时，把它移动到头部（双向链表中移动一个元素到头部时间复杂度是O(1)）；再用一个hash_map记录元素的位置。

困难：如何实现在每一次访问元素时，重新调整序列的顺序，让被访问元素移动到头部？？？

解决：STL中各种容器只有list能方便地调整顺序，就是splice方法，它可以实现把某个list的某个位置的元素或者某个区间位置的元素插入到当前list中，当然如果二者是同一个list，那么就是调整该list中某些元素的顺序了。splice方法的介绍在这里，由于其参数为位置迭代器iterator，故我们需要记录元素key对应的迭代器信息，可以使用map，但是由于map是平衡树实现的有序的序列，故其存取时间复杂度为O(logN)，由于我们无需有序，故使用hash_map即可，即unordered_map。

/* 
 * 注意整体思路是,使用双向list每次set或get一个元素时都把这个元素放到list的头部,无需统计每个元素的操作次数,实际上LRU的意思 
 * 就是根据元素最后被访问的时间来决定替换哪个,故list中尾部元素即被替换. 
 * STL技巧：1、使用map的find方法来判断key是否已经存在,返回值和map的end迭代器比较； 
            2、使用unordered_map,它是hash_map,存取时间都是O(1),用它存储元素的position迭代器,是为了方便splice函数调用 
 *          list.splice(position, list, element_pos)函数作用是把list的element_pos处的元素插入到position位置,本题中 
            为了移动元素到list头部 
 */  

 参考：http://blog.csdn.net/jiadebin890724/article/details/34096743

class LRUCache{
private:
	struct CacheNode
	{
		int key;
		int value;
		CacheNode(int k, int v):key(k), value(v){}
	};
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) return -1;
        
        //把当前访问的节点移到表头部，并更新map中该结点的地址
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key] ->value;
    }
    
    void set(int key, int value) {
    	//没有
        if (cacheMap.find(key) == cacheMap.end())
        {
        	// delete
        	if (cacheList.size() == capacity)
        	{
        		cacheMap.erase(cacheList.back().key);
        		cacheList.pop_back();
        	}
        	//insert
        	cacheList.push_front(CacheNode(key,value));
        	cacheMap[key] = cacheList.begin();
        }
        //有 或者 没有长度没超
        else
        {
        	cacheMap[key] ->value = value;
        	cacheList.splice(cacheList.begin(), cacheList,cacheMap[key]);
        	cacheMap[key] = cacheList.begin();
        }
    }
};