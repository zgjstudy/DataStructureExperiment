/*
*
*	���ݽṹ��һ��ʵ���
*	main
*	10.20 �Źڽ�
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
