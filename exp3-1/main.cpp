//��ֹջ�������ջ��100��
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

#define NUMOFSORT 11 //number of sort algorithms

enum SORT_TYPE	//Define the sorting algorithm execution order
{	
	MERGE_SORT = 0,
	MERGE_SORT_WITHOUT_OPTIMIZE,
	RADIX_SORT,
	SORT_STL,
	QUICK_SORT,
	QUICK_SORT_WITHOUT_OPTIMIZE,
	HEAP_SORT,
	SHELL_SORT,
	INSERTION_SORT,
	BUBBLE_SORT,
	SHELECTION_SORT,
};

//��ʼ��������
void init(ofstream& fs);

//���������,�����������Сֵ
void loadRandNum(int* a, int num, int min, int max, ifstream& fs);

//���������,�������������Сֵ,�������˼���Ч��
void loadRandNumEx(int* a, int num, ifstream& fs);

//��������
void copyArray(int* a, int* b, int n);

//���Ը�������
void testhelp(int* num, int n, ofstream& fs, int numOfSort = NUMOFSORT);

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

	int *num20m = new int[20000005];


	cout << "Loading rand numbers...";
	
	loadRandNumEx(num20m, 20000000, ifs);
	ifs.close();
	cout << "Done!" << endl << endl;

	init(ofs);

	//����������
	cout << "Sorting " << 10 << " numbers for " << NUMOFSORT << " sort algorithms...";
	testhelp(num20m, 10, ofs);
	cout << "Done." << endl;
	for (int i = 20, j = 10, c = 0; i < 10000; j *= (++c % 9 == 0 ? 10 : 1), i += j)
	{
		cout << "Sorting " << i << " numbers for " << NUMOFSORT << " sort algorithms...";
		testhelp(num20m, i, ofs);
		cout << "Done." << endl;
	}
	for (int i = 100000, j = i, c = 0; i <= 10000000; j *= (c++ % 10 == 9 ? 10 : 1), i += j)
	{
		cout << "Sorting " << i << " numbers for " << 8 << " sort algorithms...";
		testhelp(num20m, i, ofs, 8);
		cout << "Done." << endl;
	}
	ofs.clear();
	delete[]num20m;

	system("pause");
	return 0;
}

void testhelp(int* num, int n, ofstream& fs, int numOfSort)
{
	int* tnum = new int[n];
	int* ttnum = new int[n];
	Timestamp timer; //��ʱ��
	fs << n << ",";

	//�������õ�˳����������㷨
	for (int i = 0; i < numOfSort; ++i)
	{
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT_WITHOUT_OPTIMIZE:
			copyArray(num, tnum, n);
			timer.update();
			mergeSortWithoutOptimize(tnum, ttnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case MERGE_SORT:	//����ͬ��
			copyArray(num, tnum, n);
			timer.update();
			mergeSort(tnum, ttnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			copyArray(num, tnum, n);
			timer.update();
			quickSortWithoutOptimize(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case QUICK_SORT:
			copyArray(num, tnum, n);
			timer.update();
			quickSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case SORT_STL:
			copyArray(num, tnum, n);
			timer.update();
			sort(tnum, tnum + n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case HEAP_SORT:
			copyArray(num, tnum, n);
			timer.update();
			heapSort(tnum, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case RADIX_SORT:
		{
			int* cnt = new int[n];
			copyArray(num, tnum, n);
			timer.update();
			radixSort(tnum, ttnum, n, 10, 10, cnt);
			fs << timer.getElapsedTimeInMilliSec();
			delete[] cnt;
		}
		break;
		case SHELL_SORT:
			copyArray(num, tnum, n);
			timer.update();
			shellSort(tnum, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case INSERTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			insertionSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case BUBBLE_SORT:
			copyArray(num, tnum, n);
			timer.update();
			bubbleSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		case SHELECTION_SORT:
			copyArray(num, tnum, n);
			timer.update();
			selectionSort(tnum, 0, n);
			fs << timer.getElapsedTimeInMilliSec();
			break;
		default:
			break;
		}
		if (i < numOfSort)
			fs << ",";
	}
	fs << endl;
	delete[] tnum;
	delete[] ttnum;
}

void init(ofstream& fs)
{
	fs << "Sort algorithm time record(Millisecond):" << endl;
	fs << setw(9) << "Data size" << ",";
	for (int i = 0; i < NUMOFSORT; ++i)
	{
		switch ((SORT_TYPE)i)
		{
		case MERGE_SORT_WITHOUT_OPTIMIZE:
			fs << "mergeSortNotOpt";
			break;
		case MERGE_SORT:
			fs << "mergeSort";
			break;
		case QUICK_SORT_WITHOUT_OPTIMIZE:
			fs << "quickStNotOpt";
			break;
		case QUICK_SORT:
			fs << "quickSort";
			break;
		case SORT_STL:
			fs << "sort(STL)";
			break;
		case HEAP_SORT:
			fs << "heapSort";
			break;
		case RADIX_SORT:
			fs << "radixSort";
			break;
		case SHELL_SORT:
			fs << "shellSort";
			break;
		case INSERTION_SORT:
			fs << "insertionSort";
			break;
		case BUBBLE_SORT:
			fs << "bubbleSort";
			break;
		case SHELECTION_SORT:
			fs << "selectionSort";
			break;
		default:
			break;
		}
		if (i < NUMOFSORT)
			fs << ",";
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