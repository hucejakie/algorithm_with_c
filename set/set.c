#include "set.h"
#include "list.h"

void set_init(Set * set, int(*match)(const void *key1, const void *key2), void(*destroy)(const void *data))
{
	
	list_init(set,destroy);
	set->match = match;

}

int set_insert(Set * set, const void * data)
{
	if (set_is_member(set, data) == 0)
		return 1;

	return list_ins_next(set,list_tail(set),data);
}

int set_remove(Set * set, void ** data)
{
	ListElmt *member, *prev;
	prev = NULL;
	for (member = list_head(set);member != NULL;member = list_next(member))
	{
		
		if (set->match(data, list_data(member)))
		{
			break;
			prev = member;
		}
		
		
	}
	if (member == NULL)
		return -1;
	return list_rem_next(set,member,data);
}

int set_union(Set * setu, const Set * set1, const Set set2)
{
	return 0;
}

int set_difference(Set * sedu, const Set * set1, const Set set2)
{
	return 0;
}

int set_is_member(Set * set, const void * data)
{
	return 0;
}

int set_is_subset(Set * set1, Set * set2)
{
	return 0;
}

int set_is_equal(Set * set1, Set * set2)
{
	return 0;
}
