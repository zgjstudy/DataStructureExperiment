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
	Student testS("0032", "ZGJ");
	cout << testS << endl << endl;
	StudentGread zgj(testS);
	zgj.insert(make_pair("��·����Ӽ���", 97)).insert(make_pair("��ѧ����", 99)).insert(make_pair("��ѧ����", 100));

	cout << zgj.search("��·����Ӽ���") << endl;
	cout << zgj.search("��ѧ����") << endl;
	cout << zgj.search("��ѧ����") << endl;

	zgj.remove("��·����Ӽ���");
	cout << zgj.search("��·����Ӽ���") << endl;
	cout << zgj.search("��ѧ����") << endl;
	cout << zgj.search("��ѧ����") << endl;

	zgj.remove("��ѧ����");
	cout << zgj.search("��·����Ӽ���") << endl;
	cout << zgj.search("��ѧ����") << endl;
	cout << zgj.search("��ѧ����") << endl;

	zgj.remove("��ѧ����");
	cout << zgj.search("��·����Ӽ���") << endl;
	cout << zgj.search("��ѧ����") << endl;
	cout << zgj.search("��ѧ����") << endl << endl;
	
	
	StudentGreadManager sgm;
	sgm.insert(zgj);
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	sgm.addGread(testS, make_pair("��·����Ӽ���", 97));
	sgm.addGread(testS, make_pair("��ѧ����", 99));
	sgm.addGread(testS, make_pair("��ѧ����", 100));
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;

	sgm.remove(testS, "��·����Ӽ���");
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;

	sgm.remove(testS, "��ѧ����");
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;

	sgm.remove(testS, "��ѧ����");
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;

	sgm.addGread(testS, make_pair("��·����Ӽ���", 97));
	sgm.addGread(testS, make_pair("��ѧ����", 99));
	sgm.addGread(testS, make_pair("��ѧ����", 100));
	sgm.remove(testS);
	cout << sgm.search(testS, "��·����Ӽ���") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl;
	cout << sgm.search(testS, "��ѧ����") << endl << endl;

	Student student2("0000", "Mr.Z");
	sgm.insert(student2);
	sgm.addGread(student2, make_pair("��·����Ӽ���", 197));
	sgm.addGread(student2, make_pair("��ѧ����", 199));
	sgm.addGread(student2, make_pair("��ѧ����", 1100));
	cout << sgm.search(student2, "��·����Ӽ���") << endl;
	cout << sgm.search(student2, "��ѧ����") << endl;
	cout << sgm.search(student2, "��ѧ����") << endl << endl;

	Student student3("9999", "GOD");
	LList<Gread> g3;
	g3.append(make_pair("��·����Ӽ���", 297)).append	(make_pair("��ѧ����", 299)).append(make_pair("��ѧ����", 2100));
	sgm.insert(student3, g3);
	cout << sgm.search(student3, "��·����Ӽ���") << endl;
	cout << sgm.search(student3, "��ѧ����") << endl;
	cout << sgm.search(student3, "��ѧ����") << endl << endl;

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

