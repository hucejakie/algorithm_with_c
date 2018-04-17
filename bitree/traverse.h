#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <stdlib.h>
#include"list.h"

int bitree_preorder(const BiTreeNode *node,List *list);
int bitree_inorder(const BiTreeNode *node,List *list);
int bitree_postorder(const BiTreeNode *node,List *list);

#endif