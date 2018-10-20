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
private:
	StudentGreadManager* _manager;
	GreadReader* _reader;
	HWND consoleHwnd;
	int scrWidth;
	int scrHeight;
	int width = 1024;
	int height = 720;

	enum State
	{
		START = 0,
		INPUT_BY_USER,
		LOAD_FORM_FILE,

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

	}

	//���ļ���ȡ����
	void loadDataFromFile()
	{

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
			default:
				break;
			}
		}
	}
};