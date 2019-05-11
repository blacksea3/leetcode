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

Node_133 * Solution::cloneGraph(Node_133 * node)
{
	//回溯太难写了,抄的别人的
	//注意回溯的时候,记录以及复制了的节点请合并,对于原节点的neighbours直接全部拿过来
	//记录复制的节点时,直接把整个新节点准备完毕(val与neighbors),然后记录
	//之后要用直接用

	unordered_map<int, Node_133*> visited = {};                       //记录以及复制了的节点
	Node_133 *root = new Node_133(node->val, node->neighbors); //创建新节点
	visited[node->val] = root;                            //复制过了
	//拷贝邻居
	int size = node->neighbors.size(); //邻居表的大小
	stack<Node_133 *> M;                   //DFS栈
	M.push(root);
	while (!M.empty())
	{
		Node_133 *top = M.top();
		size = top->neighbors.size();
		int flag = 0;//标识有没有没被访问的邻居
		for (int i = 0; i < size; i++)
		{
			if (!visited[top->neighbors[i]->val])
			{
				Node_133 *nei = new Node_133(top->neighbors[i]->val, top->neighbors[i]->neighbors);
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

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	//开始行驶,如果某段路在结尾处油变成负的了,则重启起始点,记住之前负的值(可以与在之前的负的值叠加)
	//这是因为如果起始点在那段中间的话,由于那段路没到结尾油是正的，则后面一块油负的更厉害，无需考虑。
	//如果开到最后了,把多余的油与前面的总计负的值比较,结果很明显的
	int pre_init = 0;
	int pre_nagative_res = 0;
	int startloc = 0;

	for (int i = 0; i < gas.size(); i++)
	{
		pre_init += gas[i] - cost[i];
		if (pre_init < 0)
		{
			pre_nagative_res += pre_init;
			pre_init = 0;
			startloc = (i + 1);
		}
	}

	return ((pre_init + pre_nagative_res) >= 0) ? startloc : -1;
}

int Solution::candy(vector<int>& ratings)
{
	//全部初始化成1
	//先正向遍历,对当前评分大于前一个,给当前赋比前一个+1
	//后反序遍历,对当前评分大于后一个,如果当前值比后一个小或等于,那么修改当前值至比后一个+1,这不会影响第一轮遍历设置的(当前评分大于前一个,给当前赋比前一个+1,因为顶多变成当前赋值比前一个大的多)

	vector<int> candies(ratings.size(), 1);
	for (int i = 1; i < ratings.size(); i++)
		if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;

	for (int i = ratings.size() - 2; i >= 0; i--)
		if (ratings[i] > ratings[i + 1])
			if (candies[i] <= candies[i + 1])
				candies[i] = candies[i + 1] + 1;

	int sum = 0;
	for (auto icandy : candies)
		sum += icandy;
	return sum;
}

int Solution::singleNumber(vector<int>& nums)
{
	//异或

	int i = 0;
	for (auto num : nums)
		i ^= num;
	return i;
}

int Solution::singleNumber_137(vector<int>& nums)
{
	//应该想出一个操作:使得连续三次操作后为0

	//对于两个1bit数:(a,b)    0  0  ->   0  1 ->  1  0  -> 0   0
	//input 1:

	//b = (b^i) & ~a = 0^1 & 1 = 1   //单个数字取b
	//a = (a^i) & ~b = 0^1 & 0 = 0

	//b = (b^i) & ~a = 1^1 & 1 = 0
	//a = (a^i) & ~b = 0^1 & 1 = 1   //两个数字取a

	//b = (b^i) & ~a = 0^1 & 0 = 0
	//a = (a^i) & ~b = 1^1 & 1 = 0

	//input 0

	//b = (b^i) & ~a = 0^0 & 1 = 0
	//a = (a^i) & ~b = 0^0 & 1 = 0
	//连着三遍

	int a = 0;
	int b = 0;
	for (auto num : nums)
	{
		b = (b ^ num) & ~a;
		a = (a ^ num) & ~b;
	}
	return b;
}

Node * Solution::copyRandomList(Node * head)
{
	if (head == nullptr) return nullptr;

	Node* pre = head;

	//第一轮复制,给每个节点复制到自己的后面
	while (pre != nullptr)
	{
		Node* newn = new Node(pre->val, pre->next, nullptr);
		pre->next = newn;
		pre = newn->next;
	}

	//第二轮复制,查找每个原始节点(认为是奇数节点),得出random,然后把复制节点(认为是偶数节点)的random指向原始节点random的后面(就是一个random复制节点)
	pre = head;
	while (pre != nullptr)
	{
		if (pre->random)
			pre->next->random = pre->random->next;
		pre = pre->next->next;
	}

	//第三轮,拆出复制节点

	Node* returnhead = head->next;
	pre = returnhead;
	while (pre->next != nullptr)
	{
		pre->next = pre->next->next;
	}

	return returnhead;
}

bool Solution::wordBreak_139(string s, vector<string>& wordDict)
{
	//类似回溯的动态规划

	//dp[i]:  0<=i<s.size()  表示s的第一个至第i下标单词可以被形成

	vector<bool> dp(s.size(), false);
	unordered_set<string> wordd(wordDict.begin(), wordDict.end());

	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j <= i; j++)
		{
			if (((j == 0) || dp[j - 1]) && (wordd.find(s.substr(j, i - j + 1)) !=  wordd.end()) )
			{
				dp[i] = true;
				break;
			}
		}

	return dp[s.size() - 1];

}

string Solution::generate_space_sentense(const vector<string>& input)
{
	string s = input[0];
	for (int i = 1; i < input.size(); i++)
	{
		s += " ";
		s += input[i];
	}
	return s;
}

vector<string> Solution::wordBreak_140(string s, vector<string>& wordDict)
{
	//先复用139题,如果可以则回溯
	if (!wordBreak_139(s, wordDict)) return vector<string>{};

	unordered_set<string> wordd(wordDict.begin(), wordDict.end());

	int minlen = INT_MAX;
	int maxlen = 0;
	int maxloc_p1 = s.size();

	for (auto word : wordd)
	{
		minlen = min(minlen, (int)word.size());
		maxlen = max(maxlen, (int)word.size());
	}

	//回溯,dfs
	stack<stack<string>> dfs;
	vector<string> pre = {};
	vector<string> res = {};

	//init
	int loc = 0;
	stack<string> temp = {};
	for (int i = minlen - 1; i < min(maxlen, maxloc_p1); i++)
	{
		if (wordd.find(s.substr(0, i + 1)) != wordd.end()) temp.push(s.substr(0, i + 1));
	}
	dfs.push(temp);

	while (true)
	{
		//取出,注意外部已确保取出的是合法值
		if (dfs.top().empty())
		{
			dfs.pop();
			if (pre.size() == 0) break;
			string oldstr = pre[pre.size() - 1];
			pre.pop_back();
			loc -= oldstr.size();
		}
		else
		{
			string prestr = dfs.top().top();
			dfs.top().pop();
			pre.push_back(prestr);
			loc += prestr.size();
			//寻找下面有咩有
			if (loc == maxloc_p1)
			{
				//生成一个输出
				res.push_back(generate_space_sentense(pre));
				//回退一级
				pre.pop_back();
				loc -= prestr.size();
			}
			else
			{
				stack<string> temp = {};
				for (int i = loc + (minlen - 1); i < min(loc + maxlen, maxloc_p1); i++)
				{
					
					if (wordd.find(s.substr(loc, i - loc + 1)) != wordd.end())
						temp.push(s.substr(loc, i - loc + 1));
				}
				dfs.push(temp);
				//接着来,即使temp是空的也不要紧的
			}
		}
	}

	// str, loc = 3

	return res;
}

#else
#endif
