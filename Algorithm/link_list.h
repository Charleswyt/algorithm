#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int iData;
	struct Node* next;
}List;

/*
 * 链表的基本操作：
 * 创建、删除、修改、插入、排序
 * 判断链表是否为空
 */

// 创建链表会有以下四种组合：(不)带头结点，头(尾)插法
List* init_list_no_head_front();
List* init_list_no_head_back();

List * init_list_no_head_back() {
	List* previous, *current, *head;
	int iData;

	// 判断当前有无值输入，若没有则直接返回结点
	if (scanf("%d", &iData) != EOF) {
		previous = (List*)malloc(sizeof(List));
		head = previous;
		previous->iData = iData;
	}

	else
		return head;

	// 现在已经确保了第一个节点有输入，若第二个结点不输入则会跳过以下循环
	current = (List*)malloc(sizeof(List));
	while (scanf("%d", &current->iData) != EOF) {
		previous->next = current;
		previous = current;
		current = (List*)malloc(sizeof(List));
	}
	previous->next = NULL;//选用prev而不是current是为了避免没有输入第二个结点的情况
	return head;
}

#endif /* LIST_H */
