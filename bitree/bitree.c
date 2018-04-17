#include <stdlib.h>
#include <string.h>
#include"bitree.h"

void bitree_init(BiTree *tree,void (*destroy)(void *data))
{
	tree->size=0;
	tree->destroy=destroy;
	tree->root=NULL;
	return;
}

void bitree_destroy(BiTree *tree)
{
	bitree_rem_left(tree,NULL);

	memset(tree,0,sizeof(BiTree));
	return;
}

int bitree_ins_left(BiTree *tree,BiTreeNode *node,const void *data)
{
	BiTreeNode *new_node,**position;
	if(node==NULL)
	{
		///node為NULL，且size =0，表示空樹，即插入根節點
		if(bitree_size(tree)>0)
			return -1;

		position=&tree->root;
	}
	else 
	{
		
		///左子節點必須為空值才能插入
		if(bitree_left(node)!=NULL)
			return -1;

		position=&node->left;
	}

	if((new_node=(BiTreeNode *)malloc(sizeof(BiTreeNode)) )==NULL)
		return -1;
	new_node->data=(void *)data;
	new_node->left=NULL;
	new_node->right=NULL;
	*position=new_node;

	tree->size++;


	return 0;
}

int bitree_ins_right(BiTree *tree,BiTreeNode *node,const void *data)
{
	BiTreeNode *new_node,**position;
	if(node==NULL)
	{
		///node為NULL，且size =0，表示空樹，即插入根節點
		if(bitree_size(tree)>0)
			return -1;

		position=&tree->root;
	}
	else 
	{
		
		///左子節點必須為空值才能插入
		if(bitree_right(node)!=NULL)
			return -1;

		position=&node->right;
	}

	if((new_node=(BiTreeNode *)malloc(sizeof(BiTreeNode)) )==NULL)
		return -1;
	new_node->data=(void *)data;
	new_node->left=NULL;
	new_node->right=NULL;
	*position=new_node;

	tree->size++;


	return 0;
}

void bitree_rem_left(BiTree *tree,BiTreeNode *node)
{
 BiTreeNode    **position;
  
  /// 不允许在空树中执行移除
  if (bitree_size(tree) == 0) return;
  
  /// 确定移除结点的位置
  if (node == NULL) {
    position = &tree->root;
  } else {
    position = &node->left;
  }
  
  /// 移除结点（按照后序遍历从参数 node 的左子结点开始依次移除）
  if (*position != NULL) {
    
    bitree_rem_left(tree, *position);
    bitree_rem_right(tree, *position);
    
    if (tree->destroy != NULL) {
      /// 执行用户指定的 destroy 函数
      tree->destroy((*position)->data);
    }
    
    free(*position);
    *position = NULL;
    
    /// 更新树的 size
    tree->size--;
    
  }
  
  return;
 }


void bitree_rem_right(BiTree *tree,BiTreeNode *node)
{
	BiTreeNode **position;
	if (bitree_size(tree)==0)
		return ;
	if(node==NULL)
	{
		position=&tree->root;
	}
	else
	{
		position=&node->right;
	}

	if(*position!=NULL)
	{
		bitree_rem_left(tree,*position);
		bitree_rem_right(tree,*position);
		if(tree->destroy!=NULL)
		{
			tree->destroy((*position)->data);
		}
		free(*position);
		*position=NULL;
		tree->size--;
	}

	return ;
}


int bitree_merge(BiTree *merge,BiTree *left,BiTree *right,const void *data)
{
	bitree_init(merge,left->destroy);
	///根節點插入失敗，退出
	if(bitree_ins_left(merge,NULL,data)!=0)
	{
		bitree_destroy(merge);
		return -1;
	}
	bitree_root(merge)->left=bitree_root(left);
	bitree_root(merge)->right=bitree_root(right);
	merge->size=merge->size+left->size+right->size;

	left->root=NULL;
	left->size=0;

	right->root=NULL;
	right->size=0;

	return 0;
}