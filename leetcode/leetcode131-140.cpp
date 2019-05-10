#include "include.h"

#ifdef LEETCODE_131_140
#include "public.h"
#include "leetcode.h"



bool Solution::is_partition(string s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
		
	return true;
}

void Solution::iter_partition(string s)
{
	//����
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (is_partition(s.substr(0, i + 1)))
		{
			temp_131.push_back(s.substr(0, i + 1));
			iter_partition(s.substr(i + 1));
			temp_131.pop_back();
		}
	}
	//���ֻ��һ����ĸ,����һ��true,���Բ��õ��ĵݹ�������
	if (is_partition(s))
	{
		temp_131.push_back(s);
		res_131.push_back(temp_131);
		temp_131.pop_back();
	}
}

vector<vector<string>> Solution::partition(string s)
{
	//�ݹ��
	res_131.clear();
	temp_131.clear();

	iter_partition(s);
	return res_131;
}

int Solution::minCut(string s)
{
	//Ӧ��ע�⵽ ���ָ��������ʱ����Щ�����ִ��ĳ��ȶ������Ĵ������
	//����dp[i]��ʾ��i�±괦�����ٷָ���� d��ʼ��INTMAX
	//��ÿ��λ�ö�������ɢ ���ǻ��� dp��չλ��ֵ������߽���dp��һ���߲���
	int ssize = s.size();

	vector<int> dp(ssize, 0);
	for (int i = 0; i < ssize; i++)
		dp[i] = i;

	for (int i = 0; i < ssize; i++)
	{
		//�жϻ���
		int left = i;
		int right = i;
		while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
		{
			if (left == 0) dp[right] = 0;
			else dp[right] = min(dp[right], dp[left - 1] + 1);
			left--;
			right++;
		}
		left = i;
		right = i + 1;
		while ((left >= 0) && (right < ssize) && (s[left] == s[right]))
		{
			if (left == 0) dp[right] = 0;
			else dp[right] = min(dp[right], dp[left - 1] + 1);
			left--;
			right++;
		}
	}

	return dp[ssize - 1];
}

Node * Solution::cloneGraph(Node * node)
{
	//����̫��д��,���ı��˵�
	//ע����ݵ�ʱ��,��¼�Լ������˵Ľڵ���ϲ�,����ԭ�ڵ��neighboursֱ��ȫ���ù���
	//��¼���ƵĽڵ�ʱ,ֱ�Ӱ������½ڵ�׼�����(val��neighbors),Ȼ���¼
	//֮��Ҫ��ֱ����

	unordered_map<int, Node*> visited = {};                       //��¼�Լ������˵Ľڵ�
	Node *root = new Node(node->val, node->neighbors); //�����½ڵ�
	visited[node->val] = root;                            //���ƹ���
	//�����ھ�
	int size = node->neighbors.size(); //�ھӱ�Ĵ�С
	stack<Node *> M;                   //DFSջ
	M.push(root);
	while (!M.empty())
	{
		Node *top = M.top();
		size = top->neighbors.size();
		int flag = 0;//��ʶ��û��û�����ʵ��ھ�
		for (int i = 0; i < size; i++)
		{
			if (!visited[top->neighbors[i]->val])
			{
				Node *nei = new Node(top->neighbors[i]->val, top->neighbors[i]->neighbors);
				M.push(nei);
				visited[top->neighbors[i]->val] = nei;//������
				break;
			}
			else
			{
				top->neighbors[i] = visited[top->neighbors[i]->val];//�����ھ�
				flag++;
			}
		}
		if (flag == size) M.pop();//���flag����size��˵���ýڵ���ھӶ��Լ����ƹ���
	}
	return root;
}

#else
#endif
