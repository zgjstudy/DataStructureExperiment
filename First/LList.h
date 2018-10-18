/*
*
*	数据结构第一次实验课
*	双向链表
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
		header->next = tailer; header->prev = nullptr;
		tailer->prev = header; tailer->next = nullptr;
		_size = 0;
	}
	
public:
	LList(int size = DefaultSize)
	{
		init();
	}

	~LList()
	{
		clear();
		delete header;
		delete tailer;
	}

	//clear
	void clear()
	{
		curr = header->next;
		while (curr != tailer)
		{
			curr = curr->next;
			delete curr->prev;
		}
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
		Link<T>* temp = curr;
		curr = curr->next;
		curr->prev = temp->next = new Link<T>(it, temp, curr);
		curr = curr->prev;
		_size++;
	}

	//insert as predecessor
	void insertAsPred(const T& it)
	{
		Link<T>* temp = curr;
		curr = curr->prev;
		curr->next = temp->prev = new Link<T>(it, curr, temp);
		curr = curr->next;
		_size++;
	}

	//insert as last
	void append(const T& it)
	{
		Link<T>* temp = tailer->prev;
		temp->next = tailer->prev = new Link<T>(it, temp, tailer);
		_size++;
	}

	//insert as first
	void insertAsFirst(const T& it)
	{
		Link<T>* temp = header->next;
		temp->prev = header->next = new Link<T>(it, header, temp);
		_size++;
	}

	//remove curr node, then curr point to successor
	//return curr->element
	T remove()
	{
		T tempE = curr->element;
		Link<T>* temp = curr;
		curr = curr->next;
		temp->next = curr;
		curr->prev = temp->prev;
		delete temp;
		_size--;
		return tempE;
	}

	//remove pth node
	T remove(int p);

	//return the size of the list
	virtual int length() const
	{
		return _size;
	}

	//return current position
	virtual int currPos() const;

	//move to position
	virtual void moveToPos(int pos);

	//return current element
	virtual const T& getValue() const
	{
		return curr->element;
	}

};

