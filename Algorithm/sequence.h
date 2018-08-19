#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <time.h>
#include <stdlib.h>

// 变量定义
typedef int ElementType;

// 函数声明
void genConst(int* arrNumber, int iArrLength, int iNumber);						// 常数列生成器
void genNaturalNumber(int* arrNumbr, int iArrLength);							// 自然数数列生成器
void genArithmeticSequence(int* arrNumber, int iArrLength,
	int iFirstItem, int iDistance);												// 等差数列生成器
void genGeometricSequence(int* arrNumber, int iArrLength,
	int iFirstItem, int iRatio);												// 等比数列生成器
void genFibonacci(int* arrFibonacci, int iArrLength);							// 斐波那契数列生成器
void genCatalan(int* arrNumber, int iArrLength);								// 卡特兰数列生成器
void genPrimeNumbe(int* arrNumber, int iArrLength);								// 质数数列生成器
void genRand(int* arrNumber, int iMin, int iMax, int iArrLength);				// 随机数列生成器

void inverse_list(ElementType* arrData, int iArrLength);						// 序列元素逆序
void show_list(ElementType* arrData, int iArrLength);							// 显示序列中的元素
void arr_copy(ElementType* arrSrc, ElementType* arrDest, int iDestLength);		// 数组元素拷贝
ElementType get_number(ElementType* arrData, int iArrLength, int iPos);			// 获取列表中指定下标的元素

void sequence_test(void);														// 测试函数

// 函数定义
void genConst(int* arrNumber, int iArrLength, int iNumber) {
	int i;
	for (i = 0; i < iArrLength; i++) {
		arrNumber[i] = iNumber;
	}
}

void genNaturalNumber(int* arrNumbr, int iArrLength) {
	int i;
	for (i = 0; i < iArrLength; i++) {
		arrNumbr[i] = i;
	}
}

void genArithmeticSequence(int* arrNumber, int iArrLength,
	int iFirstItem, int iDistance) {
	int i;
	for (i = 0; i < iArrLength; i++) {
		arrNumber[i] = iFirstItem + i * iDistance;
	}
}

void genGeometricSequence(int* arrNumber, int iArrLength,
	int iFirstItem, int iRatio) {
	int i;
	arrNumber[0] = iFirstItem;
	for (i = 1; i < iArrLength; i++) {
		arrNumber[i] = arrNumber[i-1] * iRatio;
	}
}

void genRand(int* arrNumber, int iMin, int iMax, int iArrLength) {
	int i;
	srand((unsigned)time(NULL));						// 用时间做种，每次产生随机数不一样
	for (i = 0; i < iArrLength; i++) {
		arrNumber[i] = rand() % (iMax + 1) + iMin;
	}
}

void genFibonacci(int* arrFibonacci, int iArrLength) {
	int i;
	arrFibonacci[0] = 1;
	arrFibonacci[1] = 1;
	for (i = 2; i < iArrLength; i++) {
		arrFibonacci[i] = arrFibonacci[i - 1] + arrFibonacci[i - 2];
	}
}

void genCatalan(int* arrNumber, int iArrLength) {
	int i, j;
	arrNumber[0] = 1;
	arrNumber[1] = 1;
	for (i = 2; i < iArrLength; i++) {
		arrNumber[i] = 0;
		for (j = 0; j < i; j++) {
			arrNumber[i] += arrNumber[j] * arrNumber[i-j-1];
		}
	}
}

void genPrimeNumbe(int* arrNumber, int iArrLength) {
	int i, j, n;
	i = 1;
	arrNumber[0] = 2;
	for (n = 3; i < iArrLength; n++) {
		for (j = 2; n % j; j++)
			;
		if (j == n) {
			arrNumber[i] = n;
			i++;
		}
	}
}

void inverse_list(ElementType* arrData, int iArrLength) {
	int i;
	ElementType iTemp;
	for (i = 0; i < iArrLength / 2; i++) {
		iTemp = arrData[i];
		arrData[i] = arrData[iArrLength - i - 1];
		arrData[iArrLength - i - 1] = iTemp;
	}
}

void show_list(ElementType* arrData, int iArrLength) {
	int i;
	for (i = 0; i < iArrLength; i++) {
		printf("%d ", arrData[i]);
	}
	printf("\n");
}

void arr_copy(ElementType* arrSrc, ElementType* arrDest, int iDestLength) {
	int i;
	for (i = 0; i < iDestLength; i++) {
		arrDest[i] = arrSrc[i];
	}
}

ElementType get_number(ElementType* arrData, int iArrLength, int iPos) {
	if (iPos > iArrLength - 1) {
		return arrData[iArrLength - 1];
	}
	else{
		return arrData[iPos];
	}
}

void sequence_test(void) {
	int* arrData;
	int  iArrLength = 10;

	arrData = (int*)malloc((sizeof(int) * iArrLength));
	genPrimeNumbe(arrData, iArrLength);
	show_list(arrData, iArrLength);
	inverse_list(arrData, iArrLength);
	show_list(arrData, iArrLength);

	free(arrData);
	arrData = NULL;
}

#endif // !SEQUENCE_H
