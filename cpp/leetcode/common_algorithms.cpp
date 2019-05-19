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

//��������Ԫ��,���ݵ�ǰԪ��,Ѱ��һЩ���ϵ�Ԫ��
//inputҲ������һ�����ĸ��ڵ�,Ӧ�ð����޸�
template<class T>
stack<T> DFS_ITER<T>::find_next(vector<T> input, T pre)
{
	//.....���ɲ���
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
	int pre_length = 0;    //����һ����־ĳ�����������ı�־,Ӧ�����޸�,��һ���Ǽ�¼·������
	int stop_length = 10;  //������־,Ӧ�����޸�,��һ����·������

	//init
	//����input[0]�ǳ�ʼԪ��,��Ҳ���Ը���
	dfs.push(find_next(input, input[0]));
	
	while (true)  //��������ʱ,Ӧ�û����ڲ��˳�
	{
		if (dfs.top().empty())  //����һ�ڵ㲻����δ������ֵ
		{
			if (pre_route.empty())  //ѭ��������־,�������ǰ·���޷�����,����dfs������δ�������Ľڵ���
				break;
			else  //����
			{
				dfs.pop();
				pre_route.pop_back();
				pre_length--;
			}
		}
		else  //����һ�ڵ����δ������ֵ
		{
			pre_point = dfs.top().top();
			dfs.top.pop();
			pre_route.push(pre_point);
			pre_length++;
			
			if (pre_length == stop_length)   //��ǰ·���ﵽ�յ�,����ͨ�����������ж�
			{
				//ֱ�Ӹ�ջ���dump,��ǿ���ֶ�������һ��ѭ��ʱ�Ļ���
				dfs.push(stack<T> {});
				//��¼���,��Ҳ����ʹ��������ʽ,���߲��뺯��ת����¼��·�����ڴ˴�
				res.push_back(pre_route);
			}
			else  //Ѱ����һԪ��,������ܻ��,����Զ�������һ��ѭ��ʱ�Ļ���
			{
				dfs.push(find_next(input, pre_point));
			}
		}
	}
	return res;
}
