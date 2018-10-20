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

	//用于替换所有字符的辅助函数
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

	//读取一个学生的数据信息
	StudentGread readStudent()
	{
		Student s;
		LList<Gread> g;
		string temp;				//用于辅助的string
		getline(_reader, temp);		//将数据存到缓冲区

		replace_all(temp, ",", " ");//将,替换为 方便后续操作
		
		string id, name;
		
		if(_buffer >> temp)			//读取id和名字
			_buffer << id;
		if(_buffer >> temp)
			_buffer << name;

		string first;
		double second;
		while (_buffer >> temp)		//读取全部成绩信息
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
