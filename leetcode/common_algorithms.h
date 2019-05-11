#pragma once

#include "include.h"
#include "public.h"

//����(DFS)�ĵ���д��,ͨ��ģ��,��������Ҫ��������·��,����Ҫ��������·�������ǵ���·��
//����blacksea3
//����:17865191779@163.com
//�ⲻ��ֱ�����е�
template<class T>
class DFS_ITER
{
public:
	DFS_ITER();
	~DFS_ITER();

	stack<T> find_next(vector<T> input, T pre);

	vector<vector<T>> run(vector<T> input);
};


