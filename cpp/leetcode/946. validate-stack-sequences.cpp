#include "public.h"

//12ms, 85.16%
//ģ��:
//�������²���: ���ջ�ǿյĻ���ջ��������popped�ĵ�ǰֵ, ��ôpush(Ҫ����ʱ��pushed���˾ͷ���false)
//����pop, ���pop����, popped�����򷵻�true

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;

		int pushloc = 0;
		int poploc = 0;

		while (poploc < popped.size())
		{
			if (st.empty() || st.top() != popped[poploc])
			{
				if (pushloc >= pushed.size()) return false;
				else
				{
					st.push(pushed[pushloc++]);
				}
			}
			else
			{
				st.pop();
				poploc++;
			}
		}
		return true;
	}
};
