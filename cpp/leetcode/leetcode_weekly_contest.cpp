#include "include.h"

#ifdef LEETCODE_WC
#include "public.h"
#include "leetcode.h"

#define null NULL

vector<vector<int>> Solution::colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
{
	//ֻҪ������߽�Ϳ��Կ�
	//�����ĵ���ͼ������ɢ,����ĸ������Ǻ����ĵ���ֵͬ,�򱣴���ĸ��������ɢ,ɾ�����ĵ�
	//����:������ֵͬ�ĵ�Ȼ����ɢ
	//���ڱ߽��,������ֵͬ�ĵ�Ȼ����ɢ

	//�����Ѿ�����/ɾ���ĵ�,��ɢʱ������,��Ϊ����ֵͬ

	//m��n��
	int m = grid.size();
	int n = grid[0].size();

	//ά��һ��stack�������ɢ�ĵ�
	//ά��һ��res����ȷ���Ǳ߽�ĵ�
	//ά��һ��full�����ڲ���
	int findcolor = grid[r0][c0];
	vector<pair<int, int>> stack = { pair<int,int>(r0,c0) };
	vector<pair<int, int>> res = {};
	vector<pair<int, int>> full = {};

	while (stack.size() > 0)
	{
		int same_time = 0;
		pair<int, int> pre_loc = stack[stack.size()-1];
		stack.pop_back();

		if ((pre_loc.first != 0) && (grid[pre_loc.first - 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first - 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first - 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.first != (m - 1)) && (grid[pre_loc.first + 1][pre_loc.second] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first + 1, pre_loc.second)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first + 1, pre_loc.second));
			}
			same_time++;
		}
		if ((pre_loc.second != 0) && (grid[pre_loc.first][pre_loc.second - 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second - 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second - 1));
			}
			same_time++;
		}
		if ((pre_loc.second != (n - 1)) && (grid[pre_loc.first][pre_loc.second + 1] == findcolor))
		{
			if ((find(res.begin(), res.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == res.end()) &&
				(find(full.begin(), full.end(), pair<int, int>(pre_loc.first, pre_loc.second + 1)) == full.end()))
			{
				stack.push_back(pair<int, int>(pre_loc.first, pre_loc.second + 1));
			}
			same_time++;
		}

		if (same_time == 4) full.push_back(pre_loc);
		else res.push_back(pre_loc);
	}

	for (int i = 0; i < res.size(); i++)
	{
		grid[res[i].first][res[i].second] = color;
	}
	return grid;
}

TreeNode* Solution::bstToGst(TreeNode* root)
{
	//��ʾ��,�ƺ����ȱ���������,Ȼ�������,Ȼ�������������
	//ÿ����һ��,�滻�Ǹ��ڵ��ֵ,�õ�ǰ�Ѿ��滻�Ľڵ�ֵ֮��+�Ǹ��ڵ��ֵ�滻;Ȼ������Ѿ��滻�Ľڵ�ֵ֮��

	int pre_sum = 0;
	vector<TreeNode*> stack = {};
	TreeNode *rootbak = root;
	TreeNode *pre = root;
	while ((pre != nullptr) || !stack.empty())
	{
		if (pre != nullptr)
		{
			stack.push_back(pre);
			pre = pre->right;
		}
		else
		{
			//����һ��
			pre = stack[stack.size() - 1];
			stack.pop_back();
			pre->val += pre_sum;
			pre_sum = pre->val;
			pre = pre->left;
		}
	}
	return rootbak;
}

