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

	//��ȡ������СԪ�ؽڵ�
	NodePtr getmin(NodePtr root)
	{
		if (root->left() == nullptr)
			return root;
		else
			return getmin(root->left());
	}

	//��ȡ��С�ڵ㲢��ԭ�����Ƴ��ýڵ�
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
		if (root == nullptr)	//δ��ѯ�����
			return nullptr;
		else if (k < root->key())	//���С�ڵ�ǰkey����������������
			root->setLeft(removehelp(root->left(), k));
		else if (k > root->key())	//������ڵ�ǰkey����������������
			root->setRight(removehelp(root->right(), k));
		else	//����
		{
			NodePtr temp = root;
			if (root->left() == nullptr)	//���û��������
			{
				root = root->right();
				delete temp;
			}
			else if (root->right() == nullptr)	//���û��������
			{
				root = root->left();
				delete temp;
			}
			else
			{
				NodePtr temp = getmin(root->right());	//����С�ڵ�Ĵ浽root
				root->setElement(temp->element());
				root->setKey(temp->key());
				root->setRight(deletemin(root->right()));	//ɾ����С�Ľڵ�
				delete temp;
			}
		}
		return root;
	}

public:
	BST() : _root(nullptr), _nodeCount(0) {};
	~BST() { clear(); }

	//���
	void clear()
	{
		clearhelp(_root);
		_root = nullptr;
		_nodeCount = 0;
	}

	//����
	virtual void insert(const Key& k, const T& e)
	{
		_root = inserthelp(_root, k, e);
		_nodeCount++;
	}

	//ɾ��
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

	//��ѯ
	virtual T find(const Key& k) const
	{
		return findhelp(_root, k);
	}

	//���ؽڵ���
	int size() const { return _nodeCount; }
};
