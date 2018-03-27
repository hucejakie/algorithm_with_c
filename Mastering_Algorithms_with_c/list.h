/*list.h*/

#ifndef LIST_H

#define LIST_H

#endif


#include <stdlib.h>

/*Define a structure for linked list element*/
typedef struct ListEmt_
{
	void * data;
	struct ListEmt_ *next;
}ListEmt;

/*Define a structure for linked list */
typedef struct List_
{
	int size;
	int (*match)(const void *key1,const void *key2);
	void (*destroy)(void *data);
	ListEmt *head;
	ListEmt *tail;

}List;

/*Public interface */

/*初始化list*/
void list_init(List *list,void (*destroy)(void *data));
/*在element 後面 插入新元素*/
int list_ins_next(List *list,ListEmt *emlement,const void *data);

/*刪除element 後面 插入新元素*/
int list_rem_next(List *list,ListEmt *emlement,const void **data);

/*get size*/
#define list_size(list)((list)->size);
#define list_head(list)((list)->head);
#define list_tail(list)((list)->tail);
#define list_is_head(list,element)((element)==(list)->head ? 1:0 );
#define list_is_tail(element)((element)->next==NULL ? 1:0 );
#define list_data(element)((element)->data );
#define list_next(element)((element)->next );

