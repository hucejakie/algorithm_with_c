#ifndef CHTbl_H

#define CHTbl_H

#include <stdlib.h>
#include "list.h"

typedef struct CHTbl_
{
	int buckets;

	int (*h)(const void *key);
	int (*match)(const void *key1,const void *key2);
	void (*destroy)(void *data);	
	int size;
	List *table;

}CHTbl;

int CHTbl_init(CHTbl *htbl,int buckets,
	int (*h)(const void *key),
	int (*match)(const void *key1,const void *key2),
	void (*destroy)(void *data));

void CHTbl_destroy(CHTbl *htbl);

int CHTbl_insert(CHTbl *htbl,const void *data);

int CHTbl_remove(CHTbl *htbl, void **data);

int CHTbl_lookup(CHTbl *htbl,void **data);

#define CHTbl_size(htbl)((htbl)->size)


#endif