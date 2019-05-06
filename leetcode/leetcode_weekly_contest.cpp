#include "public.h"
#include "leetcode.h"

#ifdef LEETCODE_WC

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

/*
	//����0,��Чֵ[0,max]
	int Solution::noborder_add(int add1, int add2, int max)
	{
		return ((add1 + add2) <= max) ? (add1 + add2) : (add1 + add2 - max - 1);
	}

	int Solution::minScoreTriangulation(vector<int>& A)
	{
		//��̬�滮
		//ά��dp[start][end]:��ʾ start,start+1,end�����εĳ˻�,�����endʵ�������±�end+2
		//ά��dp2[start][length]:��ʾ��start˳ʱ���һ�γ���,length:0��ʾ������4,0���ΪA.size()-4

		int maxloc = A.size() - 1;
		int size = A.size();

		//����dp
		vector<vector<int>> dp(A.size(), vector<int>(A.size() - 3));

		for (int i = 0; i <= maxloc; i++)
			for (int j = 0; j <= (maxloc - 3); j++)
				dp[i][j] = A[i] * A[noborder_add(i, 1, maxloc)] * A[j];

		//����dp2
		vector<vector<int>> dp2(A.size(), vector<int>(A.size() - 3));

		int length = -1;
		for (int i = 0; i <= maxloc; i++)
			dp2[i][0] = min((dp[i][0] + dp[noborder_add(i, (length + 2), maxloc)][size - (length + 2) - 1]), (dp[noborder_add(i, 1, maxloc)][0] + dp[i][length + 1]));

		for (int i = 1; i <= maxloc; i++)
		{
			for (int j = 0; j <= (maxloc - 3); j++)
			{
				int length = j - 1;
				dp2[i][j] = min((dp[i][length] + dp[noborder_add(i, (length + 2), maxloc)][size - (length + 2) - 1]), (dp[noborder_add(i, 1, maxloc)][j] + dp[i][length + 1]));
			}
			
		}

		return 0;
	}

*/

#else
#endif
