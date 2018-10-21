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
	Student testS("0032", "ZGJ");
	cout << testS << endl << endl;
	StudentGread zgj(testS);
	zgj.insert(make_pair("电路与电子技术", 97)).insert(make_pair("大学物理", 99)).insert(make_pair("数学分析", 100));

	cout << zgj.search("电路与电子技术") << endl;
	cout << zgj.search("大学物理") << endl;
	cout << zgj.search("数学分析") << endl;

	zgj.remove("电路与电子技术");
	cout << zgj.search("电路与电子技术") << endl;
	cout << zgj.search("大学物理") << endl;
	cout << zgj.search("数学分析") << endl;

	zgj.remove("大学物理");
	cout << zgj.search("电路与电子技术") << endl;
	cout << zgj.search("大学物理") << endl;
	cout << zgj.search("数学分析") << endl;

	zgj.remove("数学分析");
	cout << zgj.search("电路与电子技术") << endl;
	cout << zgj.search("大学物理") << endl;
	cout << zgj.search("数学分析") << endl << endl;
	
	
	StudentGreadManager sgm;
	sgm.insert(zgj);
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl;
	sgm.addGread(testS, make_pair("电路与电子技术", 97));
	sgm.addGread(testS, make_pair("大学物理", 99));
	sgm.addGread(testS, make_pair("数学分析", 100));
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl;

	sgm.remove(testS, "电路与电子技术");
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl;

	sgm.remove(testS, "大学物理");
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl;

	sgm.remove(testS, "数学分析");
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl;

	sgm.addGread(testS, make_pair("电路与电子技术", 97));
	sgm.addGread(testS, make_pair("大学物理", 99));
	sgm.addGread(testS, make_pair("数学分析", 100));
	sgm.remove(testS);
	cout << sgm.search(testS, "电路与电子技术") << endl;
	cout << sgm.search(testS, "大学物理") << endl;
	cout << sgm.search(testS, "数学分析") << endl << endl;

	Student student2("0000", "Mr.Z");
	sgm.insert(student2);
	sgm.addGread(student2, make_pair("电路与电子技术", 197));
	sgm.addGread(student2, make_pair("大学物理", 199));
	sgm.addGread(student2, make_pair("数学分析", 1100));
	cout << sgm.search(student2, "电路与电子技术") << endl;
	cout << sgm.search(student2, "大学物理") << endl;
	cout << sgm.search(student2, "数学分析") << endl << endl;

	Student student3("9999", "GOD");
	LList<Gread> g3;
	g3.append(make_pair("电路与电子技术", 297)).append	(make_pair("大学物理", 299)).append(make_pair("数学分析", 2100));
	sgm.insert(student3, g3);
	cout << sgm.search(student3, "电路与电子技术") << endl;
	cout << sgm.search(student3, "大学物理") << endl;
	cout << sgm.search(student3, "数学分析") << endl << endl;

	cout << sgm.size() << endl;
	sgm.clear();
	cout << sgm.size() << endl;
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