/*
int Solution::iter_minScoreTriangulation(vector<int>& A)
{
	//�����������,ֱ�ӳ�����
	//����ݹ�ȥ��
	//�������µ�:    A0, A1, A2...  AN-1
	//����A0-A2, ���A0A1A2���Ұ�A2,A3...AN-1,A0
	//���A0-A3, �Ұ�A3,A3...AN-1,A0
	//���ֱ��A0-A(N-2),  ��Ӧ�Ұ�ֱ��A0,AN-1,AN

	//������ʼ��Ȼ���A1��ʼ,�ڶ����A3��ʼ,�յ���ൽAN-1
	//�����ݹ�

	if (A.size() == 3) return A[0] * A[1] * A[2];

	int minres = INT_MAX;

	int res1 = 0;
	int res2 = 0;

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 2; j < A.size(); j++)
		{
			if ((i == 0) && (j == A.size() - 1)) continue;
			vector<int> left = {};
			for (int k = i; k <= j; k++)
				left.push_back(A[k]);
			res1 = iter_minScoreTriangulation(left);
			

			vector<int> right = {};
			for (int k = j; k < A.size(); k++)
				right.push_back(A[k]);
			for (int k = 0; k <= i; k++)
				right.push_back(A[k]);
			res2 = iter_minScoreTriangulation(right);
			minres = min(minres, (res1 + res2));
		}
	}
	return minres;
}

int Solution::minScoreTriangulation(vector<int>& A)
{
	return iter_minScoreTriangulation(A);
}
*/

//��max����num
//num����>=size,��ʱ��size
int Solution::noborder(int num, int size)
{
	return (num >= size) ? (num - size) : (num < 0) ? num + size : num;
}

int Solution::minScoreTriangulation(vector<int>& A)
{
	//��̬�滮
	//ά��dp[start][end],:ע�����������һЩ�ռ�û���õ�
	//��end��start�������,��2��size-1;��start����,��0��size-1;��mid����,��start+1��end-1����
	//ע����start->mid->end�����ηָ����������������Ķ����,���������ε���ʼ���յ������ܹ�ֱ�ӱ�ʾ����!
	//

	//���ֱ����dp[0][size-1],�㵽������۴����￪ʼ,����һȦ����һ�����

	int size = A.size();

	//����dp
	vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));

	for (int diff = 2; diff < A.size(); ++diff)
		for (int start = 0; start < A.size(); ++start)
		{
			int end = noborder(start + diff, size);
			int mul = A[start] * A[end];
			dp[start][end] = INT_MAX;
			for (int mid = noborder(start + 1, size); mid != end; mid = noborder(mid + 1, size))
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid][end] + mul * A[mid]);
		}

	return dp[0][size - 1];
}

vector<int> Solution::gardenNoAdj(int N, vector<vector<int>>& paths)
{
	//��Ŀ��֤���ڴ�
    //����ͼ
	struct node { int id; int color; vector<int> links; vector<int> badcolors; };
	vector<node> gardens;
	node dump = node();
	gardens.push_back(dump);

	for (int i = 1; i <= N; i++)
	{
		node temp = node();
		temp.id = i;
		temp.color = 0;
		gardens.push_back(temp);
	}

	for (auto path : paths)
	{
		gardens[path[0]].links.push_back(path[1]);
		gardens[path[1]].links.push_back(path[0]);
	}
	
	stack<int> finished = {};
	stack<int> dfs = {};
	dfs.push(1);  //
	while (true)
	{
		int nodeid = dfs.top();
		dfs.pop();
		vector<int> totalcolors = { 1,2,3,4 };
		vector<int> precolors = {};
		int nextcolor = 0;
		for (auto gardenid : gardens[nodeid].links)
			precolors.push_back(gardens[gardenid].color);

		for (int i = 0; i < totalcolors.size(); i++)
		{
			if (std::find(precolors.begin(), precolors.end(), totalcolors[i]) == precolors.end())
				if (std::find(gardens[nodeid].badcolors.begin(), gardens[nodeid].badcolors.end(), totalcolors[i]) == gardens[nodeid].badcolors.end())
				{
					nextcolor = totalcolors[i];
					break;
				}
		}
		if (nextcolor != 0)
		{
			gardens[nodeid].color = nextcolor;
			finished.push(nodeid);
			if (finished.size() == N) goto end;
			dfs.push(nodeid + 1);
		}
		else
		{
			//��Ҫ����
			//����һ����ɫɾ��,
			int preid = finished.top();
			gardens[preid].badcolors.push_back(gardens[preid].color);
			gardens[preid].color = 0;
			finished.pop();
			dfs.push(preid);
		}
	}
end:
	vector<int> res = {};

	for (int i = 1; i <= N; i++)
		res.push_back(gardens[i].color);

	return res;
}

