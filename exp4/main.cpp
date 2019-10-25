// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for checking syntax of a hash table-based dictionary

#include "book.h"
#include "hashdict.h"
#include <queue>
#include <time.h>
#include "readHelp.h"
int main(int argc, char** argv)
{
	const int M = 2500;
	hashdict<int, Int*> dict(M, -1);
	Int* val;
	queue<double> costTime_insert;
	queue<double> costTime_delete;

	clock_t start, finish;
	double totaltime;

	for (int j = 1; j < M; j++)
	{
		cout << j << endl;

		start = clock();
		//关于插入
		for (int i = 0; i < j; i++)
		{
			dict.insert(i, new Int(i));
		}
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		costTime_insert.push(totaltime);

		start = clock();
		//关于删除
		for (int i = 0; i < j; i++)
		{
			 dict.remove(i) ;
		}
		finish = clock();
		totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
		costTime_delete.push(totaltime);
	}

	func(costTime_insert, "insert.csv");
	func(costTime_delete, "delete.csv");

	system("pause");
	return 0;
}
