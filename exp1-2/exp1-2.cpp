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

#if DEBUG
void test()
{
	Student s("0032", "ZGJ");
	cout << s << endl;
	StudentGread sg(s);
	//sg.insert(make_pair("电路与电子技术", 97)).insert(make_pair("概率论与数理统计", 95)).insert(make_pair("数学分析（二）", 100));
	//Student s1("0032", "ZGJ"), s2("0000", "ZGJ");
	//StudentGread sg1(s1), sg2(s2);
	//cout << sg.isSameStudent(s1) << " " << sg.isSameStudent(s2) << " " << (sg == sg1) << " " << (sg == sg2) << endl;
	//cout << sg.search("电路与电子技术") << endl;
	//sg.remove("电路与电子技术");
	//cout << sg.search("电路与电子技术") << endl;
	//cout << sg.search("概率论与数理统计") << endl;
	//sg.clear();
	//cout << sg.search("概率论与数理统计") << endl;
	
	sg.insert(make_pair("电路与电子技术", 97));
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
