#include "sort.h"
#include "search.h"
#include "stack.h"
#include "algorithm.h"


#define LOAD_LEAK_DETECTOR

// 是否加载内存泄漏检测工具
#ifdef LOAD_LEAK_DETECTOR
#include "vld.h"
#endif

void main(void) {
	int * arrArray = new int[8];
	for (int i = 0; i < 8; i++) {
		cin >> arrArray[i];
	}
	FindPeakValue(arrArray, 8);

	system("pause");
}
