#ifndef SEARCH_H
#define SEARCH_H

#define ARRSIZE 18
#define TRUE  1
#define FALSE 0

// 变量定义
typedef int ElementType;

typedef struct MyStruct
{
	int iNum;				// 索引表中的关键字
	int iStartIndex;		// 索引表起始索引值
	int iSubTableLength;	// 索引表长度
}SubTable;

/************************************************************************/
/*                              查找函数                                */
/************************************************************************/

/*查找算法分类：
 * 1）静态查找和动态查找；
 * 注：静态或者动态都是针对查找表而言的。动态表指查找表中有删除和插入操作的表。

 * 2）无序查找和有序查找
 * 无序查找：被查找数列有序无序均可
 * 有序查找：被查找数列必须为有序数列
*/

// 函数声明
int search_sequence(ElementType* arrData, int iArrLength, ElementType Num);		// 顺序查找
int search_binary(ElementType* arrData, int iArrLength, ElementType Num);		// 二分查找
int search_insert(ElementType* arrData, int iArrLength, ElementType Num);		// 插值查找
int search_fibonacci(ElementType* arrData, int iArrLength, ElementType Num);	// 斐波那契查找
int search_block(ElementType* arrData, int iArrLength, ElementType Num);		// 分块查找

int  get_fibonacci_length(int iArrLength);										// 确定斐波纳挈数列的长度

int  create_subtable(ElementType* arrData, int iArrLength,
	SubTable* pTable, int iTableNum);											// 创建索引表
void show_table_info(SubTable * pTable, int iTableNum);							// 显示索引表信息

void search_test(void);															// 测试函数

// 函数定义
int search_sequence(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// 顺序查找适合于存储结构为顺序存储或链接存储的线性表
	// 基本思想：顺序查找也称为线形查找，属于无序查找算法。
	// 从数据结构线形表的一端开始，顺序扫描，依次将扫描到的结点关键字与给定值k相比较，
	// 若相等则表示查找成功；若扫描结束仍没有找到关键字等于k的结点，表示查找失败。

	int i;
	int iLocate = -1;
	for (i = 0; i < iArrLength; i++) {
		if (arrData[i] == Num) {
			iLocate = i;
			break;
		}
	}
	return iLocate;
}

int search_binary(ElementType* arrData, int iArrLength, ElementType Num) {
	// 需要查找对象是有序的，每一次都找1/2的部分，查找次数大大的减少了。时间复杂度是O(logN)
	// 对于静态查找表，一次排序后不再变化，折半查找能得到不错的效率。
	// 但对于需要频繁执行插入或删除操作的数据集来说，维护有序的排序会带来不小的工作量，那就不建议使用
	
	int iLeft, iRight, iMid;
	int iLocate = -1;
	iLeft = 0;
	iRight = iArrLength - 1;
	
	if (Num > arrData[iRight] || Num < arrData[iLeft])
		iLeft = iRight + 1;

	while(iLeft <= iRight){
		iMid = (iLeft + iRight) / 2;
		if (Num < arrData[iMid]) {
			iRight = iMid - 1;
		}
		else if (Num > arrData[iMid]) {
			iLeft = iMid + 1;
		}
		else if(Num == arrData[iMid]){
			iLocate = iMid;
			break;
		}
	}
	return iLocate;
}

int search_insert(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// 基本思想：基于二分查找算法，将查找点的选择改进为自适应选择，可以提高查找效率。当然，差值查找也属于有序查找。
	// 对于表长较大，而关键字分布又比较均匀的查找表来说，插值查找算法的平均性能比折半查找要好的多。
	// 反之，数组中如果分布非常不均匀，那么插值查找未必是很合适的选择。
	
	int iLeft, iRight, iMid;
	int iLocate = -1;
	iLeft = 0;
	iRight = iArrLength - 1;

	if (Num > arrData[iRight] || Num < arrData[iLeft])
		iLeft = iRight + 1;

	while (iLeft <= iRight) {
		iMid = iLeft + (Num - arrData[iLeft]) / (arrData[iRight] - arrData[iLeft]) * (iRight - iLeft);
		if (Num < arrData[iMid]) {
			iRight = iMid - 1;
		}
		else if (Num > arrData[iMid]) {
			iLeft = iMid + 1;
		}
		else if (Num == arrData[iMid]) {
			iLocate = iMid;
			break;
		}
	}
	return iLocate;
}

