/*
*
*	数据结构第一次实验课
*	双向链表（无序）
*	10.12 张冠杰
*
*/


#pragma once
#include "List.h"
#include "dLinkWithFreeList.h"

template <typename T>
class LList : public List<T>
{
private:
	Link<T>* header;	//头哨兵
	Link<T>* tailer;	//尾哨兵
	Link<T>* curr;		//当前节点
	int _size;			//规模

protected:
	void init()
	{
		header = new Link<T>;
		tailer = new Link<T>;
		header->next = tailer; header->prev = nullptr; //初始化头尾哨兵
		tailer->prev = header; tailer->next = nullptr;
		curr = header;
		_size = 0;
	}
	
public:
	LList(int size = 20181012)	//不限规模
	{
		init();
	}

	~LList()
	{
		clear();
		delete header;
		delete tailer;
	}

	//Copy constructor(deep)
	LList(const LList<T>& l)
	{
		init();

		for (Link<T>* p = l.header->next; p != l.tailer; p = p->next)	//依次插入所有元素
		{
			insert(p->element);
		}
	}

	void operator= (const LList<T>& l)
	{
		clear();
		for (Link<T>* p = l.header->next; p != l.tailer; p = p->next)	//依次插入所有元素
		{
			append(p->element);
		}
	}

	//clear
	void clear()
	{
		curr = header->next;
		while (curr != tailer)	//删除所有节点
		{
			curr = curr->next;
			delete curr->prev;
		}
		header->next = tailer;	//初始化头尾哨兵
		tailer->prev = header;
		_size = 0;
	}

	//move to start
	void moveToStart()
	{
		curr = header->next;
	}

	//move to end
	void moveToEnd()
	{
		curr = tailer->prev;
	}

	//curr point to predecessor
	void pred()
	{
		curr = curr->next;
	}

	//curr point to successor
	void succ()
	{
		curr = curr->prev;
	}

	//insert as successor
	void insert(const T& it)
	{
		if (curr == tailer)
			return;
		Link<T>* temp = curr;
		curr = curr->next;
		curr->prev = temp->next = new Link<T>(it, temp, curr);	//新建节点
		curr = curr->prev;
		_size++;
	}

	//insert as predecessor
	void insertAsPred(const T& it)
	{
		if (curr == header)
			return;
		Link<T>* temp = curr;
		curr = curr->prev;
		curr->next = temp->prev = new Link<T>(it, curr, temp);	//新建节点
		curr = curr->next;
		_size++;
	}

	//insert as last
	LList<T>& append(const T& it)
	{
		Link<T>* temp = tailer->prev;
		temp->next = tailer->prev = new Link<T>(it, temp, tailer);	//新建节点
		_size++;
		return *this;
	}

	//insert as first
	void insertAsFirst(const T& it)
	{
		Link<T>* temp = header->next;
		temp->prev = header->next = new Link<T>(it, header, temp);	//新建节点
		_size++;
	}

	//remove curr node, then curr point to successor
	//return curr->element
	T remove()
	{
		T tempE = curr->element;
		Link<T>* temp = curr;
		curr = curr->next;
		temp->prev->next = curr;
		curr->prev = temp->prev;
		delete temp;
		_size--;
		return tempE;
	}

	//remove pth node
	T remove(int p)
	{
		Link<T>* temp = curr;
		moveToPos(p);
		T tempE = remove();
		curr = temp;
		return tempE;
	}

	//return the size of the list
	virtual int length() const
	{
		return _size;
	}

	//return current position
	virtual int currPos() const
	{
		int i = 0;
		Link<T>* temp = header;
		while (temp != curr)
		{
			i++;
			temp = temp->next;
		}
		return i;
	}

	//move to position
	virtual void moveToPos(int pos)
	{
		curr = header;
		while (pos--)
		{
			curr = curr->next;
		}
	}

	//return current element
	virtual const T& getValue() const
	{
		return curr->element;
	}

	//return current element without const
	T& getValue_()
	{
		return curr->element;
	}

	//traverse by using 函数指针
	void traverse(void(*visit)(T&))
	{
		Link<T>* t = header->next;
		while (t != tailer)
		{
			visit(t->element);
			t = t->next;
		}
	}

	//是否为空
	bool isempty() const
	{
		return !_size;
	}

	//顺序查找，失败则返回-1
	int search(T& it) const
	{
		Link<T>* t = header->next;
		int cnt = 1;
		while (t != tailer)
		{
			if (t->element == it)
				return cnt;
			cnt++;
			t = t->next;
		}
		return -1;
	}
};
