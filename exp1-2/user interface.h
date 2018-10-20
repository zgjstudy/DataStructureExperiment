/*
*
*	数据结构第一次实验课
*	用户界面
*	10.20 张冠杰
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

	//一个用于获取控制台句柄的辅助函数
	HWND GetConsoleHwnd(void)
	{
#define BUFSIZE 1024			// 控制台标题的缓冲区大小
		HWND hwndFound;				// 返回给调用者的窗口句柄
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
		currentState = START;								//初始化程序状态
		SetConsoleTitle("学生成绩管理程序 - ZGJ");			//更改标题
		consoleHwnd = GetConsoleHwnd();						//获得句柄
		scrWidth = GetSystemMetrics(SM_CXSCREEN);			//获取屏幕宽度
		scrHeight = GetSystemMetrics(SM_CYSCREEN);			//获取屏幕高度
	}

	//开始界面
	void start()
	{
		cout << "欢迎使用本成绩管理系统！" << endl
			<< "请选择导入数据模式：" << endl
			<< "1.从键盘输入" << endl
			<< "2.从文件读取" << endl << endl;
		string temp;
		cin >> temp;
		int mode = atoi(temp.c_str());
		while (mode != 1 && mode != 2)	//处理错误输入
		{
			cout << "输入错误，请重新输入： ";
			cin >> temp;
			mode = atoi(temp.c_str());
		}
		switch (mode)	//改变state
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

	//用户输入信息界面
	void userInputData()
	{

	}

	//从文件读取界面
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

	//运行用户界面
	void run()
	{
		while (true)
		{
			//锁定窗口位置
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