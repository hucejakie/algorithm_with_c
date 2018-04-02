#ifndef SET_H
#define SET_H

#include <stdlib.h>
#include "list.h"

typedef List Set;

void set_init(Set *set, int(*match)(const void *key1, const void *key2), void(*destroy)(const void *data));
#define set_destroy list_destroy

int set_insert(Set *set, const void *data);
int set_remove(Set *set,  void **data);
int set_union(Set *setu, const Set *set1, const Set set2);
int set_difference(Set *sedu, const Set *set1, const Set set2);
int set_is_member(Set *set, const void *data);
int set_is_subset(Set *set1, Set *set2);
int set_is_equal(Set *set1, Set *set2);

#define set_size(set) ((set)->size)
#endif // !SET_H


