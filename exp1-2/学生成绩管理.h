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

using std::string;

//学生基本信息
struct Student
{
	string ID;
	string name;

	bool operator== (const Student& r) const
	{
		return ID == r.ID && name == r.name;
	}
};

//单科成绩信息
typedef std::pair<string, double> Gread;

//一个学生和他的成绩单
class StudentGread
{
private:
	Student _student;
	LList<Gread>* _greadList;

	bool operator== (StudentGread) {}

public:
	StudentGread(const Student& s)
	{
		_student = s;
		_greadList = new LList<Gread>;
	}

	~StudentGread()
	{
		delete _greadList;
	}

	//在成绩单中按学科名顺序检索，成功则返回成绩，失败返回-1
	double search(string s) const
	{
		for (_greadList->moveToStart(); _greadList->currPos() < _greadList->length(); _greadList->succ())
		{
			if (_greadList->getValue().first == s)
				return _greadList->getValue().second;
		}
		return -1;
	}

	//添加成绩信息
	void insert(const Gread& g)
	{
		_greadList->append(g);
	}

	//移除成绩信息
	void clear()
	{
		_greadList->clear();
	}

	//移除单科成绩
	double remove(const string s)
	{
		for (_greadList->moveToStart(); _greadList->currPos() < _greadList->length(); _greadList->succ())
		{
			if (_greadList->getValue().first == s)
			{
				double score = _greadList->getValue().second;
				_greadList->remove();
				return score;
			}
		}
	}

	//判断是否为同一个人
	bool isSameStudent(const Student& s) const
	{
		return s == _student;
	}

	LList<Gread> getGread()
	{
		return *_greadList;
	}
};

class StudentGreadManager : Dictionary<Student, LList<Gread> >
{
private:
	LList<StudentGread>* _data;

public:
	StudentGreadManager();	//构造函数
	~StudentGreadManager();	//析构函数

	//清空学生信息
	void clear();

	//添加学生信息
	void insert(const Student&, LList<Gread>&);

	//添加学生信息
	void insert(const Student&);

	//移除学生全部成绩
	LList<Gread> remove(const Student&);

	//移除学生单科成绩
	double remove(const Student&, const string);

	//查找成绩
	LList<Gread> search(const Student&) const;

	//查找单科成绩
	double search(const Student&, const string) const;

	//返回学生数
	int size() const;

	void operator==(StudentGreadManager) {};
};

