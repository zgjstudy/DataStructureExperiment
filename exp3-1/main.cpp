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

#define NUMOFSORT 7 //numbre of sort algorithms

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
void init();

//加载随机数,可设置最大最小值
void loadRandNum(int* a, int num, int min = 0, int max = 10000000);

//加载随机数,不可设置最大最小值,但提升了加载效率
void loadRandNumEx(int* a, int num);

//复制数组
void copyArray(int* a, int* b, int n);

//测试辅助函数
void testhelp(int* num, int n);

int main()
{
	cout << "Begin." << endl;

	int *num10 = new int[15];
	int *num100 = new int[105];
	int *num1k = new int[1005];
	int *num10k = new int[10005];
	int *num100k = new int[100005];
	int *num1m = new int[1000005];
	int *num10m = new int[10000005];

	do	//读取随机数
	{
		cout << "Loading rand numbers...";
		loadRandNum(num10, 10);
		thread t1([num100] {
			loadRandNumEx(num100, 100);
		});
		t1.detach();
		thread t2([num1k] {
			loadRandNumEx(num1k, 1000);
		});
		t2.detach();
		thread t3([num10k] {
			loadRandNumEx(num10k, 10000);
		});
		t3.join();
		thread t4([num100k] {
			loadRandNumEx(num100k, 100000);
		});
		t4.detach();
		thread t5([num1m] {
			loadRandNumEx(num1m, 1000000);
		});
		t5.detach();
		thread t6([num10m] {
			loadRandNumEx(num10m, 10000000);
		});
		t6.join();
		cout << "Done!" << endl << endl;
	} while (0);

	init();

	//测试排序函数
	testhelp(num10, 10);
	testhelp(num100, 100);
	testhelp(num1k, 1000);
	testhelp(num10k, 10000);
	testhelp(num100k, 100000);
	testhelp(num1m, 1000000);
	testhelp(num10m, 10000000);
	
	delete[]num1k;
	delete[]num100;
	delete[]num10k;
	delete[]num100k;
	delete[]num1m;
	delete[]num10m;

	system("pause");
	return 0;
}

void testhelp(int* num, int n)
{
	int* tnum = new int[n];
	int* ttnum = new int[n];
	Timestamp timer; //计时器
	cout << setw(9) << n;

	//根据设置的顺序遍历排序算法
	for (int i = 0; i < NUMOFSORT; ++i)
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT:	//以下同理
			copyArray(num, tnum, n);
			timer.update();
			mergeSort(tnum, ttnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			copyArray(num, tnum, n);
			timer.update();
			quickSortWithoutOptimize(tnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case QUICK_SORT:
			copyArray(num, tnum, n);
			timer.update();
			quickSort(tnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case SORT_STL:
			copyArray(num, tnum, n);
			timer.update();
			sort(tnum, tnum + n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case HEAP_SORT:
			copyArray(num, tnum, n);
			timer.update();
			heapSort(tnum, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case RADIX_SORT:
		{
			int* cnt = new int[n];
			copyArray(num, tnum, n);
			timer.update();
			radixSort(tnum, ttnum, n, 10, 10, cnt);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			delete[] cnt;
		}
		break;
		case SHELL_SORT:
			copyArray(num, tnum, n);
			timer.update();
			shellSort(tnum, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case INSERTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			insertionSort(tnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case BUBBLE_SORT:
			copyArray(num, tnum, n);
			timer.update();
			bubbleSort(tnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		case SHELECTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			selectionSort(tnum, 0, n);
			cout << setw(15) << timer.getElapsedTimeInMilliSec();
			break;
		default:
			break;
		}
	cout << endl;
	delete[] tnum;
	delete[] ttnum;
}

void init()
{
	cout << "Sort algorithm time record(Millisecond):" << endl;
	cout << setw(9) << "Data size";
	for (int i = 0; i < NUMOFSORT; ++i)
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT:
			cout << setw(15) << "mergeSort";
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			cout << setw(15) << "quickStNotOpt";
			break;
		case QUICK_SORT:
			cout << setw(15) << "quickSort";
			break;
		case SORT_STL:
			cout << setw(15) << "sort(STL)";
			break;
		case HEAP_SORT:
			cout << setw(15) << "heapSort";
			break;
		case RADIX_SORT:
			cout << setw(15) << "radixSort";
			break;
		case SHELL_SORT:
			cout << setw(15) << "shellSort";
			break;
		case INSERTION_SORT:
			cout << setw(15) << "insertionSort";
			break;
		case BUBBLE_SORT:
			cout << setw(15) << "bubbleSort";
			break;
		case SHELECTION_SORT:
			cout << setw(15) << "selectionSort";
			break;
		default:
			break;
		}
	cout << endl;
}

void loadRandNum(int* a, int num, int min, int max)
{
	ifstream ifs("randnum.txt");
	if (!ifs.is_open())
	{
		cerr << "Can't find File!";
		exit(-1);
	}
	double temp;
	for (int i = 0; i < num; ++i)
	{
		ifs >> temp;
		a[i] = int(temp * INT_MAX) % (max - min) + min;
	}
}

void loadRandNumEx(int* a, int num)
{
	ifstream ifs("randnum.txt");
	if (!ifs.is_open())
	{
		cerr << "Can't find File!";
		exit(-1);
	}
	double temp;
	for (int i = 0; i < num; ++i)
	{
		ifs >> temp;
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