/*
*
*	数据结构第一次实验课
*	基于双向链表和二维字典的学生成绩管理类
*	10.18 张冠杰
*
*/

#pragma once

#include "Dictionary.h"
#include "../exp1-1/LList.h"
#include <string>
#include <cstring>

using std::string;

struct Student	//学生基本信息
{
	string ID;
	string name;
};

struct Gread	//单科成绩信息
{
	string courseTitle;
	double score;
};

struct StudentGread	//学生信息
{
	Student student;	//基本信息
	LList<Gread> gread;	//成绩单
};

class StudentGreadManager : Dictionary2D<Student, Gread, StudentGread>
{
private:
	LList<StudentGread>* _greadList;

	void insert(const Student& k, const StudentGread& e) {}	//隐藏不需要的接口

	void insert(const Gread& k, const StudentGread& e) {}	//隐藏不需要的接口

public:
	StudentGreadManager()	//构造函数
	{
		_greadList = new LList<StudentGread>;
	}

	~StudentGreadManager()	//析构函数
	{
		delete _greadList;
	}

	void clear()	//清空学生信息
	{
		_greadList->clear();
	}

	void insert(const StudentGread& e)	//插入学生信息
	{
		_greadList->append(e);
	}

	void insert(const Student& e)	//按照学生基本信息插入
	{
		StudentGread sg;
		sg.student = e;
		_greadList->append(sg);
	}

};