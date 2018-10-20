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

	//�����滻�����ַ��ĸ�������
	string& replace_all(string& str, const string& old_value, const string& new_value)
	{
		while (true)
		{
			string::size_type pos(0);
			if ((pos = str.find(old_value)) != string::npos)
				str.replace(pos, old_value.length(), new_value);
			else break;
		}
		return str;
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

	//��ȡһ��ѧ����������Ϣ
	StudentGread readStudent()
	{
		Student s;
		LList<Gread> g;
		string temp;				//���ڸ�����string
		getline(_reader, temp);		//�����ݴ浽������

		replace_all(temp, ",", " ");//��,�滻Ϊ �����������
		
		string id, name;
		
		if(_buffer >> temp)			//��ȡid������
			_buffer << id;
		if(_buffer >> temp)
			_buffer << name;

		string first;
		double second;
		while (_buffer >> temp)		//��ȡȫ���ɼ���Ϣ
		{
			_buffer << temp;
			_buffer >> first;
			_buffer << temp;
			_buffer >> second;
			g.append(std::make_pair(first, second));
		}

		return StudentGread(s, g);
	}

};
