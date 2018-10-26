/*
*
*	���ݽṹ�ڶ���ʵ���
*	BST��
*	10.26 �Źڽ�
*
*/

#pragma once
#include "BSTNode.h"
#include "Dictionary.h"

template <typename Key, typename T> class BST : public Dictionary<Key, T>
{
private:
	BSTNode<Key, T>* _root = nullptr;
	int _nodeCount = 0;

public:
	BST() {};
	~BST()
	{
		clear();
	}

	//���
	void clear();

	//����
	void insert(const Key& k, const T& e);

	//ɾ��
	T remove(const Key& k);

	//��ѯ
	T find(const Key& k) const;

	//���ؽڵ���
	int size() const;

	//˳���ӡ
	void printSequently() const;

	//�������
	void postorder(void(*visit)(Key&, T&));

	//�������
	void inorder(void(*visit)(Key&, T&));

	//ǰ�����
	void preorder(void(*visit)(Key&, T&));

	//����Ҷ�ӽڵ������
	int leafCount() const;

	//����Ҷ�ӽڵ�
	void leafTraversing();
};