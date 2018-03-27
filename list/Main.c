//#include <stdlib.h>
//#include <stdio.h>
//#include "list.h"
//
//static void print_list(const List *list)
//{
//	ListEmt *element;
//	int *data,i;
//
//	fprintf(stdout,"->List size is %d \n",list_size(list));
//	i=0;
//	element=list_head(list);
//	while(1)
//	{
//	 data=list_data(element);
//	 fprintf(stdout,"->List[%03d]=%03d \n",i,*data);
//	 i++;
//	 if(list_is_tail(element))
//	 {break;}
//	 else
//	 {
//	 element=list_next(element);
//	 }
//	}
//	//
//
//	return;
//}
//
//int main()
//{	
//	List list;
//	ListEmt *element;
//	int *data,i;
//
//	list_init(&list,free);
//
//	//print_list(&list);
//
//	element=list_head(&list);
//	for(i=10;i>0;i--)
//	{
//	 if((data=(int *)malloc(sizeof(int)))==NULL)
//		 return -1;
//	 *data=i;
//	 if(list_ins_next(&list,NULL,data)!=0) return 1;
//	
//	}
//
//	print_list(&list);
//
//	element=list_head(&list);
//	for(i=0;i<7;i++)
//	{
//	element=list_next(element);
//	}
//	data=list_data(element);
//	fprintf(stdout,"Removing an element after the one  containing %003d \n",*data);
//	if(list_rem_next(&list,element,(void**)&data)!=0) return 1;
//	print_list(&list);
//
//
//	fprintf(stdout,"Insert 011 at the tail of list \n");
//	*data=11;
//	if(list_ins_next(&list,list_tail(&list),data)!=0) return 1;
//	print_list(&list);
//
//
//	fprintf(stdout,"Removing an element after the first element\n");
//	element=list_head(&list);
//	if(list_rem_next(&list,element,(void**)&data)!=0) return 1;
//	print_list(&list);
//	/*int a=	fecttail(4,1);
//	int *iptr=&a;
//	printf("*iptr=%d,iptr=%d\n,count=%d",*iptr,(int)iptr,count);
//*/
//	
//	//char *sptr="abc";
//	//char *tptr=(char *)malloc(1);
//	//char *str="hello,world!";
//	//*tptr=*sptr;	
//	//printf("hello,world\n");
//	system("PAUSE");
//	return 0;
//	
//}
//
////int (*add)(int x,int y);
////
////int count=0;
////
////int fect(int n)
////{
////	if (n<0)
////		return 0;
////	else if(n==0 ||n==1)
////		return 1;
////	else
////		return n*fect(n-1);
////
////		count++;
////}
////
////int fecttail(int n ,int a)
////{
////	count++;
//// if (n<0)
////	 return 0;
//// if (n==0 || n==1)
////	 return 1;
//// else
////	 return fecttail(n-1,n*a);
////}
//
//
////
////  main.c
////  MasteringAlgorithms
////  Illustrates using a linked list (see Chapter 5).
////
////  Created by YourtionGuo on 18/04/2017.
////  Copyright © 2017 Yourtion. All rights reserved.
////

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void print_list(const List *list)
{
  ListElmt           *element;
  
  int                *data, i;
  
  /// 显示链表
  fprintf(stdout, "-> List size is %d\n", list_size(list));
  
  i = 0;
  element = list_head(list);
  
  while (1) {
    
    data = list_data(element);
    fprintf(stdout, "--> list[%03d]=%03d\n", i, *data);
    
    i++;
    
    if (list_is_tail(element)) {
      break;
    } else {
      element = list_next(element);
    }
  }
  
  return;
}

int main(int argc, const char * argv[])
{
  List               list;
  ListElmt           *element;
  
  int                *data, i;
  
  /// 初始化链表
  list_init(&list, free);
  
  /// 链表操作
  
  element = list_head(&list);
  
  for (i = 10; i > 0; i--) {
    
    if ((data = (int *)malloc(sizeof(int))) == NULL) return 1;
    
    *data = i;
    
    if (list_ins_next(&list, NULL, data) != 0) return 1;
    
  }
  
  print_list(&list);
  
  element = list_head(&list);
  
  for (i = 0; i < 7; i++) {
    element = list_next(element);
  }
  
  data = list_data(element);
  fprintf(stdout, "Removing an element after the one containing %03d\n", *data);
  
  if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
  
  print_list(&list);
  
  fprintf(stdout, "Inserting 011 at the tail of the list\n");
  
  *data = 11;
  if (list_ins_next(&list, list_tail(&list), data) != 0) return 1;
  
  print_list(&list);
  
  fprintf(stdout, "Removing an element after the first element\n");
  
  element = list_head(&list);
  if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
  
  print_list(&list);
  
  fprintf(stdout, "Inserting 012 at the head of the list\n");
  
  *data = 12;
  if (list_ins_next(&list, NULL, data) != 0) return 1;
  
  print_list(&list);
  
  fprintf(stdout, "Iterating and removing the fourth element\n");
  
  element = list_head(&list);
  element = list_next(element);
  element = list_next(element);
  
  if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
  
  print_list(&list);
  
  fprintf(stdout, "Inserting 013 after the first element\n");
  
  *data = 13;
  if (list_ins_next(&list, list_head(&list), data) != 0) return 1;
  
  print_list(&list);
  
  i = list_is_head(&list, list_head(&list));
  fprintf(stdout, "Testing list_is_head...Value=%d (1=OK)\n", i);
  i = list_is_head(&list, list_tail(&list));
  fprintf(stdout, "Testing list_is_head...Value=%d (0=OK)\n", i);
  i = list_is_tail(list_tail(&list));
  fprintf(stdout, "Testing list_is_tail...Value=%d (1=OK)\n", i);
  i = list_is_tail(list_head(&list));
  fprintf(stdout, "Testing list_is_tail...Value=%d (0=OK)\n", i);
  
  /// 销毁链表
  fprintf(stdout, "Destroying the list\n");
  list_destroy(&list);
  system("PAUSE");
  return 0;
}
