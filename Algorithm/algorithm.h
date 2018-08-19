#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char* TransIDCard15to18(char* strIDCardNO);							// 将15位身份证号转换为18位
void  FindPeakValue(int* arrArray, int iLength);					// 寻找峰值

#endif // !ALGORITHM_H
