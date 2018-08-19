#ifndef TIMER_H
#define TIMER_H
/************************************************************************/
/*                             计时模块                                 */
/************************************************************************/

#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

// 函数声明
void timer_time(void);											// 使用time()计时，输出单位为s
void timer_clock(void);											// 使用clock()计时，输出单位为ms
void timer_timeGetTime(void);									// 使用timer_timeGetTime()计时，输出单位为ms
void timer_GetTickCount(void);									// 使用GetTickCount()计时，输出单位为ms
void timer_QueryPerformanceCounter(void);						// 使用timer_QueryPerformanceCounter()计时，输出单位为ms
void genRand(int * arrNumber, int iMin, int iMax, int iSize);	// 随机数生成器，生成位于区间[iMin, iMax]内的iSize个随机数
void genCatalan(int* arrNumber, int iSize);						// 卡特兰数生成器
void genFibonacci(int* arrFibonacci, int iArrLength);			// 斐波那契数列生成器

void timer_time(void) {
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	
	Sleep(1000);
	
	timeEnd = time(NULL);
	printf("用时：%lld s\n", timeEnd - timeBegin);
}

void timer_clock(void) {
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	
	Sleep(800);
	
	clockEnd = clock();
	printf("用时：%d ms\n", clockEnd - clockBegin);
}

void timer_timeGetTime(void) {
	DWORD  dwBegin, dwEnd;
	dwBegin = timeGetTime();
	
	Sleep(800);
	
	dwEnd = timeGetTime();
	printf("用时：%d ms\n", dwEnd - dwBegin);
}

void timer_GetTickCount(void) {
	DWORD  dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	
	Sleep(800);
	
	dwGTCEnd = GetTickCount();
	printf("用时：%d ms\n", dwGTCEnd - dwGTCBegin);
}

void timer_QueryPerformanceCounter(void) {
	LARGE_INTEGER li, freq;
	QueryPerformanceCounter(&li);
	long long f_start = li.QuadPart;
	QueryPerformanceFrequency(&freq);   //取得当前线(进)程的时钟主频
	
	Sleep(800);
	
	QueryPerformanceCounter(&li);
	long long f_end = li.QuadPart;
	long long llTime = (f_end - f_start) * 1000000 / freq.QuadPart;
	printf("%lld ms\n", llTime / 1000);
}

#endif // !TIMER_H
