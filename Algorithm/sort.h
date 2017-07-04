#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

/************************************************************************/
/*                    排序函数，默认按升序排列                          */
/************************************************************************/

// 变量定义
typedef int ElementType;

typedef struct MostValue {
	ElementType Value;
	int iLocation;
}MostValue;	// 用于确定数组中最大值、最小值的数值和位置

// 函数声明
void swap(ElementType* iNumA, ElementType* iNumB);							// 交换两个数
void sort_quick_recursion(ElementType * arrData, int iLeft, int iRight);	// 快速排序递归函数
void merge(ElementType* arrData, int iLeft, int iMid, int iRight);			// 序列合并
void sort_merge_recursion(ElementType* arrData, int iLeft, int iRight);		// 归并排序递归函数

// 所有排序算法采用相同的接口，arrData表示待排序数组，iArrLength表示数组大小
void sort_bubble(ElementType * arrData, int iArrLength);					// 冒泡排序
void sort_insert(ElementType * arrData, int iArrLength);					// 插入排序
void sort_quick(ElementType* arrData, int iArrLength);						// 快速排序
void sort_selection(ElementType* arrData, int iArrLength);					// 选择排序
void sort_shell(ElementType* arrData, int iArrLength);						// 希尔排序
void sort_merge(ElementType* arrData, int iArrLength);						// 归并排序
void sort_bucket(ElementType* arrData, int iArrLength);						// 桶排序
void sort_radix(int* arrData, int iArrLength);								// 基数排序
void sort_heap(int* arrData, int iArrLength);								// 堆排序

MostValue find_max(ElementType* arrData, int iArrLength);					// 找到数组中最大值的数值和位置
MostValue find_min(ElementType* arrData, int iArrLength);					// 找到数组中最小值的数值和位置
int find_max_length(int* arrData, int iNumber);								// 找到数组中最大数的长度（即找到最大位数）
int get_number(int iNumber, int iPos);										// 得到数字中各位次的数值
void heap_adjust(int* arrData, int i, int iArrLength);						// 根据数组构建大顶堆 

void sort_test(void);														// 测试函数

// 函数定义
void swap(ElementType* NumA, ElementType* NumB)
{
	// 交换两个数的值
	ElementType NumTemp;

	NumTemp = *NumA;
	*NumA = *NumB;
	*NumB = NumTemp;
}

void sort_bubble(ElementType* arrData, int iArrLength) {
	// 冒泡排序
	int i, j;		// 循环下标

	for (i = 0; i < iArrLength - 1; i++){
		for (j = i + 1; j < iArrLength; j++){
			if (arrData[i] > arrData[j]){
				swap(&arrData[i], &arrData[j]);
		
			}
		}
	}
}

void sort_insert(ElementType* arrData, int iArrLength){
	// 插入排序
	/* 算法步骤：
	* 1.从第一个元素开始，该元素可以认为已经被排序
	* 2.取出下一个元素，在已经排序的元素序列中从后向前扫描
	* 3.如果该元素（已排序）大于新元素，将该元素移到下一位置
	* 4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
	* 5.将新元素插入到该位置中
	* 6.重复步骤2
	*/

	int i, j;				// 循环下标
	ElementType Temp;		// 用于交换的中间变量

	for (i = 1; i < iArrLength; i++) {
		Temp = arrData[i];
		for (j = i; j > 0 && arrData[j - 1] > Temp; j--) {
			arrData[j] = arrData[j - 1];
		}
		arrData[j] = Temp;
	}
}

