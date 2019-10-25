#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <queue>

using namespace std;

struct costTime {
	double x;
	double costtime;
	costTime(double x1, double y) :x(x1), costtime(y) {}
};


class Base
{
public:
	void Write(vector<struct  costTime> costTime_vector, string costTime_Path)
	{
		ofstream outFile;
		outFile.open(costTime_Path.c_str(), ios::out);
		outFile << "N/M" << ',' << "costTime" << endl;
		for (vector<struct costTime>::iterator iter = costTime_vector.begin(); iter != costTime_vector.end(); ++iter)
		{
			outFile << iter->x << ",\"" << iter->costtime << '\"' << endl;
		}

		outFile.close();
	}
};

void func(queue<double> v,string Path) {

	Base base;

	const int  M = 2500;

	vector<costTime> costTime_vector;

	for (int i = 1; i < M; i++) {
	costTime tmp((double)(i) / double(M), v.front());
	costTime_vector.push_back(tmp);
	v.pop();
	}

	base.Write(costTime_vector, Path);
}
