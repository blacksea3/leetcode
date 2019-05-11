#include "include.h"
#include "public.h"
#include "common_algorithms.h"

template<class T>
inline DFS_ITER<T>::DFS_ITER()
{
}

template<class T>
DFS_ITER<T>::~DFS_ITER()
{
}

//根据所有元素,根据当前元素,寻找一些符合的元素
//input也可以是一个树的根节点,应该按需修改
template<class T>
stack<T> DFS_ITER<T>::find_next(vector<T> input, T pre)
{
	//.....自由操作
	return stack<T>();
}

template<class T>
vector<vector<T>> DFS_ITER<T>::run(vector<T> input)
{
	if (input.size() == 0) return vector<vector<T>>();

	stack<stack<T>> dfs;
	vector<T> pre_route;
	vector<vector<T>> res;
	T pre_point;
	int pre_length = 0;    //这是一个标志某段搜索结束的标志,应按需修改,不一定是记录路径长度
	int stop_length = 10;  //结束标志,应按需修改,不一定是路径长度

	//init
	//假设input[0]是初始元素,你也可以改它
	dfs.push(find_next(input, input[0]));
	
	while (true)  //正常运行时,应该会在内部退出
	{
		if (dfs.top().empty())  //若下一节点不存在未遍历的值
		{
			if (pre_route.empty())  //循环结束标志,这表明当前路径无法回溯,而且dfs不存在未遍历到的节点了
				break;
			else  //回溯
			{
				dfs.pop();
				pre_route.pop_back();
				pre_length--;
			}
		}
		else  //若下一节点存在未遍历的值
		{
			pre_point = dfs.top().top();
			dfs.top.pop();
			pre_route.push(pre_point);
			pre_length++;
			
			if (pre_length == stop_length)   //当前路径达到终点,可以通过其他方法判断
			{
				//直接给栈添加dump,以强行手动触发下一轮循环时的回溯
				dfs.push(stack<T> {});
				//记录结果,你也可以使用其他方式,或者插入函数转换记录的路径放在此处
				res.push_back(pre_route);
			}
			else  //寻找下一元素,这里可能会空,这会自动触发下一轮循环时的回溯
			{
				dfs.push(find_next(input, pre_point));
			}
		}
	}
	return res;
}
