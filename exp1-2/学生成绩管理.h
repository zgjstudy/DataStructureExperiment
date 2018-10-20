/*
*
*	���ݽṹ��һ��ʵ���
*	����˫������Ͷ�ά�ֵ��ѧ���ɼ�������
*	10.18 �Źڽ�
*
*/

#pragma once

#include "Dictionary.h"
#include "../exp1-1/LList.h"
#include <string>
#include <cstring>

using std::string;

//ѧ��������Ϣ
struct Student
{
	string ID;
	string name;

	bool operator== (const Student& r) const
	{
		return ID == r.ID && name == r.name;
	}
};

//���Ƴɼ���Ϣ
typedef std::pair<string, double> Gread;

//һ��ѧ�������ĳɼ���
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

	//�ڳɼ����а�ѧ����˳��������ɹ��򷵻سɼ���ʧ�ܷ���-1
	double search(string s) const
	{
		for (_greadList->moveToStart(); _greadList->currPos() < _greadList->length(); _greadList->succ())
		{
			if (_greadList->getValue().first == s)
				return _greadList->getValue().second;
		}
		return -1;
	}

	//��ӳɼ���Ϣ
	void insert(const Gread& g)
	{
		_greadList->append(g);
	}

	//�Ƴ��ɼ���Ϣ
	void clear()
	{
		_greadList->clear();
	}

	//�Ƴ����Ƴɼ�
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

	//�ж��Ƿ�Ϊͬһ����
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
	StudentGreadManager();	//���캯��
	~StudentGreadManager();	//��������

	//���ѧ����Ϣ
	void clear();

	//���ѧ����Ϣ
	void insert(const Student&, LList<Gread>&);

	//���ѧ����Ϣ
	void insert(const Student&);

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

	void operator==(StudentGreadManager) {};
};

