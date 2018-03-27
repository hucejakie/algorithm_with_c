/*list.c*/
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*list_init*/
void list_init(List *list,void (*destroy)(void *data))
{
	list->size=0;
	list->destroy=destroy;
	list->head=NULL;
	list->tail=NULL;
	return;
}

void list_destroy(List *list)
{
	void *data;
	///删除每一个元素
	while(list_size(list) >0)
	{
		///调用用户定义destroy函数
		if (list_rem_next(list,NULL,(void **)&data)==0 && list->destroy!=NULL)
			list->destroy(data);
	}
	///清理链表结构体数据
	memset(list,0,sizeof(list));
	return;
}	

/*insert new data at element next  */
int list_ins_next(List *list,ListEmt *element,const void *data)
{
	ListEmt *new_element;
	///申请内存，create new element
	if((new_element=(ListEmt *)malloc(sizeof(ListEmt))) ==NULL)
		return -1;
	new_element->data=(void *)data;

	if(element==NULL)
	{
		//add first element
		if(list_size(list)==0)
			list->tail=new_element;
		new_element->next=list->head;
		list->head=new_element;
	}
	else
	{
		if(element->next==NULL)
			list->tail=new_element;

		new_element->next=element->next;
		element->next=new_element;
	
	}
	list->size++;
	return 0;

}

/*delete element's next data */
int list_rem_next(List *list,ListEmt *element,const void **data)
{
	if(list_size(list)==0)
		return -1;

	ListEmt *old_element;

	if(element==NULL)
	{
		*data=list->head->data;
		old_element=list->head;
		list->head=list->head->next;

		if(list_size(list)==1)
			list->tail=NULL;

	}
	else
	{
		if(element->next==NULL)
			return -1;
		*data=element->next->data;
		old_element=element->next;
		element->next=element->next->next;

		if(element->next==NULL)
			list->tail=element;

	}
	list->size--;
		return 0;

}