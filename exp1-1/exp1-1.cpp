#include "runtime.h"
#include "LList.h"
#include "AList.h"
using namespace std;

void print(int& i)
{
	cout << i << " ";
}

int main()
{
	AList<int> L;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
	cout << "AList element(s):";
	L.append(a).append(b).append(c).append(d).append(e);
	L.traverse(print);
	cout << endl << "AList Size: " << L.length() << endl;
	cout << "AList is empty: " << (L.isempty() ? "True" : "False") << endl;
	L.moveToPos(3);
	cout << "3rd element of AList: " << L.getValue() << endl;
	cout << "a's position is: " << L.search(a) << endl;
	L.moveToPos(4);
	L.insert(f);
	cout << "After inserted f, AList element(s):";
	L.traverse(print);
	cout << endl;
	L.moveToPos(3);
	L.remove();
	cout << "After removed 3rd element, AList element(s):";
	L.traverse(print);
	cout << endl << endl;

	LList<int> H;
	cout << "LList element(s):";
	H.append(a).append(b).append(c).append(d).append(e);
	H.traverse(print);
	cout << endl << "LList Size: " << H.length() << endl;
	cout << "LList is empty: " << (H.isempty() ? "True" : "False") << endl;
	H.moveToPos(3);
	cout << "3rd element of LList: " << H.getValue() << endl;
	cout << "a's position is: " << H.search(a) << endl;
	H.moveToPos(4);
	H.insert(f);
	cout << "After inserted f, LList element(s):";
	H.traverse(print);
	cout << endl;
	H.remove(3);
	cout << "After removed 3rd element, LList element(s):";
	H.traverse(print);
	cout << endl;



	system("pause");
	return 0;
}