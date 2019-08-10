#include "public.h"

//
//对于str1中的连续相同字母, str2中必须也是连续相同字母
//建立str1字母对应str2字母, 这个有向图不能有环

class Solution {
private:
	struct Node
	{
		int indegree = 0;  //入度
		unordered_set<int> next;  //直接等于char - 'a'
		unordered_set<int> pre;   //前缀字母
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

		//查看图的合法性: 首先一个字母不能指向超过一个字母

		for (int i = 0; i < 26; ++i)
		{
			if (vus[i]->next.size() >= 2) return false;
		}

		//然后图不能有环
		stack<int> st;
		int num_of_removed_nodes = 0;
		for (int i = 0; i < 26; i++)
			if (vus[i]->pre.size() == 0) st.push(i);

		//拆分节点
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