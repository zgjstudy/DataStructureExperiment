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
		_greadList = g;
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
		for (_greadList.moveToStart(); _greadList.currPos() < _greadList.length(); _greadList.succ())
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
		for (_greadList.moveToStart(); _greadList.currPos() < _greadList.length(); _greadList.succ())
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
private:
	LList<StudentGread>* _data;

public:
	StudentGreadManager();	//���캯��
	~StudentGreadManager();	//��������

	//���ѧ����Ϣ
	void clear();

	//���ѧ����Ϣ
	void insert(const Student&, LList<Gread>&);

	//���ѧ����Ϣ
	void insert(const Student&);

	//���ѧ����Ϣ
	void insert(const StudentGread&);

	//�Ƴ�ѧ��ȫ���ɼ�
	LList<Gread> remove(const Student&);

	//�Ƴ�ѧ�����Ƴɼ�
	double remove(const Student&, const string);

	//���ҳɼ�
	LList<Gread> search(const Student&) const;

	//���ҵ��Ƴɼ�
	double search(const Student&, const string) const;

	//����ѧ����
	int size() const;
};

