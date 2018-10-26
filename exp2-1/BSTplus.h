/*
*
*	数据结构第二次实验课
*	用于完成实验的BST类
*	10.26 张冠杰
*
*/

#pragma once
#include "BST.h"

template <typename Key, typename T> class BSTplus : public BST<Key, T>
{
public:

	//顺序打印
	void printSequently() const;

	//后序遍历
	void postorder(void(*visit)(Key&, T&));

	//中序遍历
	void inorder(void(*visit)(Key&, T&));

	//前序遍历
	void preorder(void(*visit)(Key&, T&));

	//计算叶子节点的数量
	int leafCount() const;

	//遍历叶子节点
	void leafTraversing();
};