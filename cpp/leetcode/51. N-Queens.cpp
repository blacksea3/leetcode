#include "public.h"

/*
//16ms, 61.64%
//回溯法, 先生成位置再生成结果字符串数组

class Solution {
private:
	vector<vector<string>> total_res = {};
	vector<string> rawstr;
	void generate_Queens_string(vector<int> input, int n)
	{
		vector<string> returnstr = rawstr;
		for (int i = 0; i < n; i++) returnstr[i][input[i]] = 'Q';
		total_res.emplace_back(returnstr);
	}

	void DFS(vector<int>& input, int n)
	{
		int isize = input.size();
		//去掉相同列和±45°列
		for (int x = 0; x < n; x++)
		{
			for (int i = 0; i < isize; i++)
			{
				if (x == input[i]) goto xcontinue;
				if (x == (input[i] - (isize - i))) goto xcontinue;
				if (x == (input[i] + (isize - i))) goto xcontinue;
			}
			input.push_back(x);
			if (isize == (n - 1)) generate_Queens_string(input, n);
			else DFS(input, n);
			input.pop_back();
		xcontinue: continue;
		}
	}

public:
	vector<vector<string>> solveNQueens(int n)
	{
		rawstr.resize(n);
		string dumpstr(n, '.');
		for (int index = 0; index < n; ++index)
			rawstr[index] = dumpstr;

		vector<int> input;
		DFS(input, n);
		return total_res;
	}
};
*/

//12ms, 82.63%
//回溯法, 直接拿着字符串操作, 初始字符串数组全是.

class Solution {
private:
	vector<vector<string>> total_res = {};
	vector<string> preStr;
	int gblN;

	bool isValid(int r, int c)
	{
		for (int oldr = 0; oldr < r; oldr++)
		{
			if (preStr[oldr][c] == 'Q') return false;
		}
		for (int oldr = r, oldc = c; oldr >= 0 && oldc >= 0; oldr--, oldc--)
		{
			if (preStr[oldr][oldc] == 'Q') return false;
		}
		for (int oldr = r, oldc = c; oldr >= 0 && oldc < gblN; oldr--, oldc++)
		{
			if (preStr[oldr][oldc] == 'Q') return false;
		}
		return true;
	}

	void DFS(int r)
	{
		//结束
		if (r == gblN)
		{
			total_res.push_back(preStr);
			return;
		}

		//去掉相同列和±45°列
		for (int c = 0; c < gblN; c++)
		{
			if (isValid(r, c))
			{
				preStr[r][c] = 'Q';
				DFS(r + 1);
				preStr[r][c] = '.';
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int n)
	{
		string dumpstr(n, '.');
		for (int i = 0; i < n; ++i) preStr.emplace_back(dumpstr);
		gblN = n;
		DFS(0);
		return total_res;
	}
};
