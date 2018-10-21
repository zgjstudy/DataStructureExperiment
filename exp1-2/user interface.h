/*
*
*	���ݽṹ��һ��ʵ���
*	�û�����
*	10.20 �Źڽ�
*
*/

#pragma once

#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include "GreadReader.h"
using std::cout;
using std::cin;
using std::endl;
using std::make_pair;

class UserInterface
{
public:
	StudentGreadManager* _manager;
	GreadReader* _reader;
	HWND consoleHwnd;
	int scrWidth;
	int scrHeight;
	int width = 1024;
	int height = 720;

	enum State	//״̬����
	{
		START = 0,
		INPUT_BY_USER,
		LOAD_FORM_FILE,
		OPERATION_INTERFACE,
		SAVED,

	} currentState;

	//һ�����ڻ�ȡ����̨����ĸ�������
	HWND GetConsoleHwnd(void)
	{
#define BUFSIZE 1024			// ����̨����Ļ�������С
		HWND hwndFound;				// ���ظ������ߵĴ��ھ��
		TCHAR NewWindowTitle[BUFSIZE]; // Contains fabricated 
		TCHAR OldWindowTitle[BUFSIZE]; // Contains original 

		GetConsoleTitle(OldWindowTitle, BUFSIZE);

		wsprintf(NewWindowTitle, "%d/%d",
			GetTickCount(),
			GetCurrentProcessId());

		SetConsoleTitle(NewWindowTitle);

		Sleep(40);

		hwndFound = FindWindow(NULL, NewWindowTitle);

		SetConsoleTitle(OldWindowTitle);

		return(hwndFound);
	}

	void init()
	{
		currentState = START;								//��ʼ������״̬
		SetConsoleTitle("ѧ���ɼ�������� - ZGJ");			//���ı���
		consoleHwnd = GetConsoleHwnd();						//��þ��
		scrWidth = GetSystemMetrics(SM_CXSCREEN);			//��ȡ��Ļ���
		scrHeight = GetSystemMetrics(SM_CYSCREEN);			//��ȡ��Ļ�߶�
	}

	//��ʼ����
	void start()
	{
		cout << "��ӭʹ�ñ��ɼ�����ϵͳ��" << endl
			<< "��ѡ��������ģʽ��" << endl
			<< "1.�Ӽ�������" << endl
			<< "2.���ļ���ȡ" << endl
			<< "3.ѡ���" << endl << endl;
		string temp;
		cin >> temp;
		int mode = atoi(temp.c_str());
		while (mode != 1 && mode != 2 && mode != 3)	//�����������
		{
			cout << "����������������룺 ";
			cin >> temp;
			mode = atoi(temp.c_str());
		}
		switch (mode)	//�ı�state
		{
		case 1:
			currentState = INPUT_BY_USER;
			break;
		case 2:
			currentState = LOAD_FORM_FILE;
			break;
		case 3:
			currentState = SAVED;
			break;
		default:
			break;
		}
	}

	//�û�������Ϣ����
	void userInputData()
	{
		cout << endl << "�ù�����δ���ơ�" << endl << endl;
		currentState = START;
	}

	//���ļ���ȡ����
	void loadDataFromFile()
	{
		_manager->clear();					//�����Ϣ
		cout << "������Ҫ��ȡ���ļ����� ";	//���ļ���ȡ
		string filename;
		cin >> filename;
		cout << "��ȡ�С�����";
		_reader = new GreadReader(filename);
		//_reader->readAll(_manager);			//�ù�����δ����
		//cout << "��ȡ��ϡ�" << endl << endl;
		cout << "Ȼ���ù�����δ���� bhys" << endl << endl;
		currentState = START;
	}

