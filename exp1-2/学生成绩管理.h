/*
*
*	数据结构第一次实验课
*	基于双向链表和字典的学生成绩管理类
*	10.18 张冠杰
*
*/

#pragma once

#include "Dictionary.h"
#include "../exp1-1/LList.h"
#include <string>
#include <cstring>
#include <iostream>

using std::string;

//学生基本信息
struct Student
{
	string ID;
	string name;

	Student() {}
	Student(string id, string n)
		:ID(id), name(n) {}

	friend std::ostream& operator<< (std::ostream& os, Student& s)
	{
		os << s.ID << " " << s.name << " ";
		return os;
	}

	bool operator== (const Student& r) const
	{
		return ID == r.ID && name == r.name;
	}
};

//单科成绩信息
typedef std::pair<string, double> Gread;

//一个学生和他的成绩单
struct StudentGread
{
	Student _student;
	LList<Gread> _greadList;

	//默认构造函数
	StudentGread() {}

	//构造函数
	StudentGread(const Student& s)
	{
		_student = s;
	}

	StudentGread(const Student& s, LList<Gread>& g)
	{
		_student = s;
		for (g.moveToStart(); g.currPos() <= g.length(); g.pred())
		{
			_greadList.append(g.getValue());
		}
	}

	StudentGread(const StudentGread& sg)
	{
		_student = sg._student;
		_greadList = sg._greadList;
	}

	~StudentGread() {}

	//在成绩单中按学科名顺序检索，成功则返回成绩，失败返回-1
	double search(string s)
	{
		if (_greadList.isempty())
			return -1;
		for (_greadList.moveToStart(); _greadList.currPos() <= _greadList.length(); _greadList.pred())
		{
			if (_greadList.getValue().first == s)
				return _greadList.getValue().second;
		}
		return -1;
	}

	//添加成绩信息
	StudentGread& insert(const Gread& g)
	{
		_greadList.append(g);
		return *this;
	}

	//移除成绩信息
	void clear()
	{
		_greadList.clear();
	}

	//移除单科成绩
	double remove(const string s)
	{
		for (_greadList.moveToStart(); _greadList.currPos() <= _greadList.length(); _greadList.pred())
		{
			if (_greadList.getValue().first == s)
			{
				double score = _greadList.getValue().second;
				_greadList.remove();
				return score;
			}
		}
		return -1;
	}

	//判断是否为同一个人
	bool isSameStudent(const Student& s) const
	{
		return s == _student;
	}

	//使用LList必须要声明==
	bool operator== (StudentGread& sg)
	{
		return isSameStudent(sg._student);
	}
};

class StudentGreadManager : Dictionary<Student, LList<Gread> >
{
public:
	LList<StudentGread> _data;

public:
	StudentGreadManager() {}
	~StudentGreadManager() {}

	//清空学生信息
	void clear()
	{
		_data.clear();
	}

	//添加学生信息
	void insert(const StudentGread& sg)
	{
		_data.append(sg);
	}

	//添加学生信息
	void insert(const Student& student, LList<Gread>& l)
	{
		StudentGread sg(student, l);
		insert(sg);
	}

	//添加学生信息
	void insert(const Student& s)
	{
		StudentGread sg(s);
		insert(sg);
	}

	//添加学生成绩
	void addGread(const Student& student, const Gread& g)
	{
		for (_data.moveToStart(); _data.currPos() <= _data.length(); _data.pred())
		{
			if (_data.getValue().isSameStudent(student))
			{
				_data.getValue_().insert(g);
			}
		}
	}

	//移除学生全部成绩
	LList<Gread> remove(const Student& student)
	{
		for (_data.moveToStart(); _data.currPos() <= _data.length(); _data.pred())
		{
			if (_data.getValue().isSameStudent(student))
			{
				LList<Gread> temp = _data.getValue_()._greadList;
				_data.getValue_().clear();
				return temp;
			}
		}
		return NULL;
	}

	//移除学生单科成绩
	double remove(const Student& student, const string s)
	{
		for (_data.moveToStart(); _data.currPos() <= _data.length(); _data.pred())
		{
			if (_data.getValue().isSameStudent(student))
			{
				return _data.getValue_().remove(s);
			}
		}
		return -1;
	}

	//查找成绩
	LList<Gread> search(const Student& student)
	{
		if (_data.isempty())
			return NULL;
		for (_data.moveToStart(); _data.currPos() <= _data.length(); _data.pred())
		{
			if (_data.getValue().isSameStudent(student))
			{
				return _data.getValue_()._greadList;
			}
		}
		return NULL;
	}

	//查找单科成绩
	double search(const Student& student, const string s)
	{
		for (_data.moveToStart(); _data.currPos() <= _data.length(); _data.pred())
		{
			if (_data.getValue().isSameStudent(student))
			{
				return _data.getValue_().search(s);
			}
		}
		return -1;
	}

	//返回学生数
	int size() const
	{
		return _data.length();
	}
};