int search_fibonacci(ElementType* arrData, int iArrLength, ElementType Num) {
	
	// 也是二分查找的一种提升算法，通过运用黄金比例的概念在数列中选择查找点进行查找，提高查找效率。
	// 同样地，斐波那契查找也属于一种有序查找算法。
	// 斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。
	
	// 要求开始表中记录的个数为某个斐波那契数小1，即iArrLength = Fibonacci(k) - 1;
	// 开始将k值与第F(k - 1)位置的记录进行比较(即mid = low + Fibonacci(k - 1) - 1), 比较结果也分为三种
	// （1）相等，mid位置的元素即为所求
	// （2）大于，low = mid + 1, k -= 2;
	// 说明：low = mid + 1说明待查找的元素在[mid + 1, high]范围内，
	// k -= 2 说明范围[mid + 1, high]内的元素个数为n - (F(k - 1)) = Fk - 1 - F(k - 1) = Fk - F(k - 1) - 1 = F(k - 2) - 1个，所以可以递归的应用斐波那契查找。
	// （3）小于，high = mid - 1, k -= 1。
	// 说明：low = mid + 1说明待查找的元素在[low, mid - 1]范围内，
	// k -= 1 说明范围[low, mid - 1]内的元素个数为F(k - 1) - 1个，所以可以递归的应用斐波那契查找。
	
	int  iLeft, iMid, iRight;					// 序列左值、中值、右值
	int  iLocate = -1;							// 待查找元素索引
	int  i,j;									// 循环下标
	int* arrFibonacci;							// 生成的斐波那契数列
	ElementType* arrTempNum;					// 填充后的临时序列
	int iFibonacciArrLength, iTempArrLength;	// 菲薄那切数列长度、临时序列长度
	
	iLeft = 0; iRight = iArrLength - 1;
	
	if (Num > arrData[iRight] || Num < arrData[iLeft])
		return iLocate;

	iFibonacciArrLength = get_fibonacci_length(iArrLength);			// 获取对应的斐波那契数列长度
	arrFibonacci = (int*)malloc(sizeof(int) * iFibonacciArrLength);	// 申请空间
	genFibonacci(arrFibonacci, iFibonacciArrLength);				// 构造斐波那契数列
	iTempArrLength = arrFibonacci[iFibonacciArrLength - 1] - 1;		// 临时数列的长度为当前斐波纳挈数列的最后一个数 - 1

	// 构造临时序列
	arrTempNum = (int*)malloc(sizeof(int)* iTempArrLength);
	for (i = 0; i < iArrLength; i++) {
		arrTempNum[i] = arrData[i];
	}
	for (i = iArrLength; i < iTempArrLength; i++) {
		arrTempNum[i] = arrData[iRight];
	}

	j = iFibonacciArrLength - 1;
	while (iLeft <= iRight) {
		iMid = iLeft + arrFibonacci[j - 1] - 1;
		if (Num > arrTempNum[iMid]) {
			iLeft = iMid + 1;
			j = j - 2;
		}
		else if (Num < arrTempNum[iMid]) {
			iRight = iMid - 1;
			j = j - 1;
		}
		else if (iMid <= iRight) {
			iLocate = iMid;
			break;
		}
		else{
			iLocate = iRight;
			break;
		}
	}
	
	free(arrFibonacci);
	arrFibonacci = NULL;

	free(arrTempNum);
	arrTempNum = NULL;

	return iLocate;
}

