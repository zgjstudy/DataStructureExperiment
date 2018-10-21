/*
*
*	���ݽṹ��һ��ʵ���
*	ѧ�����ݶ�ȡ
*	10.20 �Źڽ�
*
*/

#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include "ѧ���ɼ�����.h"

class GreadReader
{
private:
	std::fstream _reader;
	std::stringstream _buffer;

	//��ʼ��
	void init()
	{
		_reader.clear();		//���
		_buffer.clear();
		string s;
		getline(_reader, s);	//��ȡ��һ��
	}

public:
	//���캯��
	GreadReader(string filename)
	{
		_reader.open(filename);
		if (!_reader.is_open())
		{
			std::cerr << "Error opening file";
			exit(-1);
		}
		init();
	}

	~GreadReader()
	{
		_reader.close();
	}

	//��ȡȫ������
	void readAll(StudentGreadManager* sgm)
	{
		Student s;
		LList<Gread> g;
		string temp;				//���ڸ�����string

		while (!_reader.eof())	//�ж��ļ�β
		{
			string id, name;
			_buffer << temp;			//��ȡid������
			_buffer >> id;
			_buffer << temp;
			_buffer >> name;

			std::cout << id << " " << name << std::endl;

			string first;
			double second;
			while (_buffer << temp)		//��ȡȫ���ɼ���Ϣ
			{
				_buffer >> first;
				_buffer << temp;
				_buffer >> second;
				g.append(std::make_pair(first, second));
			}

			sgm->insert(s, g);
		}
	}

};