void sort_quick_recursion(ElementType* arrData, int iLeft, int iRight) {
	// 快速排序
	/* 算法原理：
	* 1.从数列中挑出一个元素作为“基准”
	* 2.重新对数列进行排序，比基准小的放在前面，比基准大的放在后面
	* 3.递归地把小于基准值元素的子数列和大于基准值元素的子数列排序
	**/
	int i, j;
	ElementType Pivot;
	if (iLeft < iRight) {
		i = iLeft; j = iRight;
		Pivot = arrData[iLeft];
		while (i < j) {
			while (i < j && arrData[j] >= Pivot)
				j--;
			if (i < j)
				arrData[i++] = arrData[j];
			while (i < j && arrData[i] < Pivot)
				i++;
			if (i < j)
				arrData[j--] = arrData[i];
		}
		arrData[i] = Pivot;
		sort_quick_recursion(arrData, iLeft, i - 1);
		sort_quick_recursion(arrData, i + 1, iRight);
	}
}

void sort_quick(ElementType* arrData, int iArrLength) {
	int iLeft, iRight;
	iLeft = 0; iRight = iArrLength - 1;
	sort_quick_recursion(arrData, iLeft, iRight);
}

void heap_adjust(int* arrData, int i, int iArrLength) {
	// arrData为待调整的堆数组，i是待调整的数组元素的位置，iArrLength是数组的长度
	int iChild;
	for (; 2 * i + 1 < iArrLength; i = iChild) {
		iChild = 2 * i + 1;		// 字节点的位置 = 2 * 父节点位置 + 1
		if (iChild < iArrLength - 1 && arrData[iChild + 1] > arrData[iChild])
			iChild++;
		// 如果较大的子节点大于父节点，那么用该子节点替换父节点
		if (arrData[i] < arrData[iChild]) {
			swap(&arrData[i], &arrData[iChild]);
		}
		else
			break;
	}
}

void sort_selection(ElementType* arrData, int iArrLength)
{
	// 选择排序
	int i, j;			// 循环变量
	int iMinIndex;		// 最小值下标

	for (i = 0; i < iArrLength - 1; i++) {
		iMinIndex = i;
		for (j = i + 1; j < iArrLength; j++) {
			if (arrData[iMinIndex] > arrData[j]) {
				iMinIndex = j;
			}
		}
		swap(&arrData[i], &arrData[iMinIndex]);
	}
}

void sort_shell(ElementType* arrData, int iArrLength) {
	// 希尔排序，也称递减增量排序算法，是插入排序的一种高速而稳定的改进版本
	int i, j;			// 循环下标
	int iGap;			// 增量
	for (iGap = iArrLength / 2; iGap >= 1; iGap /= 2) {
		for (i = iGap; i < iArrLength; i++) {
			for (j = i - iGap; j >= 0 && arrData[j] > arrData[j + iGap]; j -= iGap) {
				swap(&arrData[j], &arrData[j + iGap]);
			}

		}
	}
}

void sort_merge_recursion(ElementType* arrData, int iLeft, int iRight) {
	// 归并（Merge）排序法是将两个（或两个以上）有序表合并成一个新的有序表，
	// 即把待排序序列分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。
	int iMid;
	if (iLeft < iRight) {
		iMid = (iLeft + iRight) / 2; /* 注意防止溢出 */
		sort_merge_recursion(arrData, iLeft, iMid);
		sort_merge_recursion(arrData, iMid + 1, iRight);
		merge(arrData, iLeft, iMid, iRight);
	}
}

void sort_merge(ElementType* arrData, int iArrLength) {
	int iLeft, iRight;
	iLeft = 0; iRight = iArrLength - 1;
	sort_merge_recursion(arrData, iLeft, iRight);
}

void sort_heap(int* arrData, int iArrLength)
{
	// 堆排序
	/*
	* 1.堆是完全二叉树
	* 2.大顶堆：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆。
	* 3.小顶堆：每个结点的值都大于或等于其左右孩子结点的值，称为小顶堆。
	* 如果i > 1，则双亲是结点[i/2]。也就是说下标i与2i和2i+1是双亲子女关系。
	* 当排序对象为数组时，下标从0开始，所以下标 i 与下标 2i+1和2i+2是双亲子女关系。
	*/

	/* 算法步骤：
	* 1.先将数组构建成一个大顶堆
	* 2.从完全二叉树的最下一层最右边的非终端节点开始构建
	*/
	int i;
	for (i = iArrLength / 2 - 1; i >= 0; i--)
		heap_adjust(arrData, i, iArrLength);
	for (i = iArrLength - 1; i > 0; i--) {
		swap(&arrData[i], &arrData[0]);
		heap_adjust(arrData, 0, i);
	}
}

