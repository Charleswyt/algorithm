#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#define YES 1
#define NO  0
#define TRUE 1
#define FALSE 0
#define LIST_INIT_SIZE 10			// 线性表初始化长度

#include <stdio.h>
#include <stdlib.h>

// 变量定义
typedef int ElementType;

typedef struct{
	ElementType* arrData;			// 线性表首地址
	int iListLength;				// 线性表长度(用于表示线性表当前的存储状态)
	int iListSize;					// 线性表空间(用于表示线性表初始化时申请的变量空间)
}LinearList;

// 函数声明
void init_list(LinearList* L);		// 初始化线性表
void destroy_list(LinearList* L);	// 销毁线性表
void clear_list(LinearList* L);		// 线性表置空
int  isEmpty_list(LinearList* L);	// 判断线性表是否为空
int  isFull_list(LinearList* L);	// 判断线性表是否已满


// 函数定义
void init_list(LinearList* L) {
	L->arrData = (ElementType*)malloc(sizeof(ElementType) * LIST_INIT_SIZE);
	if (L->arrData == NULL) {
		printf("线性表初始化失败\n");
	}
	L->iListLength = 0;
	L->iListSize = LIST_INIT_SIZE;
}

void destroy_list(LinearList* L) {
	if (L->arrData == NULL) {
		printf("当前线性表尚未初始化\n");
		return;
	}
	else {
		L->arrData = NULL;
		L->iListLength = 0;
		L->iListSize = 0;
	}
}

void clear_list(LinearList* L) {

}

int  isEmpty_list(LinearList* L) {
	return 0;
}
#endif // !LINEAR_LIST_H
