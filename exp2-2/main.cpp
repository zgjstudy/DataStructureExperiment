#include <iostream>
#include <cstdlib>
#include "HuffmanTree.h"

using namespace std;

struct Comp
{
	static bool prior(int a, int b)
	{
		return a > b;
	}

	static void swap(int& a, int& b)
	{
		a ^= b ^= a ^= b;
	}
};

int main()
{
	heap<int, Comp> test;

	test.insert(10).insert(20).insert(30).insert(0).insert(2);
	int n = 5;
	while (n--)
		cout << test.remove() << endl;

	system("pause");

	return 0;
}