void sort_bucket(ElementType* arrData, int iArrLength) {
	int i, j;
	ElementType BucketNum;
	ElementType* arrBucket;
	MostValue tMax;

	tMax = find_max(arrData, iArrLength);	// 找到数组中的最大值，方便确定桶的个数
	BucketNum = tMax.Value + 1;				// 由于索引值从0开始，因而桶的个数比最大值加1
	arrBucket = (ElementType*)malloc(sizeof(int) * (BucketNum));
	
	for (i = 0; i < BucketNum; i++)
		arrBucket[i] = 0;					// 初始化桶内所有数据均为0

	for (i = 0; i < iArrLength; i++)		// 将数组中的值放入到对应的桶内，如数字1就放入1号桶，数字10就放入10号桶
		arrBucket[arrData[i]]++;			// 考虑到可能有重复元素出现，因而桶内存放的是每个元素出现的次数

	j = 0;
	for (i = 0; i < BucketNum; i++) {	// 按从小到大的顺序将桶内元素依次输出
		while (arrBucket[i]--){
			arrData[j++] = i;
		}
	}
	free(arrBucket);
	arrBucket = NULL;
}

void sort_radix(int* arrData, int iArrLength) {
	/*	基数排序
		将整形10进制按每位拆分，然后从低位到高位依次比较各个位。每次比较完进行排序，直到整个数组有序
		主要分为两个过程：
		(1)分配，先从个位开始，根据位值(0 - 9)分别放到0 - 9号桶中（比如53, 个位为3，则放入3号桶中）
		(2)收集，再将放置在0 - 9号桶中的数据按顺序放到数组中
		重复(1)(2)过程，从个位到最高位，直到排好序为止（比如32位无符号整形最大数4294967296，最高位10位）
	*/
	int i, j, k;				// 循环索引
	int iPos;					// 位数索引
	int iTempNum;				// 当前位
	int iIndex;					// 桶内元素索引
	int iMaxDigit;				// 最大位数
	int iCounts[10];			// 用于记录每个桶中的元素个数
	int * arrRadix[10];

	for (i = 0; i < 10; i++) {	// 初始化，iCounts[i]存储桶内元素的个数，初值设为0
		arrRadix[i] = (int*)malloc(sizeof(int)*(iArrLength + 1));
		iCounts[i] = 0;
	}

	iMaxDigit = find_max_length(arrData, iArrLength);	// 确定数组中最大元素的位数
	
	for (iPos = 1; iPos <= iMaxDigit; iPos++) {
		for (i = 0; i < iArrLength; i++) {
			iTempNum = get_number(arrData[i], iPos);	// 获取iPos位，1为个位，2为十位，依次类推
			iIndex = iCounts[iTempNum]++;
			arrRadix[iTempNum][iIndex] = arrData[i];
		}

		j = 0;
		for (i = 0; i < 10; i++) {
			for (k = 0; k < iCounts[i]; k++) {
				arrData[j++] = arrRadix[i][k];
			}
			iCounts[i] = 0;
		}
	}

	// 指针数组的空间释放
	for (i = 0; i < 10; i++) {
		free(arrRadix[i]);
		arrRadix[i] = NULL;
	}
}

