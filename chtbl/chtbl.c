#include <stdlib.h>
#include "list.h"
#include "chtbl.h"

int chtbl_init(CHTBL *htbl,int buckets,int (*h)(const void *key),
	int(*match)(const void *key1,const void *key2),
 void	(*destroy)(void *data))
	
{
	int i;
	if((htbl->table=(List *)malloc(buckets*sizeof(List)))==NULL)
		return -1;

	htbl->buckets=buckets;
	for(i=0;i<htbl->buckets;i++)
	{
		list_init(&htbl->table[i],destroy);
	}
	htbl->destroy=destroy;
	htbl->h=h;
	htbl->match=match;
	htbl->size=0;
	return 0;
}