	//���洢��Ϣ
	void loadFromProgram()
	{
		_manager->clear();					//�����Ϣ
		Student student0("0032", "ZGJ"); StudentGread sg0(student0);
		Student student1("0036", "ZYZ"); StudentGread sg1(student1);
		Student student2("0026", "YZF"); StudentGread sg2(student2);
		Student student3("0028", "YJJ"); StudentGread sg3(student3);
		Student student4("0005", "FWH"); StudentGread sg4(student4);
		Student student5("0027", "YWB"); StudentGread sg5(student5);
		Student student6("0054", "CRL"); StudentGread sg6(student6);
		Student student7("0055", "HSX"); StudentGread sg7(student7);
		Student student8("0049", "XRH"); StudentGread sg8(student8);
		Student student9("0053", "CL");  StudentGread sg9(student9);
		sg0.insert(make_pair("��·����Ӽ���", 97)).insert(make_pair("������������ͳ��", 95)).insert(make_pair("��ѧ����2", 100)).insert(make_pair("��ѧ����1", 99)).insert(make_pair("��ѧ����1", 99)).insert(make_pair("C++���򿪷�ʵѵ", 95)).insert(make_pair("�߼����Գ������", 89));
		sg1.insert(make_pair("��·����Ӽ���", 70)).insert(make_pair("������������ͳ��", 72)).insert(make_pair("��ѧ����2", 61)).insert(make_pair("��ѧ����1", 74)).insert(make_pair("��ѧ����1", 60)).insert(make_pair("C++���򿪷�ʵѵ", 75)).insert(make_pair("�߼����Գ������", 73));
		sg2.insert(make_pair("��·����Ӽ���", 70)).insert(make_pair("������������ͳ��", 72)).insert(make_pair("��ѧ����2", 56)).insert(make_pair("��ѧ����1", 81)).insert(make_pair("��ѧ����1", 67)).insert(make_pair("C++���򿪷�ʵѵ", 90)).insert(make_pair("�߼����Գ������", 84));
		sg3.insert(make_pair("��·����Ӽ���", 70)).insert(make_pair("������������ͳ��", 71)).insert(make_pair("��ѧ����2", 86)).insert(make_pair("��ѧ����1", 67)).insert(make_pair("��ѧ����1", 85)).insert(make_pair("C++���򿪷�ʵѵ", 78)).insert(make_pair("�߼����Գ������", 81));
		sg4.insert(make_pair("��·����Ӽ���", 91)).insert(make_pair("������������ͳ��", 77)).insert(make_pair("��ѧ����2", 93)).insert(make_pair("��ѧ����1", 92)).insert(make_pair("��ѧ����1", 99)).insert(make_pair("C++���򿪷�ʵѵ", 95)).insert(make_pair("�߼����Գ������", 94));
		sg5.insert(make_pair("��·����Ӽ���", 94)).insert(make_pair("������������ͳ��", 98)).insert(make_pair("��ѧ����2", 94)).insert(make_pair("��ѧ����1", 99)).insert(make_pair("��ѧ����1", 98)).insert(make_pair("C++���򿪷�ʵѵ", 90)).insert(make_pair("�߼����Գ������", 80));
		sg6.insert(make_pair("��·����Ӽ���", 92)).insert(make_pair("������������ͳ��", 65)).insert(make_pair("��ѧ����2", 83)).insert(make_pair("��ѧ����1", 93)).insert(make_pair("��ѧ����1", 86)).insert(make_pair("C++���򿪷�ʵѵ", 93)).insert(make_pair("�߼����Գ������", 89));
		sg7.insert(make_pair("��·����Ӽ���", 81)).insert(make_pair("������������ͳ��", 80)).insert(make_pair("��ѧ����2", 73)).insert(make_pair("��ѧ����1", 87)).insert(make_pair("��ѧ����1", 93)).insert(make_pair("C++���򿪷�ʵѵ", 95)).insert(make_pair("�߼����Գ������", 81));
		sg8.insert(make_pair("��·����Ӽ���", 86)).insert(make_pair("������������ͳ��", 71)).insert(make_pair("��ѧ����2", 86)).insert(make_pair("��ѧ����1", 67)).insert(make_pair("��ѧ����1", 85)).insert(make_pair("C++���򿪷�ʵѵ", 78)).insert(make_pair("�߼����Գ������", 81));
		sg9.insert(make_pair("��·����Ӽ���", 82)).insert(make_pair("������������ͳ��", 85)).insert(make_pair("��ѧ����2", 93)).insert(make_pair("��ѧ����1", 91)).insert(make_pair("��ѧ����1", 93)).insert(make_pair("C++���򿪷�ʵѵ", 95)).insert(make_pair("�߼����Գ������", 80));
		_manager->insert(sg0);
		_manager->insert(sg1);
		_manager->insert(sg2);
		_manager->insert(sg3);
		_manager->insert(sg4);
		_manager->insert(sg5);
		_manager->insert(sg6);
		_manager->insert(sg7);
		_manager->insert(sg8);
		_manager->insert(sg9);
		
		currentState = OPERATION_INTERFACE;
	}																					

