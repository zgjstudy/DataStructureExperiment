/*
*
*	数据结构第一次实验课
*	字典类
*	10.18 张冠杰
*
*/

#pragma once

template <typename key1, typename E>
class Dictionary
{
private:
	void operator =(const Dictionary&) {}	//防止赋值
	Dictionary(const Dictionary&) {}	//防止复制

public:
	Dictionary() {}
	virtual ~Dictionary() {}

	virtual void clear() = 0;

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	virtual void insert(const key1& k, E& e) = 0;

	// Remove and return a record.
	// k: The key of the record to be removed.
	// Return: A maching record. If multiple records match
	// "k", remove an arbitrary one. Return NULL if no record
	// with key "k" exists.
	virtual E remove(const key1& k) = 0;

	// Return: A record matching "k" (NULL if none exists).
	// If multiple records match, return an arbitrary one.
	// k: The key of the record to find
	virtual E search(const key1& k) const = 0;

	// Return the number of records in the dictionary.
	virtual int size() const = 0;
};