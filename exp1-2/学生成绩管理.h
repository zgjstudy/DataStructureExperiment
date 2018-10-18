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

struct Student	//ѧ��������Ϣ
{
	string ID;
	string name;
};

struct Gread	//���Ƴɼ���Ϣ
{
	string courseTitle;
	double score;
};

struct StudentGread	//ѧ����Ϣ
{
	Student student;	//������Ϣ
	LList<Gread> gread;	//�ɼ���
};

class StudentGreadManager : Dictionary2D<Student, Gread, StudentGread>
{
private:
	LList<StudentGread>* _greadList;

	void insert(const Student& k, const StudentGread& e) {}	//���ز���Ҫ�Ľӿ�

	void insert(const Gread& k, const StudentGread& e) {}	//���ز���Ҫ�Ľӿ�

public:
	StudentGreadManager()	//���캯��
	{
		_greadList = new LList<StudentGread>;
	}

	~StudentGreadManager()	//��������
	{
		delete _greadList;
	}

	void clear()	//���ѧ����Ϣ
	{
		_greadList->clear();
	}

	void insert(const StudentGread& e)	//����ѧ����Ϣ
	{
		_greadList->append(e);
	}

	void insert(const Student& e)	//����ѧ��������Ϣ����
	{
		StudentGread sg;
		sg.student = e;
		_greadList->append(sg);
	}

};