	//�û���������
	void operationInterface()
	{
		string mode;
		cout << endl << "��Ҫ���" << endl
			<< "1.����ѧ����Ϣ���ҳɼ�" << endl
			<< "2.����ѧ����Ϣ�Ϳ�Ŀ���ҳɼ�" << endl
			<< "3.���ѧ����Ϣ" << endl
			<< "4.���ѧ���γ̳ɼ�" << endl
			<< "5.ɾ��ѧ���γ̳ɼ�" << endl
			<< "6.�������ͬѧ�����гɼ�" << endl
			<< "7.�������ͬѧ����Ϣ" << endl
			<< "h.���ؿ�ʼ�˵�" << endl
			<< "q.�˳�����" << endl << endl;
		cin >> mode;

		switch (mode[0])
		{
		case '1':
		{
			Student stu;
			cout << "������ѧ��ID�������Ϳγ�����ʾ����0032 ZGJ����";
			cin >> stu.ID >> stu.name;

			LList<Gread> greadlist = _manager->search(stu);
			int l = greadlist.length();
			Gread* temp = new Gread[l];
			greadlist.moveToStart();
			for (int i = 0; i < l; ++i)
			{
				temp[i] = greadlist.getValue();
				greadlist.pred();
			}
			sort(temp, temp + l, descending);
			for (int i = 0; i < l; ++i)
			{
				cout << temp[i].first << " " << temp[i].second << endl;
			}
			delete[] temp;
		}
			break;
		case '2':
		{
			Student stu;
			string coursename;
			cout << "������ѧ��ID�������Ϳγ�����ʾ����0032 ZGJ ��·����Ӽ�������";
			cin >> stu.ID >> stu.name >> coursename;

			double score = _manager->search(stu, coursename);
			if (score != -1)
				cout << "�ÿ�Ŀ�ɼ�Ϊ��" << score << endl;
			else
				cout << "δ��ѯ���ÿ�Ŀ�ɼ�" << endl;
		}
			break;
		case '3':
		{
			cout << "������ѧ��ID��������";
			string id, name;
			cin >> id >> name;
			_manager->insert(Student(id, name));
			cout << "����ɹ���" << endl << endl;
		}
			break;
		case '4':
		{
			cout << "������ѧ��ID�������Ϳγ����ͷ�����";
			string id, name, course;
			double score;
			cin >> id >> name >> course >> score;
			if (_manager->addGread(Student(id, name), make_pair(course, score)))
				cout << "����ɹ���" << endl << endl;
			else
				cout << "ѧ�������ڣ�" << endl << endl;
		}
			break;
		case '5':
		{
			cout << "������ѧ��ID�������Ϳγ�����";
			string id, name, course;
			cin >> id >> name >> course;
			if (_manager->remove(Student(id, name), course) != -1)
				cout << "ɾ���ɹ���" << endl << endl;
			else 
				cout << "ɾ��ʧ�ܣ�" << endl << endl;
		}
			break;
		case '6':
			break;
		case '7':
			_manager->printAllStudentInfo();
			break;
		case 'h':
			currentState = START;
			break;
		case 'q':
		{
			cout << endl << "���Ҫ�˳���(y for yes): ";
			cin >> mode;
			if (mode[0] == 'y')
				exit(0);
		}
			break;
		default:
			cout << "��������" << endl;
			break;
		}

	}

public:
	UserInterface()
	{
		_manager = new StudentGreadManager;
		init();
	}

	~UserInterface()
	{
		delete _manager;
	}

	//�����û�����
	void run()
	{
		while (true)
		{
			//��������λ��
			::MoveWindow(consoleHwnd, (scrWidth - width) / 2, (scrHeight - height) / 2,
				width, height, true);

			//����״̬��
			switch (currentState)
			{
			case UserInterface::START:
				start();
				break;
			case UserInterface::INPUT_BY_USER:
				userInputData();
				break;
			case UserInterface::LOAD_FORM_FILE:
				loadDataFromFile();
				break;
			case UserInterface::OPERATION_INTERFACE:
				operationInterface();
				break;
			case UserInterface::SAVED:
				loadFromProgram();
				break;
			default:
				break;
			}
		}
	}
};