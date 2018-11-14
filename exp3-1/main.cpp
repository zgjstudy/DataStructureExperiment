//防止栈溢出，把栈扩100倍
#pragma comment(linker,"/STACK:102400000,102400000")

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <thread>
#include <algorithm>
#include <iomanip>
#include "SortAlgorithm.h"
#include "TIME.h"
using namespace std;

#define NUMOFSORT 10 //number of sort algorithms

enum SORT_TYPE	//Define the sorting algorithm execution order
{
	MERGE_SORT = 0,
	QUICK_SORT_WITHOUT_OPTIMIZE,
	QUICK_SORT,
	RADIX_SORT,
	HEAP_SORT,
	SHELL_SORT,
	SORT_STL,
	INSERTION_SORT,
	BUBBLE_SORT,
	SHELECTION_SORT,
};

//初始化排序函数
void init(ofstream& fs);

//加载随机数,可设置最大最小值
void loadRandNum(int* a, int num, int min, int max, ifstream& fs);

//加载随机数,不可设置最大最小值,但提升了加载效率
void loadRandNumEx(int* a, int num, ifstream& fs);

//复制数组
void copyArray(int* a, int* b, int n);

//测试辅助函数
void testhelp(int* num, int n, ofstream& fs);

int main()
{
	cout << "Begin." << endl;
	ifstream ifs("randnum.txt");
	ofstream ofs("output.csv");
	if (!ifs.is_open())
	{
		cerr << "Can't find File!";
		exit(-1);
	}

	int *num10m = new int[10000005];


	cout << "Loading rand numbers...";
	
	loadRandNumEx(num10m, 10000000, ifs);
	ifs.close();
	cout << "Done!" << endl << endl;

	init(ofs);

	//测试排序函数
	for (int i = 10, c = 0; i < 1000000; i *= (++c & 1 ? 5 : 2))
	{
		cout << "Sorting " << i << " numbers...";
		testhelp(num10m, i, ofs);
		cout << "Done." << endl;
	}
	ofs.clear();
	delete[]num10m;

	system("pause");
	return 0;
}

void testhelp(int* num, int n, ofstream& fs)
{
	int* tnum = new int[n];
	int* ttnum = new int[n];
	Timestamp timer; //计时器
	fs << n << ",";

	//根据设置的顺序遍历排序算法
	for (int i = 0; i < NUMOFSORT; ++i)
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT:	//以下同理
			copyArray(num, tnum, n);
			timer.update();
			mergeSort(tnum, ttnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			copyArray(num, tnum, n);
			timer.update();
			quickSortWithoutOptimize(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case QUICK_SORT:
			copyArray(num, tnum, n);
			timer.update();
			quickSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case SORT_STL:
			copyArray(num, tnum, n);
			timer.update();
			sort(tnum, tnum + n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case HEAP_SORT:
			copyArray(num, tnum, n);
			timer.update();
			heapSort(tnum, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case RADIX_SORT:
		{
			int* cnt = new int[n];
			copyArray(num, tnum, n);
			timer.update();
			radixSort(tnum, ttnum, n, 10, 10, cnt);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			delete[] cnt;
		}
		break;
		case SHELL_SORT:
			copyArray(num, tnum, n);
			timer.update();
			shellSort(tnum, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case INSERTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			insertionSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case BUBBLE_SORT:
			copyArray(num, tnum, n);
			timer.update();
			bubbleSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		case SHELECTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			selectionSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec() << ",";
			break;
		default:
			break;
		}
	fs << n << endl;
	delete[] tnum;
	delete[] ttnum;
}

void init(ofstream& fs)
{
	fs << "Sort algorithm time record(Millisecond):" << endl;
	fs << setw(9) << "Data size";
	for (int i = 0; i < NUMOFSORT; ++i)
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT:
			fs << "mergeSort" << ",";
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			fs << "quickStNotOpt" << ",";
			break;
		case QUICK_SORT:
			fs << "quickSort" << ",";
			break;
		case SORT_STL:
			fs << "sort(STL)" << ",";
			break;
		case HEAP_SORT:
			fs << "heapSort" << ",";
			break;
		case RADIX_SORT:
			fs << "radixSort" << ",";
			break;
		case SHELL_SORT:
			fs << "shellSort" << ",";
			break;
		case INSERTION_SORT:
			fs << "insertionSort" << ",";
			break;
		case BUBBLE_SORT:
			fs << "bubbleSort" << ",";
			break;
		case SHELECTION_SORT:
			fs << "selectionSort" << ",";
			break;
		default:
			break;
		}
	fs << endl;
}

void loadRandNum(int* a, int num, int min, int max, ifstream& fs)
{
	double temp;
	for (int i = 0; i < num; ++i)
	{
		fs >> temp;
		a[i] = int(temp * INT_MAX) % (max - min) + min;
	}
}

void loadRandNumEx(int* a, int num, ifstream& fs)
{
	double temp;
	for (int i = 0; i < num; ++i)
	{
		fs >> temp;
		a[i] = temp * 100000000;
	}
}

void copyArray(int* a, int* b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[i];
	}
}