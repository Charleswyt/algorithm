#ifndef QUENE_H
#define QUENE_H

#define INIT_QUENE_LENGTH 10
#define QUENE_INCREMENT   1

// 变量定义
typedef int ElementType;


typedef struct Quene {
	ElementType* pBase;		// 栈底指针
	ElementType* pTop;		// 栈顶指针
	int  iStackLength;		// 堆栈大小
}Stack;



#endif // !QUENE_H
