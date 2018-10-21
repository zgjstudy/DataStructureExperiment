/*
*
*	���ݽṹ��һ��ʵ���
*	�û�����
*	10.20 �Źڽ�
*
*/

#pragma once

#include <cstdlib>
#include <windows.h>
#include "GreadReader.h"
using std::cout;
using std::cin;
using std::endl;

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
			<< "2.���ļ���ȡ" << endl << endl;
		string temp;
		cin >> temp;
		int mode = atoi(temp.c_str());
		while (mode != 1 && mode != 2)	//�����������
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
		cout << "������Ҫ��ȡ���ļ����� ";
		string filename;
		cin >> filename;
		cout << "��ȡ�С�����";
		_reader = new GreadReader(filename);
		_reader->readAll(_manager);
		cout << "��ȡ��ϡ�" << endl << endl;
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
			<< "h.���ؿ�ʼ�˵�" << endl
			<< "q.�˳�����" << endl << endl;
		cin >> mode;

		switch (mode[0])
		{
		case '1':
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
			break;
		case '4':
			break;
		case '5':
			break;
		case 'h':
			currentState = START;
			break;
		case 'q':
			cout << endl << "���Ҫ�˳���(y for yes): ";
			cin >> mode;
			if (mode[0] == 'y')
				exit(0);
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
			default:
				break;
			}
		}
	}
};