void merge(ElementType* arrData, int iLeft, int iMid, int iRight) {
	
	// 设r[i…n]由两个有序子表 r[i…m] 和 r[m + 1…n] 组成，两个子表长度分别为n - i + 1、n - m。
	// 1.j = m + 1；k = i；i = i; 置两个子表的起始下标及辅助数组的起始下标
	// 2.若i > m 或j > n，转⑷ //其中一个子表已合并完，比较选取结束
	// 3.选取r[i]和r[j]较小的存入辅助数组rf
	//	 如果r[i] < r[j]，rf[k] = r[i]； i++； k++； 转⑵
	//	 否则，rf[k] = r[j]； j++； k++； 转⑵
	// 4.将尚未处理完的子表中元素存入rf
	//	 如果i <= m，将r[i…m]存入rf[k…n] //前一子表非空
	//   如果j <= n, 将r[j…n] 存入rf[k…n] //后一子表非空
	// 5.合并结束

	int  i, j;
	ElementType* arrTemp = (ElementType*)malloc(sizeof(int) * (iRight - iLeft + 1));
	//申请空间，使其大小为两个
	int iLeftLow = iLeft;
	int iLeftHigh = iMid;
	int iRightLow = iMid + 1;
	int iRightHigh = iRight;

	// 比较两个指针所指向的元素
	for (i = 0; iLeftLow <= iLeftHigh && iRightLow <= iRightHigh; i++) {
		if (arrData[iLeftLow] <= arrData[iRightLow]) {
			arrTemp[i] = arrData[iLeftLow++];
		}
		else {
			arrTemp[i] = arrData[iRightLow++];
		}
	}

	//若第一个序列有剩余，直接复制出来粘到合并序列尾
	if (iLeftLow <= iLeftHigh) {
		for (j = iLeftLow; j <= iLeftHigh; j++)
			arrTemp[i++] = arrData[j];
	}

	//若第二个序列有剩余，直接复制出来粘到合并序列尾
	if (iRightLow <= iRightHigh) {
		for (j = iRightLow; j <= iRightHigh; j++)
			arrTemp[i++] = arrData[j];
	}

	for (i = 0; i < iRight - iLeft + 1; i++)
		arrData[iLeft + i] = arrTemp[i];

	free(arrTemp);
	arrTemp = NULL;
}

MostValue find_max(ElementType* arrData, int iArrLength) {
	int i;
	MostValue tMax;
	tMax.Value = arrData[0];
	tMax.iLocation = 0;

	for (i = 1; i < iArrLength; i++) {
		if (arrData[i] > tMax.Value) {
			tMax.Value = arrData[i];
			tMax.iLocation = i;
		}
	}
	return tMax;
}

MostValue find_min(ElementType* arrData, int iArrLength) {
	int i;
	MostValue tMin;
	tMin.Value = arrData[0];
	tMin.iLocation = 0;

	for (i = 1; i < iArrLength; i++) {
		if (arrData[i] < tMin.Value) {
			tMin.Value = arrData[i];
			tMin.iLocation = i;
		}
	}
	return tMin;
}

int find_max_length(int* arrData, int iNumber) {
	int iDigit = 0;
	MostValue tMax;
	tMax = find_max(arrData, iNumber);
	while (tMax.Value){
		tMax.Value /= 10;
		iDigit++;
	}
	return iDigit;
}

int get_number(int iNumber, int iPos) {
	int iTemp = 1;
	int i;
	for (i = 0; i < iPos - 1; i++) {
		iTemp *= 10;
	}
	iTemp = (iNumber / iTemp) % 10;
	return iTemp;
}

void sort_test(void) {

	ElementType iArrNumber = 10;
	int iMin = 0, iMax = 1000;

	int * arrData = (int*)malloc(sizeof(int) * iArrNumber);
	int i;

	genRand(arrData, iMin, iMax, iArrNumber);

	printf("排序前：");
	for (i = 0; i < iArrNumber; i++) {
		printf("%d ", arrData[i]);
	}

	printf("\n\n");

	sort_bucket(arrData, iArrNumber);

	printf("\n排序后：");
	for (i = 0; i < iArrNumber; i++) {
		printf("%d ", arrData[i]);
	}
	printf("\n");

	free(arrData);
	arrData = NULL;
}

#endif // !SORT_H
