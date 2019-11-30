#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_

//实现直接插入排序算法

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

template < typename T>
class InsertSort
{
private:
	unsigned len;  //若只写了unsigned，则默认为unsigned int类型，无符号整型。
	vector<T> list;

public:
	InsertSort(vector<T> _list, unsigned _len)
	{
		for (unsigned i = 0; i < _len; ++i) list.push_back(_list[i]);
		this->len = _len;
	}

	void insertSort()
	{
		T insertNum; //insertNum临时存放待插入的数据，找到合适位置后，将其赋值。
		for (unsigned i = 0; i < len; ++i) // 插入len次数据
		{
			insertNum = list[i]; // 每次用insertNum临时存放待插入的数据
			unsigned j = i; //从后往前开始找，i、i-1、i-2
			while (j && insertNum < list[j - 1]) // 寻找该数据的合适位置，找到后即为j(所以必须判断j大于0)
			{                       //此处插入排序是按照升序排序的。
				list[j] = list[j - 1]; //向后挪位
				--j;
			}
			list[j] = insertNum; //list[j]存放的就是插入数据的合适位置
		}
	}

	void out()
	{
		for (unsigned i = 0; i < len; i++)
		{
			cout << list[i] << " ";
			if ((i + 1) % 18 == 0) cout << endl;  //17个数为一行
		}
		cout << endl;
	}
};


int main()
{
	const unsigned list_num = 8;
	int data[list_num] = { 1,5,2,4,6,8,3,2 };
	vector<int> testData;
	for (unsigned i = 0; i < list_num; i++)
	{
		testData.push_back(data[i]);
	}
	InsertSort<int>test(testData, list_num);
	test.insertSort();
	test.out();
	system("pause");
}

#endif // !_INSERTSORT_H_