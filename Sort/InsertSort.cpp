#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_

//ʵ��ֱ�Ӳ��������㷨

#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

template < typename T>
class InsertSort
{
private:
	unsigned len;  //��ֻд��unsigned����Ĭ��Ϊunsigned int���ͣ��޷������͡�
	vector<T> list;

public:
	InsertSort(vector<T> _list, unsigned _len)
	{
		for (unsigned i = 0; i < _len; ++i) list.push_back(_list[i]);
		this->len = _len;
	}

	void insertSort()
	{
		T insertNum; //insertNum��ʱ��Ŵ���������ݣ��ҵ�����λ�ú󣬽��丳ֵ��
		for (unsigned i = 0; i < len; ++i) // ����len������
		{
			insertNum = list[i]; // ÿ����insertNum��ʱ��Ŵ����������
			unsigned j = i; //�Ӻ���ǰ��ʼ�ң�i��i-1��i-2
			while (j && insertNum < list[j - 1]) // Ѱ�Ҹ����ݵĺ���λ�ã��ҵ���Ϊj(���Ա����ж�j����0)
			{                       //�˴����������ǰ�����������ġ�
				list[j] = list[j - 1]; //���Ųλ
				--j;
			}
			list[j] = insertNum; //list[j]��ŵľ��ǲ������ݵĺ���λ��
		}
	}

	void out()
	{
		for (unsigned i = 0; i < len; i++)
		{
			cout << list[i] << " ";
			if ((i + 1) % 18 == 0) cout << endl;  //17����Ϊһ��
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