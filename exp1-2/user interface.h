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
public:
	StudentGreadManager* _manager;
	GreadReader* _reader;
	HWND consoleHwnd;
	int scrWidth;
	int scrHeight;
	int width = 1024;
	int height = 720;

	enum State	//状态编码
	{
		START = 0,
		INPUT_BY_USER,
		LOAD_FORM_FILE,
		OPERATION_INTERFACE,

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
		cout << endl << "该功能尚未完善。" << endl << endl;
		currentState = START;
	}

	//从文件读取界面
	void loadDataFromFile()
	{
		cout << "请输入要读取的文件名： ";
		string filename;
		cin >> filename;
		cout << "读取中。。。";
		_reader = new GreadReader(filename);
		_reader->readAll(_manager);
		cout << "读取完毕。" << endl << endl;
		currentState = OPERATION_INTERFACE;
	}

	//用户操作界面
	void operationInterface()
	{
		string mode;
		cout << endl << "您要干嘛？" << endl
			<< "1.按照学生信息查找成绩" << endl
			<< "2.按照学生信息和科目查找成绩" << endl
			<< "3.添加学生信息" << endl
			<< "4.添加学生课程成绩" << endl
			<< "5.删除学生课程成绩" << endl
			<< "6.输出所有同学的所有成绩" << endl
			<< "h.返回开始菜单" << endl
			<< "q.退出程序" << endl << endl;
		cin >> mode;

		switch (mode[0])
		{
		case '1':
			break;
		case '2':
		{
			Student stu;
			string coursename;
			cout << "请输入学生ID、姓名和课程名（示例：0032 ZGJ 电路与电子技术）：";
			cin >> stu.ID >> stu.name >> coursename;

			double score = _manager->search(stu, coursename);
			if (score != -1)
				cout << "该科目成绩为：" << score << endl;
			else
				cout << "未查询到该科目成绩" << endl;
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
			cout << endl << "真的要退出？(y for yes): ";
			cin >> mode;
			if (mode[0] == 'y')
				exit(0);
			break;
		default:
			cout << "输入有误！" << endl;
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

	//运行用户界面
	void run()
	{
		while (true)
		{
			//锁定窗口位置
			::MoveWindow(consoleHwnd, (scrWidth - width) / 2, (scrHeight - height) / 2,
				width, height, true);

			//有限状态机
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