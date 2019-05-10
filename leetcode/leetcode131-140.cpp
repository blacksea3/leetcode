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
	//暴力
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (is_partition(s.substr(0, i + 1)))
		{
			temp_131.push_back(s.substr(0, i + 1));
			iter_partition(s.substr(i + 1));
			temp_131.pop_back();
		}
	}
	//如果只有一个字母,这里一定true,所以不用担心递归结果混乱
	if (is_partition(s))
	{
		temp_131.push_back(s);
		res_131.push_back(temp_131);
		temp_131.pop_back();
	}
}

vector<vector<string>> Solution::partition(string s)
{
	//递归吧
	res_131.clear();
	temp_131.clear();

	iter_partition(s);
	return res_131;
}

int Solution::minCut(string s)
{
	//应当注意到 当分割次数最少时，这些回文字串的长度对于中心处是最长的
	//设置dp[i]表示第i下标处的最少分割次数 d初始化INTMAX
	//从每个位置都往外扩散 若是回文 dp扩展位置值等于左边界外dp加一或者不变
	int ssize = s.size();

	vector<int> dp(ssize, 0);
	for (int i = 0; i < ssize; i++)
		dp[i] = i;

	for (int i = 0; i < ssize; i++)
	{
		//判断回文
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
	//回溯太难写了,抄的别人的
	//注意回溯的时候,记录以及复制了的节点请合并,对于原节点的neighbours直接全部拿过来
	//记录复制的节点时,直接把整个新节点准备完毕(val与neighbors),然后记录
	//之后要用直接用

	unordered_map<int, Node*> visited = {};                       //记录以及复制了的节点
	Node *root = new Node(node->val, node->neighbors); //创建新节点
	visited[node->val] = root;                            //复制过了
	//拷贝邻居
	int size = node->neighbors.size(); //邻居表的大小
	stack<Node *> M;                   //DFS栈
	M.push(root);
	while (!M.empty())
	{
		Node *top = M.top();
		size = top->neighbors.size();
		int flag = 0;//标识有没有没被访问的邻居
		for (int i = 0; i < size; i++)
		{
			if (!visited[top->neighbors[i]->val])
			{
				Node *nei = new Node(top->neighbors[i]->val, top->neighbors[i]->neighbors);
				M.push(nei);
				visited[top->neighbors[i]->val] = nei;//访问了
				break;
			}
			else
			{
				top->neighbors[i] = visited[top->neighbors[i]->val];//更新邻居
				flag++;
			}
		}
		if (flag == size) M.pop();//如果flag等于size，说明该节点的邻居都以及复制过了
	}
	return root;
}

#else
#endif
