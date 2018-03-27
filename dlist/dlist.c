﻿//#include <stdio.h>
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


//int dlist_ins_next(DList *dlist,DListElmt *element,const void *data)
//{
//	return 0;
//}
//
//
//int dlist_ins_prev(DList *dlist,DListElmt *element,const void *data)
//{
//	return 0;
//}
//
//
int dlist_remove(DList *list,DListElmt *element,const void **data)
{
	if(element==NULL || dlist_size(list)==0)
		return -1;

	*data=element->data;
	if(element=list->head)
	{
		list->head=element->next;
		if(list->head==NULL)
			list->tail=NULL;
		else
		element->next->prev=NULL;
	}
	else
	{
		element->prev->next=element->next;
		if(element->next==NULL)
		{
			list->tail=element->prev;
		}
		else
			element->next->prev=element->prev;	
	}
	free(element);
	list->size--;

	return 0;
}
//
