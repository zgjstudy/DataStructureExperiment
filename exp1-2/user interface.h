/*
*
*	数据结构第一次实验课
*	用户界面
*	10.20 张冠杰
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

	enum State	//状态编码
	{
		START = 0,
		INPUT_BY_USER,
		LOAD_FORM_FILE,
		OPERATION_INTERFACE,
		SAVED,

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
			<< "2.从文件读取" << endl
			<< "3.选这个" << endl << endl;
		string temp;
		cin >> temp;
		int mode = atoi(temp.c_str());
		while (mode != 1 && mode != 2 && mode != 3)	//处理错误输入
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
		case 3:
			currentState = SAVED;
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
		_manager->clear();					//清空信息
		cout << "请输入要读取的文件名： ";	//从文件读取
		string filename;
		cin >> filename;
		cout << "读取中。。。";
		_reader = new GreadReader(filename);
		//_reader->readAll(_manager);			//该功能尚未完善
		//cout << "读取完毕。" << endl << endl;
		cout << "然而该功能尚未完善 bhys" << endl << endl;
		currentState = START;
	}

	//打表存储信息
	void loadFromProgram()
	{
		_manager->clear();					//清空信息
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
		sg0.insert(make_pair("电路与电子技术", 97)).insert(make_pair("概率论与数理统计", 95)).insert(make_pair("数学分析2", 100)).insert(make_pair("大学物理1", 99)).insert(make_pair("数学分析1", 99)).insert(make_pair("C++程序开发实训", 95)).insert(make_pair("高级语言程序设计", 89));
		sg1.insert(make_pair("电路与电子技术", 70)).insert(make_pair("概率论与数理统计", 72)).insert(make_pair("数学分析2", 61)).insert(make_pair("大学物理1", 74)).insert(make_pair("数学分析1", 60)).insert(make_pair("C++程序开发实训", 75)).insert(make_pair("高级语言程序设计", 73));
		sg2.insert(make_pair("电路与电子技术", 70)).insert(make_pair("概率论与数理统计", 72)).insert(make_pair("数学分析2", 56)).insert(make_pair("大学物理1", 81)).insert(make_pair("数学分析1", 67)).insert(make_pair("C++程序开发实训", 90)).insert(make_pair("高级语言程序设计", 84));
		sg3.insert(make_pair("电路与电子技术", 70)).insert(make_pair("概率论与数理统计", 71)).insert(make_pair("数学分析2", 86)).insert(make_pair("大学物理1", 67)).insert(make_pair("数学分析1", 85)).insert(make_pair("C++程序开发实训", 78)).insert(make_pair("高级语言程序设计", 81));
		sg4.insert(make_pair("电路与电子技术", 91)).insert(make_pair("概率论与数理统计", 77)).insert(make_pair("数学分析2", 93)).insert(make_pair("大学物理1", 92)).insert(make_pair("数学分析1", 99)).insert(make_pair("C++程序开发实训", 95)).insert(make_pair("高级语言程序设计", 94));
		sg5.insert(make_pair("电路与电子技术", 94)).insert(make_pair("概率论与数理统计", 98)).insert(make_pair("数学分析2", 94)).insert(make_pair("大学物理1", 99)).insert(make_pair("数学分析1", 98)).insert(make_pair("C++程序开发实训", 90)).insert(make_pair("高级语言程序设计", 80));
		sg6.insert(make_pair("电路与电子技术", 92)).insert(make_pair("概率论与数理统计", 65)).insert(make_pair("数学分析2", 83)).insert(make_pair("大学物理1", 93)).insert(make_pair("数学分析1", 86)).insert(make_pair("C++程序开发实训", 93)).insert(make_pair("高级语言程序设计", 89));
		sg7.insert(make_pair("电路与电子技术", 81)).insert(make_pair("概率论与数理统计", 80)).insert(make_pair("数学分析2", 73)).insert(make_pair("大学物理1", 87)).insert(make_pair("数学分析1", 93)).insert(make_pair("C++程序开发实训", 95)).insert(make_pair("高级语言程序设计", 81));
		sg8.insert(make_pair("电路与电子技术", 86)).insert(make_pair("概率论与数理统计", 71)).insert(make_pair("数学分析2", 86)).insert(make_pair("大学物理1", 67)).insert(make_pair("数学分析1", 85)).insert(make_pair("C++程序开发实训", 78)).insert(make_pair("高级语言程序设计", 81));
		sg9.insert(make_pair("电路与电子技术", 82)).insert(make_pair("概率论与数理统计", 85)).insert(make_pair("数学分析2", 93)).insert(make_pair("大学物理1", 91)).insert(make_pair("数学分析1", 93)).insert(make_pair("C++程序开发实训", 95)).insert(make_pair("高级语言程序设计", 80));
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
			<< "7.输出所有同学的信息" << endl
			<< "h.返回开始菜单" << endl
			<< "q.退出程序" << endl << endl;
		cin >> mode;

		switch (mode[0])
		{
		case '1':
		{
			Student stu;
			cout << "请输入学生ID、姓名和课程名（示例：0032 ZGJ）：";
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
		{
			cout << "请输入学生ID和姓名：";
			string id, name;
			cin >> id >> name;
			_manager->insert(Student(id, name));
			cout << "插入成功！" << endl << endl;
		}
			break;
		case '4':
		{
			cout << "请输入学生ID和姓名和课程名和分数：";
			string id, name, course;
			double score;
			cin >> id >> name >> course >> score;
			if (_manager->addGread(Student(id, name), make_pair(course, score)))
				cout << "插入成功！" << endl << endl;
			else
				cout << "学生不存在！" << endl << endl;
		}
			break;
		case '5':
		{
			cout << "请输入学生ID和姓名和课程名：";
			string id, name, course;
			cin >> id >> name >> course;
			if (_manager->remove(Student(id, name), course) != -1)
				cout << "删除成功！" << endl << endl;
			else 
				cout << "删除失败！" << endl << endl;
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
			cout << endl << "真的要退出？(y for yes): ";
			cin >> mode;
			if (mode[0] == 'y')
				exit(0);
		}
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
			case UserInterface::SAVED:
				loadFromProgram();
				break;
			default:
				break;
			}
		}
	}
};