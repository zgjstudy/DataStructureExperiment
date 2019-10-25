/*
*
*	数据结构第四次实验课
*	hashDict类
*	11.27 张冠杰
*
*/

#include <string>
#include <iostream>
#include <ctime>
#include "dictionary.h"
#include "KVpair.h"

using namespace std;

#define TOMBKEY -2

// Dictionary implemented with a hash table
template <typename Key, typename E>
class hashdict : public Dictionary<Key, E>
{
private:
	KVpair<Key, E>* HT;   // The hash table
	int M;        // Size of HT
	int currcnt;  // The current number of elements in HT
	Key EMPTYKEY; // User-supplied key value for an empty slot
	int* Perm;

	// Probe using quadratic probing
	int p(Key K, int i) const
	{
		return 2 * i*i + 3 * i + 1;
	}

	int h(int x)const
	{
		int 平方 = x * x;
		int 位数 = 0;
		while (平方 > 0)
		{
			平方 /= 10;
			位数++;
		}
		位数 = (位数 - 1) / 2;
		平方 = x * x;
		while (位数-- > 0)
			平方 /= 10;

		return 平方 % M;
	}

	void hashInsert(const Key&, const E&);
	E hashSearch(const Key&) const;
	E hashremove(const Key&) const;

public:
	hashdict(int sz, Key k)
	{
		M = sz;
		EMPTYKEY = k;
		currcnt = 0;
		HT = new KVpair<Key, E>[sz];
		for (int i = 0; i < M; i++)
			(HT[i]).setKey(EMPTYKEY);

		srand(0);
		Perm = new int[M - 1];
		for (int i = 0; i < M - 1; i++) {
			Perm[i] = (rand() % (M - 1) + 1);
		}
	}

	~hashdict() { delete HT; }

	E find(const Key& k) const
	{
		return hashSearch(k);
	}

	int size() { return currcnt; }

	void insert(const Key& k, const E& it)
	{
		Assert(currcnt < M, "Hash table is full");
		hashInsert(k, it);
		currcnt++;
	}

	E remove(const Key& K)
	{
		Assert(currcnt > 0, "Hash table is empty");
		E tmp = (hashremove(K));
		if (tmp != NULL)
			currcnt--;
		return tmp;
	}

	E removeAny()
	{
		Assert(currcnt != 0, "Hash table is empty");
		int i;
		for (i = 0; i < M; i++)
			if ((HT[i]).key() != EMPTYKEY)
			{
				(HT[i]).setKey(EMPTYKEY);
				currcnt--;
				break;
			}
		return (HT[i]).value();
	}

	void clear()
	{ // Clear the dictionary
		for (int i = 0; i < M; i++) (HT[i]).setKey(EMPTYKEY);
		currcnt = 0;
	}
};


// Insert e into hash table HT
template <typename Key, typename E>
void hashdict<Key, E>::
hashInsert(const Key& k, const E& e)
{
	int home;                     // Home position for e
	int pos = home = h(k);        // Init probe sequence
	for (int i = 1; EMPTYKEY != (HT[pos]).key() && TOMBKEY != (HT[pos]).key(); i++)
	{
		pos = (home + p(k, i)) % M; // probe
		Assert(k != (HT[pos]).key(), "Duplicates not allowed");
	}
	KVpair<Key, E> temp(k, e);
	HT[pos] = temp;
}

// Search for the record with Key K
template <typename Key, typename E>
E hashdict<Key, E>::
hashSearch(const Key& k) const
{
	int home;              // Home position for k
	int pos = home = h(k); // Initial position is home slot
	for (int i = 1; (k != (HT[pos]).key()) &&
		(EMPTYKEY != (HT[pos]).key()); i++)
		pos = (home + p(k, i)) % M; // Next on probe sequence
	//跳出for条件为:遍历到的slot的key要么是research的key，要么是EMPTYKEY,
	if (k == (HT[pos]).key())     // Found it
		return (HT[pos]).value();
	else return NULL;            // k not in hash table
}

// delete for the record with Key K
template <typename Key, typename E>
E hashdict<Key, E>::
hashremove(const Key& k) const
{
	int home;              // Home position for k
	int pos = home = h(k); // Initial position is home slot
	for (int i = 1; (k != (HT[pos]).key()) &&
		(EMPTYKEY != (HT[pos]).key()); i++)
		pos = (home + p(k, i)) % M; // Next on probe sequence
	if (k == (HT[pos]).key())
	{
		E tmp = (HT[pos]).value();
		(HT[pos]).setKey(TOMBKEY);
		return tmp;
	}
	return NULL;
}
