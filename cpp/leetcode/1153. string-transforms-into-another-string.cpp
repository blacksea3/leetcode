#include "public.h"

//
//����str1�е�������ͬ��ĸ, str2�б���Ҳ��������ͬ��ĸ
//����str1��ĸ��Ӧstr2��ĸ, �������ͼ�����л�

class Solution {
private:
	struct Node
	{
		int indegree = 0;  //���
		unordered_set<int> next;  //ֱ�ӵ���char - 'a'
		unordered_set<int> pre;   //ǰ׺��ĸ
	};


public:
	bool canConvert(string str1, string str2) {
		vector<Node*> vus(26);
		unordered_set<char> umc;

		for (int i = 0; i < 26; ++i)
		{
			Node* temp = new Node();
			vus[i] = temp;
		}

		for (int loc = 0; loc < str1.size(); ++loc)
		{
			umc.insert(str2[loc]);
			if (str1[loc] == str2[loc]) continue;

			vus[str1[loc] - 'a']->next.insert(str2[loc] - 'a');
			vus[str2[loc] - 'a']->pre.insert(str1[loc] - 'a');
		}

		//�鿴ͼ�ĺϷ���: ����һ����ĸ����ָ�򳬹�һ����ĸ

		for (int i = 0; i < 26; ++i)
		{
			if (vus[i]->next.size() >= 2) return false;
		}

		//Ȼ��ͼ�����л�
		stack<int> st;
		int num_of_removed_nodes = 0;
		for (int i = 0; i < 26; i++)
			if (vus[i]->pre.size() == 0) st.push(i);

		//��ֽڵ�
		while (!st.empty())
		{
			int prenodeid = st.top();
			st.pop();
			num_of_removed_nodes++;
			for (auto& nextnodeid : vus[prenodeid]->next)
			{
				vus[nextnodeid]->pre.erase(prenodeid);
				if (vus[nextnodeid]->pre.size() == 0)
					st.push(nextnodeid);
			}
		}

		if (umc.size() == 26) return (num_of_removed_nodes == 26);
		else return true;
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->canConvert("aabcc", "ccdee");
	return 0;
}