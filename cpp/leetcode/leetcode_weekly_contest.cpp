#include "include.h"

#ifdef LEETCODE_WC
#include "public.h"
#include "leetcode.h"

#define null NULL

vector<vector<int>> Solution::colorBorder(vector<vector<int>>& grid, int r0, int c0, int color)
{
	//只要搞清楚边界就可以咯
	//从中心点试图向外扩散,如果四个方向都是和中心点相同值,则保存此四个点接着扩散,删除中心点
	//否则:保存相同值的点然后扩散
	//对于边界点,保存相同值的点然后扩散

	//对于已经保存/删除的点,扩散时无视它,认为是相同值

	//m行n列
	int m = grid.size();
	int n = grid[0].size();

	//维护一个stack保存待扩散的点
	//维护一个res保存确认是边界的点
	//维护一个full保存内部点
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
	//看示例,似乎是先遍历右子树,然后遍历根,然后遍历左子树咯
	//每遍历一次,替换那个节点的值,用当前已经替换的节点值之和+那个节点的值替换;然后更新已经替换的节点值之和

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
			//撤回一步
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
	//如果长度是三,直接乘起来
	//否则递归去吧
	//对于以下点:    A0, A1, A2...  AN-1
	//连线A0-A2, 左半A0A1A2与右半A2,A3...AN-1,A0
	//左半A0-A3, 右半A3,A3...AN-1,A0
	//左半直到A0-A(N-2),  对应右半直到A0,AN-1,AN

	//划分起始点然后从A1开始,第二点从A3开始,终点最多到AN-1
	//搞个大递归

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

//按max调整num
//num可能>=size,此时减size
int Solution::noborder(int num, int size)
{
	return (num >= size) ? (num - size) : (num < 0) ? num + size : num;
}

int Solution::minScoreTriangulation(vector<int>& A)
{
	//动态规划
	//维护dp[start][end],:注意这个数组有一些空间没有用到
	//对end与start间隔遍历,从2至size-1;对start遍历,从0至size-1;对mid遍历,从start+1至end-1遍历
	//注意用start->mid->end三角形分割两个顶点是连续的多边形,而且这多边形的起始与终点坐标能够直接表示出来!
	//

	//最后直接用dp[0][size-1],算到最后无论从哪里开始,绕了一圈都是一个结果

	int size = A.size();

	//计算dp
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
	//题目保证存在答案
    //生成图
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
			//需要回溯
			//把上一个颜色删了,
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
	//注意到单词长度最长为16
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

	//按长度遍历单词
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
