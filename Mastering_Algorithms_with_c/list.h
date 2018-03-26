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
	List *head;
	List *tail;

}List;

/*Public interface */

/*��l��list*/
void list_init(List *list,void (*destroy)(void *data));
/*�belement �᭱ ���J�s����*/
int list_ins_next(List *list,ListEmt *emlement,const void *data);

/*�R��element �᭱ ���J�s����*/
int list_rem_next(List *list,ListEmt *emlement,const void **data);

/*get size*/
#define list_size(list)(list->size);


