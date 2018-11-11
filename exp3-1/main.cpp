#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <thread>
#include "SortAlgorithm.h"
#include "TIME.h"
using namespace std;

#define EOHOD 'H' //experience mode or homework mode or debug mode

void loadRandNum(int* a, int num, int min = 0, int max = 10000000)
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

template <typename T>
void copyArray(T* a, T* b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		b[i] = a[i];
	}
}

int main()
{
	int *num1k = new int[1005];		//原始数组
	int *tnum1k = new int[1005];	//待排序数组
	int *ttnum1k = new int[1005];	//备用空间


#if EOHOD == 'E'
	int *num100 = new int[105];
	int *tnum100 = new int[105];
	int *ttnum100 = new int[105];
	int *num10k = new int[10005];
	int *tnum10k = new int[10005];
	int *ttnum10k = new int[10005];
	int *num100k = new int[100005];
	int *tnum100k = new int[100005];
	int *ttnum100k = new int[100005];
	int *num1m = new int[1000005];
	int *tnum1m = new int[1000005];
	int *ttnum1m = new int[1000005];
	do
	{
		thread t1([num100, tnum100] {
			loadRandNum(num100, 100, 0, 1000);
			copyArray(num100, tnum100, 100);
		});
		t1.detach();
		thread t2([num1k, tnum1k] {
			loadRandNum(num1k, 1000, 0, 10000);
			copyArray(num1k, tnum1k, 1000);
		});
		t2.detach();
		thread t3([num10k, tnum10k] {
			loadRandNum(num10k, 10000, 0, 100000);
			copyArray(num10k, tnum10k, 10000);
		});
		t3.detach();
		thread t4([num100k, tnum100k] {
			loadRandNum(num100k, 100000, 0, 1000000);
			copyArray(num100k, tnum100k, 100000);
		});
		t4.detach();
		thread t5([num1m, tnum1m] {
			loadRandNum(num1m, 1000000, 0, 10000000);
			copyArray(num1m, tnum1m, 1000000);
		});
		t5.join();
	} while (0);
#endif

#if EOHOD == 'H'
#define NUMOFNUM 100
	loadRandNum(num1k, NUMOFNUM, 0, 30000);	//加载1000个0到30000的随机数
	copyArray(num1k, tnum1k, NUMOFNUM);		//拷贝到待排序数组
	cout << "unsorted list:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出未排序数组
	{
		cout << num1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;

	//插排
	insertionSort(tnum1k, 0, NUMOFNUM);
	cout << "After insertionSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//冒泡
	bubbleSort(tnum1k, 0, NUMOFNUM);
	cout << "After bubbleSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//选排
	selectionSort(tnum1k, 0, NUMOFNUM);
	cout << "After selectionSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//希尔
	shellSort(tnum1k, NUMOFNUM);
	cout << "After shellSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//快排
	quickSort(tnum1k, 0, NUMOFNUM);
	cout << "After quickSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//归并
	mergeSort(tnum1k, ttnum1k, 0, NUMOFNUM);
	cout << "After mergeSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//堆排
	heapSort(tnum1k, NUMOFNUM);
	cout << "After heapSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

	//基数
	int *cnt = new int[NUMOFNUM];
	radixSort(tnum1k, ttnum1k, NUMOFNUM, 10, 4, cnt);
	cout << "After radixSort:" << endl;
	for (int i = 0; i < NUMOFNUM; ++i)	//输出已排序数组
	{
		cout << tnum1k[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cout << endl;
	copyArray(num1k, tnum1k, NUMOFNUM);

#endif

	
#if EOHOD == 'D'
	//
#endif

	system("pause");
	return 0;
}