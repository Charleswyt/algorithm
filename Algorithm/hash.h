#ifndef HASH_H
#define HASH_H

void create_hash_table(int * arrHash);							// 创建Hash表
int search_hash(int * arrData, int iArrLength, int iNum);		// 哈希查找
int  hash_function(int iNum, int iHashLength, int iHashType);	// 散列函数
int  hash_function_address(int iNum, int iHashLength,
	int iWeight, int iBias);									// 直接定址法Hash
int  hash_function_mod(int iNum, int iHashLength);				// 除留余数法Hash

int  generate_prime(int iArrLength);							// 根据原始序列的长度产生相对应的质数大小


int search_hash(int * arrData, int iArrLength, int iNum) {

}

int  hash_function(int iNum, int iHashLength, int iHashType) {
	// 哈希函数规则：
	// 通过某种转换关系，使关键字适度的分散到指定大小的的顺序结构中，越分散，则以后查找的时间复杂度越小，空间复杂度越高。
	// 算法流程：
	// 1）用给定的哈希函数构造哈希表；
	// 2）根据选择的冲突处理方法解决地址冲突；
	//常见的解决冲突的方法：拉链法和线性探测法。

	int iHash;
	int iWeight, iBias;
	if (iHashType == 0) {
		// 直接定址法，关键字分配不连续，存储空间浪费
		// 简单、均匀，不会产生冲突。但是需要事先知道关键字的分布情况，适合查找表较小并且连续的情况
		iHash = iWeight * iNum + iBias;
	}

	else if (iHashType == 1) {
		// 除留余数法是用关键字K除以散列表长度m所得余数作为散列地址的方法
		// 计算简单，适用范围广
		iHash = iNum % iHashLength;
	}

	else if (iHashType == 2) {

	}

	return iHash;

}

#endif // !HASH_H
