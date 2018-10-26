/*
*
*	���ݽṹ�ڶ���ʵ���
*	�������ʵ���BST��
*	10.26 �Źڽ�
*
*/

#pragma once
#include "BST.h"

template <typename Key, typename T> class BSTplus : public BST<Key, T>
{
public:

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