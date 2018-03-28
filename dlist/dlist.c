//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"

void dlist_init(DList *list,void (*destroy)(void *data))
{
	list->size=0;
	list->tail=NULL;
	list->head=NULL;
	list->destroy=destroy;
	return;
}


void dlist_destroy(DList *list)
{
	void *data;
	while(dlist_size(list)>0)
	{
		if(dlist_remove(list,dlist_tail(list),(void **)&data)==0 && (list->destroy!=NULL))
		{
			list->destroy(data);
		}
			
	}
	memset(list,0,sizeof(DList));
	return;
}


int dlist_ins_next(DList *list,DListElmt *element,const void *data)
{
	DListElmt *new_element;

	 /// 除非是空双向链表，否则不允许 element 为 NULL
	if(dlist_size(list)!=0 && element==NULL)
		return -1;

	if ((new_element=(DListElmt *)malloc(sizeof(DListElmt)))==NULL)
		return -1;

	new_element->data=(void *)data;

	if(dlist_size(list)==0)
	{
		list->head=new_element;
		list->tail=new_element;
		new_element->prev=NULL;
		new_element->next=NULL;
	}
	else
	{
		new_element->prev=element;
		new_element->next=element->next;

		if(element->next==NULL)
		{ list->tail=new_element;}
		else
		{
		element->next->prev=new_element;
		}

		element->next=new_element;
	
	}
	list->size++;
	return 0;
}


int dlist_ins_prev(DList *list,DListElmt *element,const void *data)
{
	DListElmt * new_element;
	if( element==NULL && dlist_size(list)!=0 )
		return -1;

	if ((new_element=(DListElmt *)malloc(sizeof(DListElmt)))==NULL)
		return -1;

	new_element->data=(void *)data;

	if(dlist_size(list)==0)
	{
		list->head=new_element;
		list->head->prev=NULL;
		list->head->next=NULL;
		list->tail=new_element;
	
	}
	else
	{
		new_element->next=element;
		new_element->prev=element->prev;
		

		if(element->prev==NULL)
		{ 
			list->head=new_element;
		}
		else
		{
			element->prev->next=new_element;
		}

		element->prev=new_element;
	
	}
	list->size++;
	return 0;
}



int dlist_remove(DList *list, DListElmt *element, void **data)
{

	

  /// 禁止删除 element 为空或空链表的数据
  if (element == NULL || dlist_size(list) == 0) return -1;

  *data = element->data;
  
  if (element == list->head) {
    
    /// 处理删除头部元素
    
    list->head = element->next;
    
    if (list->head == NULL) {
      list->tail = NULL;
    } else {
      element->next->prev = NULL;
    }
  } else {
    
    /// 处理删除非头部元素
    
    element->prev->next = element->next;
    
    if (element->next == NULL) {
      list->tail = element->prev;
    } else {
      element->next->prev = element->prev;
    }
  }
  
  /// 清理旧结点元素的
  free(element);
  
  /// 更新链表的 size
  list->size--;
  
  return 0;
}





