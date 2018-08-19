#include "algorithm.h"


char* TransIDCard15to18(char* strIDCardInput) {
	/*
	* 将15位身份证号转换为18位标准身份证号
	* 首先将15位身份证号补全为17位，然后再补全最后一位
	* 1. 将身份证号加入出生年变为17位
	* 2. 将17位数分别乘以不同的系数， 从第1位到第17位的系数分别为: 7-9-10-5-8-4-2-1-6-3-7-9-10-5-8-4-2
	* 3. 将这17位数字和系数相乘的结果相加
	* 4. 将第3步结果除以11得到余数, 余数只可能为0-10，分别对应的数字为: 1-0-X-9-8-7-6-5-4-3-2
	*/

	char* strIDCardOutput;		// 转换后的身份证号
	return strIDCardInput;
}

void FindPeakValue(int * arrArray, int iLength){
	/*
	 * 寻找峰值
	 * 给定一个整数数组(size为n), 其具有以下特点:
	 * 1. 相邻位置的数字是不同的
	 * 2. A[0] < A[1] 并且 A[n-2] > A[n-1]
	 * 假定P是峰值的位置, 则满足A[P] > A[P-1] 且 A[P] > A[P+1]
	 * input : 一个整数数组
	 * output: 输出所有数组中的峰值的位置
	 * 样例:
	 * input : [1, 2, 1, 3, 4, 5, 7, 6]
	 * output: 1, 6
	*/

	for (int i = 1; i < iLength - 1; i++) {
		if (arrArray[i] > arrArray[i - 1] && arrArray[i] > arrArray[i + 1]) {
			cout << i << " ";
		}
	}
}
