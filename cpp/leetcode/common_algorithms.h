#pragma once

#include "include.h"
#include "public.h"

//回溯(DFS)的迭代写法,通用模板,适用于需要记忆完整路径,且需要遍历所有路径而不是单个路径
//作者blacksea3
//邮箱:17865191779@163.com
//这不能直接运行的
template<class T>
class DFS_ITER
{
public:
	DFS_ITER();
	~DFS_ITER();

	stack<T> find_next(vector<T> input, T pre);

	vector<vector<T>> run(vector<T> input);
};


