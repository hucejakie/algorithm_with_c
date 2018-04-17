
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv)
{
	int **data=(int *)malloc(sizeof(int *));
	int *ip=NULL;
	int a=100;

	//data=&ip;

	ip=&a;
	*data=ip;
	//data=&ip;
  
	//fprintf(stdout,"value=",**value );
	getchar();
	return 0;
}