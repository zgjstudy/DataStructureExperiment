/*
*
*	数据结构第一次实验课
*	main
*	10.20 张冠杰
*
*/
#define DEBUG 1
#include "user interface.h"

using namespace std;

int main()
{
	Student s("0032", "ZGJ");
	cout << s;

#if DEBUG
	system("pause");
#endif

	return 0;
}
