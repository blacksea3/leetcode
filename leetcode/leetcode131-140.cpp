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

Node_133 * Solution::cloneGraph(Node_133 * node)
{
	//����̫��д��,���ı��˵�
	//ע����ݵ�ʱ��,��¼�Լ������˵Ľڵ���ϲ�,����ԭ�ڵ��neighboursֱ��ȫ���ù���
	//��¼���ƵĽڵ�ʱ,ֱ�Ӱ������½ڵ�׼�����(val��neighbors),Ȼ���¼
	//֮��Ҫ��ֱ����

	unordered_map<int, Node_133*> visited = {};                       //��¼�Լ������˵Ľڵ�
	Node_133 *root = new Node_133(node->val, node->neighbors); //�����½ڵ�
	visited[node->val] = root;                            //���ƹ���
	//�����ھ�
	int size = node->neighbors.size(); //�ھӱ�Ĵ�С
	stack<Node_133 *> M;                   //DFSջ
	M.push(root);
	while (!M.empty())
	{
		Node_133 *top = M.top();
		size = top->neighbors.size();
		int flag = 0;//��ʶ��û��û�����ʵ��ھ�
		for (int i = 0; i < size; i++)
		{
			if (!visited[top->neighbors[i]->val])
			{
				Node_133 *nei = new Node_133(top->neighbors[i]->val, top->neighbors[i]->neighbors);
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

int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
	//��ʼ��ʻ,���ĳ��·�ڽ�β���ͱ�ɸ�����,��������ʼ��,��ס֮ǰ����ֵ(��������֮ǰ�ĸ���ֵ����)
	//������Ϊ�����ʼ�����Ƕ��м�Ļ�,�����Ƕ�·û����β�������ģ������һ���͸��ĸ����������迼�ǡ�
	//������������,�Ѷ��������ǰ����ܼƸ���ֵ�Ƚ�,��������Ե�
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
	//ȫ����ʼ����1
	//���������,�Ե�ǰ���ִ���ǰһ��,����ǰ����ǰһ��+1
	//�������,�Ե�ǰ���ִ��ں�һ��,�����ǰֵ�Ⱥ�һ��С�����,��ô�޸ĵ�ǰֵ���Ⱥ�һ��+1,�ⲻ��Ӱ���һ�ֱ������õ�(��ǰ���ִ���ǰһ��,����ǰ����ǰһ��+1,��Ϊ�����ɵ�ǰ��ֵ��ǰһ����Ķ�)

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
	//���

	int i = 0;
	for (auto num : nums)
		i ^= num;
	return i;
}

int Solution::singleNumber_137(vector<int>& nums)
{
	//Ӧ�����һ������:ʹ���������β�����Ϊ0

	//��������1bit��:(a,b)    0  0  ->   0  1 ->  1  0  -> 0   0
	//input 1:

	//b = (b^i) & ~a = 0^1 & 1 = 1   //��������ȡb
	//a = (a^i) & ~b = 0^1 & 0 = 0

	//b = (b^i) & ~a = 1^1 & 1 = 0
	//a = (a^i) & ~b = 0^1 & 1 = 1   //��������ȡa

	//b = (b^i) & ~a = 0^1 & 0 = 0
	//a = (a^i) & ~b = 1^1 & 1 = 0

	//input 0

	//b = (b^i) & ~a = 0^0 & 1 = 0
	//a = (a^i) & ~b = 0^0 & 1 = 0
	//��������

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

	//��һ�ָ���,��ÿ���ڵ㸴�Ƶ��Լ��ĺ���
	while (pre != nullptr)
	{
		Node* newn = new Node(pre->val, pre->next, nullptr);
		pre->next = newn;
		pre = newn->next;
	}

	//�ڶ��ָ���,����ÿ��ԭʼ�ڵ�(��Ϊ�������ڵ�),�ó�random,Ȼ��Ѹ��ƽڵ�(��Ϊ��ż���ڵ�)��randomָ��ԭʼ�ڵ�random�ĺ���(����һ��random���ƽڵ�)
	pre = head;
	while (pre != nullptr)
	{
		if (pre->random)
			pre->next->random = pre->random->next;
		pre = pre->next->next;
	}

	//������,������ƽڵ�

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
	//���ƻ��ݵĶ�̬�滮

	//dp[i]:  0<=i<s.size()  ��ʾs�ĵ�һ������i�±굥�ʿ��Ա��γ�

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
	//�ȸ���139��,������������
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

	//����,dfs
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
		//ȡ��,ע���ⲿ��ȷ��ȡ�����ǺϷ�ֵ
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
			//Ѱ������������
			if (loc == maxloc_p1)
			{
				//����һ�����
				res.push_back(generate_space_sentense(pre));
				//����һ��
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
				//������,��ʹtemp�ǿյ�Ҳ��Ҫ����
			}
		}
	}

	// str, loc = 3

	return res;
}

#else
#endif