int Solution::iter_lastStoneWeight(vector<int>& stones)
{
	return 0;
}

int Solution::lastStoneWeight(vector<int>& stones)
{
	multiset<int> ml;
	for (auto stone:stones)
	{
		ml.insert(stone);
	}
	while (ml.size() >= 2)
	{
		int s1 = *ml.rbegin();
		ml.erase(ml.find(s1));
		int s2 = *(ml.rbegin());
		ml.erase(ml.find(s2));
		if (s1 != s2)
		{
			ml.insert(s1 - s2);
		}
	}
	return (ml.size() == 1) ? *ml.begin() : 0;
}

bool Solution::isfront_body(string word1, string word2)
{
	int i = 0;
	int j = 0;
	while ((i < word1.size()) && (word1[i] == word2[j]))
	{
		i++;
		j++;
	}
	if (i == word1.size()) return true;
	j++;
	while ((j < word2.size()) && (word1[i] == word2[j]))
	{
		i++;
		j++;
	}
	if (j == word2.size()) return true;
	else return false;
}

int Solution::longestStrChain(vector<string>& words)
{
	//ע�⵽���ʳ����Ϊ16
	vector<vector<pair<string, int>>> v(16, vector<pair<string, int>>{});

	for (auto word : words)
		v[word.size() - 1].push_back(pair<string, int>{word, 1});

	int may_maxlen = 1;
	int maxlen = 1;

	int temp = 0;
	for (auto iter_v : v)
	{
		if (iter_v.empty())
		{
			may_maxlen = max(may_maxlen, temp);
			temp = 0;
		}
		else temp++;
	}
	may_maxlen = max(may_maxlen, temp);

	//�����ȱ�������
	for (int i = 1; i < 16; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			pair<string, int> pair_bigword = v[i][j];
			for (int k = 0; k < v[i - 1].size(); k++)
			{
				pair<string, int> pair_smallword = v[i - 1][k];
				if (isfront_body(pair_smallword.first, pair_bigword.first))
				{
					v[i][j].second = max(v[i][j].second, pair_smallword.second + 1);
					maxlen = max(maxlen, v[i][j].second);
					if (maxlen == may_maxlen) return may_maxlen;
				}
			}
		}
	}
	return maxlen;
}

string Solution::removeDuplicates(string S) {
	int left = 0;
	if (S.size() <= 1) return S;

	while ((left + 1) < S.size())
	{
		if (S[left] == S[left + 1])
		{
			S.erase(S.begin() + left);
			S.erase(S.begin() + left);
			if (left != 0) left--;
		}
		else
			left++;
	}
	return S;
}

#else
#endif

//#############################################################################################
//#############################################################################################
//#############################################################################################
//#############################################################################################
//#############################################################################################

#ifdef LEETCODE_WC
void testwc1(Solution s)
{
	vector<vector<int>> grid = { {1,1},{1,2} };
	vector<vector<int>> res = s.colorBorder(grid, 0, 0, 3);
	int i = 1;
}


void testwc_135_2(Solution s)
{
	TreeNode *root = s.initTreeNode({ 4,1,6,0,2,5,7,null,null,null,3,null,null,null,8 });
	TreeNode* res = s.bstToGst(root);
	int i = 1;
}

void testwc_135_3(Solution s)
{
	vector<int> A = { 1,2,8,5,3,6,7,6,2 };
	cout << s.minScoreTriangulation(A);
}

void testwc_136_2(Solution s)
{
	int N = 3;
	vector<vector<int>> paths = { {1,2},{2,3},{3,1} };
	vector<int> res = s.gardenNoAdj(N, paths);
	int i = 1;
}

#else
#endif
