#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void print_list(const List *list)
{
	ListEmt *element;
	int *data,i;
	fprintf(stdout,"List size is %d \n",list_size(list));
}

int main()
{	
	List list;
	ListEmt *element;
	int *data,i;

	list_init(&list,free);

	print_list(&list);

	/*int a=	fecttail(4,1);
	int *iptr=&a;
	printf("*iptr=%d,iptr=%d\n,count=%d",*iptr,(int)iptr,count);
*/
	
	//char *sptr="abc";
	//char *tptr=(char *)malloc(1);
	//char *str="hello,world!";
	//*tptr=*sptr;	
	//printf("hello,world\n");
	system("PAUSE");
	return 0;
	
}

//int (*add)(int x,int y);
//
//int count=0;
//
//int fect(int n)
//{
//	if (n<0)
//		return 0;
//	else if(n==0 ||n==1)
//		return 1;
//	else
//		return n*fect(n-1);
//
//		count++;
//}
//
//int fecttail(int n ,int a)
//{
//	count++;
// if (n<0)
//	 return 0;
// if (n==0 || n==1)
//	 return 1;
// else
//	 return fecttail(n-1,n*a);
//}


