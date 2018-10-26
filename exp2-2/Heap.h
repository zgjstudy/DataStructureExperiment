/*
*
*	数据结构第二次实验课
*	Heap类
*	10.26 张冠杰
*
*/

#pragma once

// 如果i应该在j之前，则Comp::prior(i, j)返回true.
template <typename T, typename Comp> class heap
{
private:
	T* _heap;
	int _maxSize;
	int n;

protected:
	// 父节点
	inline int parent(int i) { return (i - 1) >> 1; }

	// 左孩子
	inline int LChild(int i) { return 1 + (i << 1); }

	// 右孩子
	inline int RChild(int i) { return (i + 1) << 1; }

	// 最后一个内部节点
	inline int lastInternal() { return parent(n - 1); }

	// 是否在堆内
	inline bool inHeap(int i) { return i >= 0 && i < n; }

	// 是否为叶子节点
	inline bool isLeaf(int i) { return i < n && i >= n / 2; }

	// 左孩子是否存在
	inline bool hasLChild(int i) { return inHeap(LChild(i)); }

	// 右孩子是否存在
	inline bool hasRChild(int i) { return inHeap(RChild(i)); }

	// 取更适合靠近堆顶者（等时前者优先）
	inline int lighter(int i, int j) { return Comp::prior(_heap[i], _heap[j]) ? i : j; }

	// 返回父子中的最大者，i作为原始的父节点，相等时父节点优先
	inline int trueParent(i)
	{
		return hasRChild(i) ? lighter(lighter(i, LChild(i)), RChild(i)) :
			(LChildValid(n, i) ? lighter(i, LChild(i)) : i);
	}
	
	// 下滤
	int siftDown(int i);

	// 上滤
	int siftUp(int i);

	// 批量建堆
	void buildHeap();

public:
	heap(T* h, int )
};