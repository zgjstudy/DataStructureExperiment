/*
*
*	���ݽṹ��һ��ʵ���
*	����˫��������ֵ��ѧ���ɼ�������
*	10.18 �Źڽ�
*
*/

#pragma once

#include "Dictionary.h"
#include "../exp1-1/LList.h"
#include <string>
#include <cstring>
#include <iostream>

using std::string;

//ѧ��������Ϣ
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

//���Ƴɼ���Ϣ
typedef std::pair<string, double> Gread;

//һ��ѧ�������ĳɼ���
struct StudentGread
{
	Student _student;
	LList<Gread> _greadList;

	//Ĭ�Ϲ��캯��
	StudentGread() {}

	//���캯��
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

	//�ڳɼ����а�ѧ����˳��������ɹ��򷵻سɼ���ʧ�ܷ���-1
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

	//��ӳɼ���Ϣ
	StudentGread& insert(const Gread& g)
	{
		_greadList.append(g);
		return *this;
	}

	//�Ƴ��ɼ���Ϣ
	void clear()
	{
		_greadList.clear();
	}

	//�Ƴ����Ƴɼ�
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

	//�ж��Ƿ�Ϊͬһ����
	bool isSameStudent(const Student& s) const
	{
		return s == _student;
	}

	//ʹ��LList����Ҫ����==
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

	//���ѧ����Ϣ
	void clear()
	{
		_data.clear();
	}

	//���ѧ����Ϣ
	void insert(const StudentGread& sg)
	{
		_data.append(sg);
	}

	//���ѧ����Ϣ
	void insert(const Student& student, LList<Gread>& l)
	{
		StudentGread sg(student, l);
		insert(sg);
	}

	//���ѧ����Ϣ
	void insert(const Student& s)
	{
		StudentGread sg(s);
		insert(sg);
	}

	//���ѧ���ɼ�
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

	//�Ƴ�ѧ��ȫ���ɼ�
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

	//�Ƴ�ѧ�����Ƴɼ�
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

	//���ҳɼ�
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

	//���ҵ��Ƴɼ�
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

	//����ѧ����
	int size() const
	{
		return _data.length();
	}
};

