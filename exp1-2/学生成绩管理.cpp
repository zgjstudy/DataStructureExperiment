#include "学生成绩管理.h"

StudentGreadManager::StudentGreadManager()
{
	_data = new LList<StudentGread>;
}

StudentGreadManager::~StudentGreadManager()
{
	delete _data;
}

void StudentGreadManager::clear()
{
	_data->clear();
}

void StudentGreadManager::insert(const Student & student, LList<Gread>& l)
{
	StudentGread sg(student);
	for (l.moveToStart(); l.currPos() < l.length(); l.succ())
	{
		sg.insert(l.getValue());
	}
	_data->append(student);
}

void StudentGreadManager::insert(const Student & s)
{
	StudentGread sg(s);
	_data->append(s);
}

LList<Gread> StudentGreadManager::remove(const Student & student)
{
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			LList<Gread> temp = _data->getValue_().getGread();
			_data->getValue_().clear();
			return temp;
		}
	}
}

double StudentGreadManager::remove(const Student & student, const string s)
{
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			return _data->getValue_().remove(s);
		}
	}
}

LList<Gread> StudentGreadManager::search(const Student & student) const
{
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			return _data->getValue_().getGread();
		}
	}
}

double StudentGreadManager::search(const Student & student, const string s) const
{
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			return _data->getValue_().search(s);
		}
	}
}

inline int StudentGreadManager::size() const
{
	return _data->length();
}
