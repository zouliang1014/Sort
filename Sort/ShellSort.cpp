//实现希尔排序算法
#ifndef _SHELLSORT_H_
#define _SHELLSORT_H_
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class ShellSort
{
private:
	vector<int> list;
	unsigned len;

public:
	ShellSort(vector<int>_list,unsigned _len)
	{
		this->len = _len;
		for (unsigned i = 0; i < _len; i++)
		{
			list.push_back(_list[i]);
		}
	}

	void shellsort()
	{
		T insertNum;
		unsigned gap = len / 2;
		while (gap)
		{
			for (unsigned i = gap; i < len; i++)
			{
				insertNum = list[i];
				unsigned j = i;
				while (j >= gap && insertNum < list[j-gap]) //寻找插入的合适位置
				{
					list[j] = list[j - gap];
					j = j - gap;
				}
				list[j] = insertNum;//找到插入的位置
			}
			gap = gap / 2;
		}

	}

	void out()
	{
		for (unsigned i = 0; i < len; i++)
		{
			cout << list[i] << " ";
			if ((i + 1) % 18 == 0) cout << endl;
		}
		cout << endl;
	}

};


int main()
{
	const unsigned data_num = 8;
	int data[data_num] = { 5,23,11,2,1,5,33,12 };

	vector<int> testData;
	for (unsigned i = 0; i < data_num; i++)
	{
		testData.push_back(data[i]);
	}

	ShellSort<int> test(testData, data_num);
	test.shellsort();
	test.out();
	system("pause");
}



#endif // !_SHELLSORT_H_
