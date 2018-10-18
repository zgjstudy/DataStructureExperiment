/*
*
*	���ݽṹ��һ��ʵ���
*	��ά�ֵ���
*	10.18 �Źڽ�
*
*/

#pragma once

template <typename key1, typename key2, typename E>
class Dictionary2D
{
private:
	void operator =(const Dictionary2D&) {}	//��ֹ��ֵ
	Dictionary2D(const Dictionary2D&) {}	//��ֹ����

public:
	Dictionary2D() {}
	virtual ~Dictionary2D() {}

	virtual void clear() = 0;

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	virtual void insert(const key1& k, const E& e) = 0;
	virtual void insert(const key2& k, const E& e) = 0;

	// Remove and return a record.
	// k: The key of the record to be removed.
	// Return: A maching record. If multiple records match
	// "k", remove an arbitrary one. Return NULL if no record
	// with key "k" exists.
	virtual E remove(const key1& k) = 0;
	virtual E remove(const key2& k) = 0;

	// Return: A record matching "k" (NULL if none exists).
	// If multiple records match, return an arbitrary one.
	// k: The key of the record to find
	virtual E search(const key1& k) const = 0;
	virtual E search(const key2& k) const = 0;

	// Return the number of records in the dictionary.
	virtual int size() = 0;
};