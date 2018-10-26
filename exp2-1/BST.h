/*
*
*	数据结构第二次实验课
*	BST类
*	10.26 张冠杰
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

	//清空
	void clear();

	//插入
	void insert(const Key& k, const T& e);

	//删除
	T remove(const Key& k);

	//查询
	T find(const Key& k) const;

	//返回节点数
	int size() const;

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