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

#if DEBUG
void test()
{
	Student s("0032", "ZGJ");
	cout << s << endl;
	StudentGread sg(s);
	//sg.insert(make_pair("��·����Ӽ���", 97)).insert(make_pair("������������ͳ��", 95)).insert(make_pair("��ѧ����������", 100));
	//Student s1("0032", "ZGJ"), s2("0000", "ZGJ");
	//StudentGread sg1(s1), sg2(s2);
	//cout << sg.isSameStudent(s1) << " " << sg.isSameStudent(s2) << " " << (sg == sg1) << " " << (sg == sg2) << endl;
	//cout << sg.search("��·����Ӽ���") << endl;
	//sg.remove("��·����Ӽ���");
	//cout << sg.search("��·����Ӽ���") << endl;
	//cout << sg.search("������������ͳ��") << endl;
	//sg.clear();
	//cout << sg.search("������������ͳ��") << endl;
	
	sg.insert(make_pair("��·����Ӽ���", 97));
	sg.clear();
}
#endif

int main()
{

	

#if DEBUG
	test();
	system("pause");
#endif

	return 0;
}
