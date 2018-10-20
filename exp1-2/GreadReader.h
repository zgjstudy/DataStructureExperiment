/*
*
*	数据结构第一次实验课
*	学生数据读取
*	10.20 张冠杰
*
*/

#pragma once
#include <fstream>
#include <iostream>
#include "学生成绩管理.h"

class GreadReader
{
private:
	std::fstream _reader;

	void init()
	{
		string s;
		getline(_reader, s);
	}

public:
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

	Student readStudent()
	{
		string id, name;
		getline(_reader, id, ',');
		getline(_reader, name, ',');
		Student temp;
		temp.ID = id;
		temp.name = name;
		return temp;
	}

	LList<Gread> readGread()
	{
		LList<Gread> data;
	}
};
