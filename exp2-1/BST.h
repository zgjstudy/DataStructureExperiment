/*
*
*	���ݽṹ�ڶ���ʵ���
*	BST��
*	10.26 �Źڽ�
*
*/

#pragma once
#include <iostream>
#include "BSTNode.h"
#include "Dictionary.h"

template <typename Key, typename T> class BST : public Dictionary<Key, T>
{
private:
	typedef BSTNode<Key, T>* NodePtr;
	NodePtr _root;
	int _nodeCount;

	T removeAny() { return T(); }	//���ز���Ҫ�Ľӿ�

	//���ڼ����ĸ�������
	int counthelp(NodePtr root)
	{
		if (root == nullptr)
			return 0;
		return 1 + counthelp(root->left()) + counthelp(root->right());
	}

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
		if (root == NULL)
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

	//˳�������������
	void printhelp(BSTNode<Key, T>* root) const
	{
		if (root == NULL)		
		{
			std::cout << " / ";	//�սڵ����/
			return;
		}
		std::cout << " " << root->key() << " ";	//�����ǰkey
		printhelp(root->left());	//���������
		printhelp(root->right());	//���������
	}

	//���������������
	void preorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		visit(root->key(), root->element());				//������
		preorderhelp(root->left(), visit);
		preorderhelp(root->right(), visit);
	}

	//���������������
	void inorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		inorderhelp(root->left(), visit);			//�����
		visit(root->key(), root->element());
		inorderhelp(root->right(), visit);
	}

	//���������������
	void postorderhelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr) return;
		postorderhelp(root->left(), visit);	//���Ҹ�
		postorderhelp(root->right(), visit);
		visit(root->key(), root->element());
	}

	//��Ҷ�Ӹ�������
	int leafCounthelp(BSTNode<Key, T>* root) const
	{
		if (root == nullptr)	//��������0
			return 0;
		if (root->isLeaf())		//Ҷ�ӽ�㷵��1
			return 1;
		else
			return leafCounthelp(root->left()) + leafCounthelp(root->right());	//ûɶ��ע�͵�
	}

	//����Ҷ�ӽ�㸨������
	void leafTraversinghelp(BSTNode<Key, T>* root, void(*visit)(Key&, T&))
	{
		if (root == nullptr)	//��������
			return;
		if (root->isLeaf())		//Ҷ�ӽ��ִ��visit
			visit(root->key(), root->element());
		leafTraversinghelp(root->left(), visit);	//����������
		leafTraversinghelp(root->right(), visit);	//����������
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

	//˳���ӡ
	void printSequently() const
		{
			printhelp(_root);
		}

	//�������
	void postorder(void(*visit)(Key&, T&))
		{
			postorderhelp(_root, visit);
		}

	//�������
	void inorder(void(*visit)(Key&, T&))
		{
			inorderhelp(_root, visit);
		}

	//ǰ�����
	void preorder(void(*visit)(Key&, T&))
		{
			preorderhelp(_root, visit);
		}

	//����Ҷ�ӽڵ������
	int leafCount() const
		{
			return leafCounthelp(_root);
		}

	//����Ҷ�ӽڵ�
	void leafTraversing(void(*visit)(Key&, T&))
		{
			leafTraversinghelp(_root, visit);
		}

};
