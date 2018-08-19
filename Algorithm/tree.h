#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

typedef int ElementType;

typedef struct TreeNode
{
	ElementType data;				// 数值域
	struct TreeNode* pLeftChiled;	// 左节点
	struct TreeNode* pRightChild;	// 右节点
}TreeNode，*pTreeNode;

// 函数声明
void create_tree(TreeNode** pRoot, int * arrData ,int iArrLength);	// 创建树结构
int  isEmpty_tree(TreeNode* pRoot);									// 判断当前树结构是否非空

// 函数定义
void create_tree(TreeNode** pRoot, ElementType * arrData) {

}

#endif // !TREE_H
