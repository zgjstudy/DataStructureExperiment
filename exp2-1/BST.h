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
	typedef BSTNode<Key, T>* NodePtr;
	NodePtr _root = nullptr;
	int _nodeCount = 0;

	T removeAny() { return T(); }

protected:
	//clear helper
	void clearhelp(NodePtr root)
	{
		if (root == nullptr) return;
		clearhelp(root->left());
		clearhelp(root->right());
		delete root;
	}

	//find helper, return value
	T findhelp(NodePtr root, const Key& k) const
	{
		if (root == nullptr)
			return NULL;
		if (k < root->key())
			return findhelp(root->left(), k);
		else if (k > root->key())
			return findhelp(root->right(), k);
		else return root->element();
	}

	//获取树中最小元素节点
	NodePtr getmin(NodePtr root)
	{
		if (root->left() == nullptr)
			return root;
		else
			return getmin(root->left());
	}

	//获取最小节点并在原树中移除该节点
	NodePtr deletemin(NodePtr root)
	{
		if (root->left() == nullptr)
			return root->right();
		else
		{
			root->setLeft(deletemin(root->left()));
			return root;
		}
	}

	//insert helper
	NodePtr inserthelp(NodePtr root, const Key& k, const T& e)
	{
		if (root == nullptr)
			return new BSTNode<Key, T>(k, e, nullptr, nullptr);
		if (k < root->key())
			root->setLeft(inserthelp(root->left(), k, e));
		else
			root->setRight(inserthelp(root->right(), k, e));
		return root;
	}

	//remove helper
	NodePtr removehelp(NodePtr root, const Key& k)
	{
		if (root == nullptr)	//未查询到结果
			return nullptr;
		else if (k < root->key())	//如果小于当前key则在左子树中搜索
			root->setLeft(removehelp(root->left(), k));
		else if (k > root->key())	//如果大于当前key则在右子树中搜索
			root->setRight(removehelp(root->right(), k));
		else	//命中
		{
			NodePtr temp = root;
			if (root->left() == nullptr)	//如果没有左子树
			{
				root = root->right();
				delete temp;
			}
			else if (root->right() == nullptr)	//如果没有右子树
			{
				root = root->left();
				delete temp;
			}
			else
			{
				NodePtr temp = getmin(root->right());	//将最小节点的存到root
				root->setElement(temp->element());
				root->setKey(temp->key());
				root->setRight(deletemin(root->right()));	//删除最小的节点
				delete temp;
			}
		}
		return root;
	}

public:
	BST() : _root(nullptr), _nodeCount(0) {};
	~BST() { clear(); }

	//清空
	void clear()
	{
		clearhelp(_root);
		_root = nullptr;
		_nodeCount = 0;
	}

	//插入
	virtual void insert(const Key& k, const T& e)
	{
		_root = inserthelp(_root, k, e);
		_nodeCount++;
	}

	//删除
	virtual T remove(const Key& k)
	{
		T temp = findhelp(_root, k);
		if (temp != NULL)
		{
			_root = removehelp(_root, k);
			_nodeCount--;
		}
		return temp;
	}

	//查询
	virtual T find(const Key& k) const
	{
		return findhelp(_root, k);
	}

	//返回节点数
	int size() const { return _nodeCount; }
};
