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
	int n;

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

	// �����Ƿ����
	inline bool hasLChild(int i) { return inHeap(LChild(i)); }

	// �Һ����Ƿ����
	inline bool hasRChild(int i) { return inHeap(RChild(i)); }

	// ȡ���ʺϿ����Ѷ��ߣ���ʱǰ�����ȣ�
	inline int lighter(int i, int j) { return Comp::prior(_heap[i], _heap[j]) ? i : j; }

	// ���ظ����е�����ߣ�i��Ϊԭʼ�ĸ��ڵ㣬���ʱ���ڵ�����
	inline int trueParent(i)
	{
		return hasRChild(i) ? lighter(lighter(i, LChild(i)), RChild(i)) :
			(LChildValid(n, i) ? lighter(i, LChild(i)) : i);
	}
	
	// ����
	int siftDown(int i);

	// ����
	int siftUp(int i);

	// ��������
	void buildHeap();

public:
	heap(T* h, int )
};