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

void StudentGreadManager::insert(const StudentGread & sg)
{
	_data->append(sg);
}

LList<Gread> StudentGreadManager::remove(const Student & student)
{
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			LList<Gread> temp = _data->getValue_()._greadList;
			_data->getValue_().clear();
			return temp;
		}
	}
	return NULL;
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
	return -1;
}

LList<Gread> StudentGreadManager::search(const Student & student) const
{
	if (_data->isempty())
		return NULL;
	for (_data->moveToStart(); _data->currPos() < _data->length(); _data->succ())
	{
		if (_data->getValue().isSameStudent(student))
		{
			return _data->getValue_()._greadList;
		}
	}
	return NULL;
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
	return -1;
}

inline int StudentGreadManager::size() const
{
	return _data->length();
}