int search_block(ElementType* arrData, int iArrLength, ElementType iNum) {
	
	// 分块查找，在每一块中记录的关键字不一定有序，但是块与块之间必须有序。
	// 假设这种排序是按关键字值递增排序的，抽取各块中的最大关键字及该块的起始位置构成索引表，
	// 按块的顺序存放在一个数组中，显然这个数组是有序的，一般按升序排列
	// 从本质上说，分块查找对存储序列是有要求的

	int iFlag;							// 索引表创建标识
	int iTableNum;						// 索引表个数
	int iLocate = -1;					// 待查找元素索引
	SubTable* pTable;					// 索引表
	int iLeft, iRight, iMid;	//
//	int iSubLeft, iSubRight, iSubMid;	// 

	iTableNum = 3;
	pTable = (SubTable*)malloc(sizeof(SubTable) * iTableNum);
	iFlag = create_subtable(arrData, iArrLength, pTable, iTableNum);

	if (iFlag == -1) {
		printf("索引表创建失败");
		return iLocate;
	}
	else {
		show_table_info(pTable, iTableNum);
		iLeft = 0; iRight = iTableNum - 1;
		while (iLeft <= iRight) {
			iMid = (iLeft + iRight) / 2;
			if (iNum <= pTable[iMid].iNum) {
				iRight = iMid - 1;
			}
			else{
				iLeft = iMid + 1;
			}
			printf("iLeft = %d, iMid = %d, iRight = %d\n", iLeft, iMid, iRight);
		}
		
	}

	free(pTable);
	pTable = NULL;

	return 0;
}

int get_fibonacci_length(int iArrLength) {
	int iNumber1 = 1;
	int iNumber2 = 1;
	int iNumber3;
	int iIndex;
	for (iIndex = 3; iIndex < iArrLength; iIndex++) {
		iNumber3 = iNumber1 + iNumber2;
		iNumber1 = iNumber2;
		iNumber2 = iNumber3;
		if (iNumber3 - 1 >= iArrLength)
			break;
	}
	return iIndex;
}

int create_subtable(ElementType * arrData, int iArrLength, SubTable * pTable, int iTableNum) {
	
	int* arrSubTable;			// 子表
	int  iSubTableLength;		// 子表长度
	MostValue tMax;				// 子表中的最大元素及其索引值
	int  i;						// 循环下标

	// 采用固定分组模式
	if (iArrLength % iTableNum != 0 || iTableNum > iArrLength) {
		return FALSE;			// 索引表创建失败
	}

	iSubTableLength = iArrLength / iTableNum;
	arrSubTable = (int*)malloc(sizeof(int) * iSubTableLength);
	for (i = 0; i < iTableNum; i++) {
		arr_copy(arrData + (i * iSubTableLength), arrSubTable, iSubTableLength);
		tMax = find_max(arrSubTable, iSubTableLength);
		pTable[i].iStartIndex = i * iSubTableLength;
		pTable[i].iSubTableLength = iSubTableLength;
		pTable[i].iNum = tMax.Value;
	}

	free(arrSubTable);
	arrSubTable = NULL;

	return TRUE;
}

void search_test(void) {
	//ElementType arrData[ARRSIZE] = { 22, 12, 13, 8, 9, 20, 33, 42, 44, 38, 24, 46, 60, 58, 74, 47, 86, 53 };
	ElementType arrData[ARRSIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
	ElementType Num = 12;
	int iLocate;
	int i;

	//iLocate = search_fibonacci(arrData, ARRSIZE, iNum);
	//iLocate = search_insert(arrData, ARRSIZE, iNum);
	iLocate = search_binary(arrData, ARRSIZE, Num);

	printf("序列arrData中的元素分别为：");
	for (i = 0; i < ARRSIZE; i++) {
		printf("%d ", arrData[i]);
	}
	printf("\n");

	if (iLocate != -1) {
		printf("序列arrData中存在元素%d，下标为：%d\n", Num, iLocate);
	}
	else{
		printf("序列arrData中不存在元素%d\n", Num);
	}
}

void show_table_info(SubTable * pTable, int iTableNum) {
	int i;
	printf("当前序列创建的索引表为：\n");
	for (i = 0; i < iTableNum; i++) {
		printf("{ %d %d %d }\n", pTable[i].iNum, pTable[i].iStartIndex, pTable[i].iSubTableLength);
	}
}

#endif // !SEARCH_H
