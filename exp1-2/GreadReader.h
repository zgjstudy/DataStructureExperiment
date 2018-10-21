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
#include <sstream>
#include "学生成绩管理.h"

class GreadReader
{
private:
	std::fstream _reader;
	std::stringstream _buffer;

	//初始化
	void init()
	{
		_reader.clear();		//清空
		_buffer.clear();
		string s;
		getline(_reader, s);	//读取第一行
	}

public:
	//构造函数
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

	//读取全部数据
	void readAll(StudentGreadManager* sgm)
	{
		Student s;
		LList<Gread> g;
		string temp;				//用于辅助的string

		while (!_reader.eof())	//判断文件尾
		{
			string id, name;
			_buffer << temp;			//读取id和名字
			_buffer >> id;
			_buffer << temp;
			_buffer >> name;

			std::cout << id << " " << name << std::endl;

			string first;
			double second;
			while (_buffer << temp)		//读取全部成绩信息
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
