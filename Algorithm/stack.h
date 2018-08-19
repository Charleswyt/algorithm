//#ifndef STACK_H
//#define STACK_H
//
//#define YES 1
//#define NO  0
//#define INIT_STACK_LENGTH 10
//#define STACK_INCREMENT 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// 变量定义
//typedef int ElementType;
//
//// 静态数组
//typedef struct Stack{
//	ElementType stack[INIT_STACK_LENGTH];
//	int iTopPoint;
//}Stack_Static;
//
//// 动态数组
//typedef struct Stack {
//	ElementType* pBase;		// 栈底指针
//	ElementType* pTop;		// 栈顶指针
//	int  iStackLength;		// 堆栈大小
//}Stack_Dynamic;
//
//// 单链表实现
//typedef struct STACK_NODE
//{
//	ElementType iNum;
//	struct STACK_NODE *next;
//} StackNode;
//
///*
// 栈（stack）的显著特点是后进先出（Last - In First - Out, LIFO），
// 其实现的方法有三种可选方案：静态数组、动态分配的数组、动态分配的链式结构。
// 1.静态数组：特点是要求结构的长度固定，而且长度在编译时候就得确定。其优点是结构简单，实现起来方便而不容易出错。而缺点就是不够灵活以及固定长度不容易控制，适用于知道明确长度的场合。
// 2.动态数组：特点是长度可以在运行时候才确定以及可以更改原来数组的长度。优点是灵活，缺点是由此会增加程序的复杂性。
// 3.链式结构：特点是无长度上线，需要的时候再申请分配内存空间，可最大程度上实现灵活性。缺点是链式结构的链接字段需要消耗一定的内存，在链式结构中访问一个特定元素的效率不如数组。
//*/
//
///************************************************************************/
///*                             静态数组实现                             */
///************************************************************************/
//
//// 函数声明
//void init_stack(Stack_Static* pStack);								// 初始化栈空间
//void push(int iNumber);												// 数据入栈
//void pop(void);														// 数据出栈
//int  isEmpty_stack(void);											// 判断当前栈是否空
//int  isFull_stack(void);											// 判断当前栈是否满
//void clear_stack(void);												// 清空栈
//int  get_stack_length(void);										// 获取栈大小
//void printf_stack_info(void);										// 显示栈内元素
//ElementType get_top(void);											// 获取栈顶元素
//void test_stack_static(void);										// 测试函数
//
//// 函数定义
//void init_stack(Stack_Static* pStack) {
//	Stack_Static stack;
//	pStack = &stack;
//	pStack->iTopPoint = -1;
//}
//
//void push(int iNumber) {
//	if (isFull_stack() == YES) {
//		printf("当前栈已满\n");
//	}
//	else {
//		stack[iTopPoint++] = iNumber;
//		//printf("iTopPoint = %d\n", iTopPoint);
//	}
//}
//
//void pop(void) {
//	if (isEmpty_stack() == YES) {
//		printf("当前栈为空\n");
//	}
//	else{
//		printf("元素%d出栈\n", stack[iTopPoint-1]);
//		iTopPoint--;
//		//printf("iTopPoint = %d\n", iTopPoint);
//	}
//}
//
//int isEmpty_stack(void) {
//	int iFlag;
//	if (iTopPoint == -1) {
//		iFlag = YES;
//	}
//	else {
//		iFlag = NO;
//	}
//	return iFlag;
//}
//
//int isFull_stack(void) {
//	int iFlag;
//	if (iTopPoint == INIT_STACK_LENGTH - 1) {
//		iFlag = YES;
//	}
//	else {
//		iFlag = NO;
//	}
//	return iFlag;
//}
//
//void clear_stack(void) {
//	iTopPoint = -1;
//}
//
//int get_stack_length(void) {
//	return INIT_STACK_LENGTH;
//}
//
//void printf_stack_info(void) {
//	int iTempPoint;
//	if (isEmpty_stack() == YES) {
//		printf("当前栈为空\n");
//		return;
//	}
//	else {
//		iTempPoint = -1;
//		printf("当前栈内元素为：");
//		while(iTempPoint != iTopPoint){
//			printf("%d ", stack[iTempPoint++]);
//		}
//		printf("\n");
//	}
//}
//
//ElementType get_top(void) {
//	return stack[iTopPoint];
//}
//
//void test_stack_static(void) {
//	pop();
//	push(10); push(9); push(7); push(6); push(5);
//	printf_stack_info();
//	printf("当前栈大小为：%d\n", get_stack_length());
//	pop(); pop();
//	printf_stack_info();
//	printf("%d", iTopPoint);
//
//}
//
///************************************************************************/
///*                             动态数组实现                             */
///************************************************************************/
// 
//// 函数声明
//void create_stack(Stack_Dynamic* pStack);										// 创建堆栈
//void destory_stack(Stack_Dynamic* pStack);										// 销毁堆栈
//void fill_stack(Stack_Dynamic* pStack, ElementType* arrData, int iArrLength);	// 堆栈赋值
//void push(Stack_Dynamic* pStack, int iNumber);									// 数据入栈
//void pop(Stack_Dynamic* pStack);												// 数据出栈
//int  isEmpty_stack(Stack_Dynamic* pStack);										// 判断当前栈是否空
//int  isFull_stack(Stack_Dynamic* pStack);										// 判断当前栈是否满
//void clear_stack(Stack_Dynamic* pStack);										// 清空栈
//int  get_stack_length(Stack_Dynamic* pStack);									// 获取栈大小
//void printf_stack_info(Stack_Dynamic* pStack);									// 显示栈内元素
//ElementType get_top(Stack_Dynamic* pStack);										// 获取栈顶元素
//
//void test_stack_dynamic(void);													// 测试代码
//
//// 函数定义
//void create_stack(Stack_Dynamic* pStack) {
//	pStack->pBase = (ElementType*)malloc(sizeof(ElementType) * INIT_STACK_LENGTH);
//	if (!pStack->pBase) {
//		printf("栈初始化失败\n");
//	}
//	else {
//		pStack->pTop = pStack->pBase;
//		pStack->iStackLength = INIT_STACK_LENGTH;
//		printf("栈初始化成功\n");
//	}
//}
//
//void fill_stack(Stack_Dynamic* pStack, ElementType* arrData, int iArrLength) {
//	int iFlag;
//	int i;
//	iFlag = isEmpty_stack(pStack);
//	if (iFlag == YES) {
//		printf("当前栈为空\n");
//		return;
//	}
//	else {
//		i = 0;
//		pStack->pTop = pStack->pBase;
//		if (iArrLength > INIT_STACK_LENGTH) {
//			pStack->pBase = (ElementType*)realloc(pStack->pBase, sizeof(ElementType) * iArrLength);
//			pStack->iStackLength = iArrLength;
//			while (pStack->pTop - pStack->pBase < iArrLength) {
//				*(pStack->pTop) = arrData[i];
//				pStack->pTop++;
//				i++;
//			}
//		}
//		else {
//			while (pStack->pTop - pStack->pBase < iArrLength) {
//				*(pStack->pTop) = arrData[i];
//				pStack->pTop++;
//				i++;
//			}
//			while(pStack->pTop - pStack->pBase >= iArrLength && pStack->pTop - pStack->pBase < INIT_STACK_LENGTH){
//					*(pStack->pTop) = 0;
//					pStack->pTop++;
//			}
//		}
//	}
//}
//
//void printf_stack_info(Stack_Dynamic* pStack) {
//	ElementType* pTemp;
//	int iFlag;
//	iFlag = isEmpty_stack(pStack);
//	if (iFlag == YES) {
//		printf("当前栈为空\n");
//		printf("当前栈大小为：%d\n", pStack->iStackLength);
//		return;
//	}
//	else{
//		pTemp = pStack->pBase;
//
//		printf("堆栈当前各元素分别为：\n");
//		while (pTemp != pStack->pTop) {
//			printf("%d ", *pTemp);
//			pTemp++;
//		}
//		printf("\n当前栈大小为：%d\n", pStack->iStackLength);
//	}
//}
//
//void destory_stack(Stack_Dynamic* pStack) {
//	if(pStack == NULL){
//		printf("当前栈尚未初始化\n");
//		return;
//	}
//	else {
//		free(pStack->pBase);
//		pStack = NULL;
//	}
//}
//
//int isEmpty_stack(Stack_Dynamic* pStack) {
//	int iFlag;
//	if (pStack->pBase == pStack->pTop) {
//		iFlag = YES;
//	}
//	else {
//		iFlag = NO;
//	}
//
//	return iFlag;
//}
//
//ElementType get_top(Stack_Dynamic* pStack) {
//	int iFlag;
//	ElementType TopNumber;
//
//	iFlag = isEmpty_stack(pStack);
//	if (iFlag == YES) {
//		printf("当前栈为空\n");
//		return 0;
//	}
//	else {
//		TopNumber = *(pStack->pTop - 1);
//	}
//	return TopNumber;
//}
//
//int isFull_stack(Stack_Dynamic* pStack) {
//	int iFlag;
//	if (pStack->pTop - pStack->pBase == pStack->iStackLength) {
//		iFlag = YES;
//	}
//	else {
//		iFlag = NO;
//	}
//	return iFlag;
//}
//
//void push(Stack_Dynamic* pStack, int iNumber) {
//	int iFlag;
//	iFlag = isFull_stack(pStack);
//	if (iFlag == YES) {
//		pStack->pBase = (ElementType*)realloc(pStack->pBase, 
//			sizeof(ElementType) * (pStack->iStackLength + STACK_INCREMENT));
//		pStack->iStackLength++;
//		*(pStack->pTop) = iNumber;
//		pStack->pTop++;
//		printf("元素%d入栈\n", iNumber);
//	}
//	else {
//		*(pStack->pTop) = iNumber;
//		pStack->pTop++;
//		printf("元素%d入栈\n", iNumber);
//	}
//}
//
//void pop(Stack_Dynamic* pStack) {
//	int iFlag;
//	iFlag = isEmpty_stack(pStack);
//	if (iFlag == YES) {
//		printf("当前栈为空\n");
//		return;
//	}
//	else{
//		printf("元素%d出栈\n", *(pStack->pTop - 1));
//		pStack->pTop--;
//	}
//}
//
//void clear_stack(Stack_Dynamic* pStack) {
//	int iFlag;
//	iFlag = isEmpty_stack(pStack);
//	if (iFlag == YES) {
//		printf("当前栈为空\n");
//	}
//	else {
//		pStack->pTop = pStack->pBase;
//		pStack->iStackLength = 0;
//		printf("当前栈已清空\n");
//	}
//}
//
//int get_stack_length(Stack_Dynamic* pStack) {
//	int iStackLength;
//	iStackLength = pStack->iStackLength;
//	return iStackLength;
//}
//
//void test_stack_dynamic(void) {
//	Stack_Dynamic stack, *pStack;
//	ElementType* arrData;
//	int iArrLength = 6;
//	ElementType Min = 10, Max = 100;
//
//	pStack = &stack;
//	arrData = (ElementType*)malloc(sizeof(ElementType) * iArrLength);
//	genRand(arrData, Min, Max, iArrLength);
//	
//	create_stack(pStack);
//	fill_stack(pStack, arrData, iArrLength);
//	printf_stack_info(pStack);
//	clear_stack(pStack);
//	pop(pStack); pop(pStack); pop(pStack);
//	push(pStack, 1); push(pStack, 2); push(pStack, 3); push(pStack, 4); push(pStack, 5);
//	printf_stack_info(pStack);
//	destory_stack(pStack);
//
//	free(arrData);
//	arrData = NULL;
//}
//
///************************************************************************/
///*                               链表实现                               */
///************************************************************************/
//
//// 函数声明
//void push(StackNode* pStack);									// 入栈
//void pop(StackNode* pStack);
//int  isEmpty(StackNode* pStack);								// 判断当前栈是否为空
//
//void test_stack_link(void);										// 测试程序
//
//// 函数定义
//int isEmpty(StackNode* pStack) {
//	int iFlag;
//	if (pStack == NULL) {
//		iFlag = YES;
//	}
//	else {
//		iFlag = NO;
//	}
//	return iFlag;
//}
//
//void push(StackNode* pStack, int iNumber) {
//
//}
//
//void test_stack_link(void) {
//	StackNode stack, *pStack;
//	pStack = &stack;
//	if (isEmpty(pStack) == YES) {
//		printf("当前栈为空\n");
//	}
//}
//
//#endif // !STACK_H
