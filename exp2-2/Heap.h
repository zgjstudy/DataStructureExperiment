/*
*
*	���ݽṹ�ڶ���ʵ���
*	Heap��
*	10.26 �Źڽ�
*
*/

#pragma once

// ���iӦ����j֮ǰ����Comp::prior(i, j)����true.
template <typename T, typename Comp> class heap
{
private:
	T* _heap;
	int _maxSize;
	int n;			//��ǰ����±�

protected:
	// ���ڵ�
	inline int parent(int i) { return (i - 1) >> 1; }

	// ����
	inline int LChild(int i) { return 1 + (i << 1); }

	// �Һ���
	inline int RChild(int i) { return (i + 1) << 1; }

	// ���һ���ڲ��ڵ�
	inline int lastInternal() { return parent(n - 1); }

	// �Ƿ��ڶ���
	inline bool inHeap(int i) { return i >= 0 && i < n; }

	// �Ƿ�ΪҶ�ӽڵ�
	inline bool isLeaf(int i) { return i < n && i >= n / 2; }

	// ���ڵ��Ƿ����
	inline bool hasParent(int i) { return i > 0; }

	// �����Ƿ����
	inline bool hasLChild(int i) { return inHeap(LChild(i)); }

	// �Һ����Ƿ����
	inline bool hasRChild(int i) { return inHeap(RChild(i)); }

	// ȡ���ʺϿ����Ѷ��ߣ���ʱǰ�����ȣ�
	inline int lighter(int i, int j) { return Comp::prior(_heap[i], _heap[j]) ? i : j; }

	// ���ظ����е�����ߣ�i��Ϊԭʼ�ĸ��ڵ㣬���ʱ���ڵ�����
	inline int trueParent(int i)
	{
		return hasRChild(i) ? lighter(lighter(i, LChild(i)), RChild(i)) :
			(hasLChild(i) ? lighter(i, LChild(i)) : i);
	}
	
	// ����
	int siftDown(int i)
	{
		int j;
		while (i != (j = trueParent(i)))	//ֻҪi��j
		{
			Comp::swap(_heap[i], _heap[j]);	//���򽻻�
			i = j;
		}
		return i;
	}

	// ����
	int siftUp(int i)
	{
		while (hasParent(i))	//��δ����Ѷ�
		{
			int j = parent(i);	//��i֮����Ϊj
			if (Comp::prior(_heap[j], _heap[i]))	//���i,j˳����ȷ���������
				break;
			Comp::swap(_heap[i], _heap[j]);	//���򽻻�����λ��
			i = j;
		}
		return i;	//�������˵ִ��λ��
	}

	// ��������
	void buildHeap()
	{
		for (int i = lastInternal(n); i >= 0; --i)
		{
			siftDown(i);
		}
	}

public:
	heap()
		:n(0), _maxSize(100)
	{
		_heap = new T[_maxSize];
	}

	heap(T* h, int size, int max = 100)
		:n(size - 1), _maxSize(max)
	{
		_heap = new T[_maxSize];
		for (int i = 0; i <= n; ++i)
		{
			_heap[i] = h[i];
		}
		buildHeap();
	}

	~heap()
	{
		delete[]_heap;
	}

	heap<T, Comp> & insert(T e)
	{
		if (n + 1 > _maxSize)
			exit(-1);
		_heap[++n] = e;
		siftUp(n);		//����

		return *this;
	}

	T remove()
	{
		T max = _heap[0];
		_heap[0] = _heap[n--];
		siftDown(0);
		return max;
	}

};