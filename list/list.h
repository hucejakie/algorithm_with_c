/*list.h*/

#ifndef LIST_H

#define LIST_H

#include <stdlib.h>

/*Define a structure for linked list element*/
/**
 链表结点
 */
typedef struct ListElmt_
{
	void * data;
	struct ListElmt_ *next;
}ListElmt;

/*Define a structure for linked list */
typedef struct List_
{
	int size;
	int (*match)(const void *key1,const void *key2);
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;

}List;

/*Public interface */

/**
 初始化指定的链表 list - O(1)
 @param list 链表
 @param destroy 成员析构函数（free...）
 */
void list_init(List *list,void (*destroy)(void *data));

/**
 销毁指定的链表 list - O(n)
 @param list 链表
 */
void list_destroy(List *list);

/**
 在指定链表 list 中 element 后面插入一个新元素 - O(1)
 @param list 指定的链表
 @param element 新元素，如果为 NULL 则插入头部
 @param data 元素数据
 @return 成功返回 1，否则返回 -1
 */
int list_ins_next(List *list,ListElmt *element,const void *data);

/**
 在指定链表 list 中移除 element 后的元素 - O(1)
 @param list 指定的链表
 @param element 待移除元素前的元素，如果为 NULL 则移除头元素
 @param data 指向已移除元素的存储数据
 @return 成功返回 0，否则返回 -1
 */
int list_rem_next(List *list,ListElmt *element,const void **data);


/**
 获取指定链表 list 的长度 - O(1)
 @param list 指定的链表
 @return 链表中元素的个数
 */
#define list_size(list)((list)->size)

/**
 获取指定链表 list 的头元素指针 - O(1)
 
 @param list 指定的链表
 @return 链表的头元素指针
 */
#define list_head(list)((list)->head)

/**
 获取指定链表 list 的尾元素指针 - O(1)
 
 @param list 指定的链表
 @return 链表的尾元素指针
 */
#define list_tail(list)((list)->tail)

/**
 判断元素 element 是否为指定链表 list 的头节点 - O(1)
 @param list 指定的链表
 @param element 待判断的元素
 @return 是返回 1，否则返回 0
 */
#define list_is_head(list,element)((element)==(list)->head ? 1:0 )

/**
 判断元素 element 是否为指定链表 list 的尾节点 - O(1)
 
 @param list 指定的链表
 @param element 待判断的元素
 @return 是返回 1，否则返回 0
 */
#define list_is_tail(element)((element)->next==NULL ? 1:0 )

/**
 获取指定元素 element 中保存的数据 - O(1)
 @param element 指定的元素
 @return 结点保存的数据
 */
#define list_data(element)((element)->data )

/**
 获取指定元素 element 中保存的下一个节点 - O(1)
 
 @param element 指定的元素
 @return 结点的下一个节点
 */
#define list_next(element)((element)->next )

#endif
