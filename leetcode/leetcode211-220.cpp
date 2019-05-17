#include "include.h"

#ifdef LEETCODE_211_220
#include "public.h"
#include "leetcode.h"

int Solution::getusedir_212(vector<vector<bool>> searchde_board, int predir, int prex, int prey)
{
	if (predir == 0)
		if ((prey != 0) && (!searchde_board[prey - 1][prex])) return predir;
		else return getusedir_212(searchde_board, ++predir, prex, prey);
	else if (predir == 1)
		if ((prex != searchde_board[0].size() - 1) && (!searchde_board[prey][prex + 1])) return predir;
		else return getusedir_212(searchde_board, ++predir, prex, prey);
	else if (predir == 2)
		if ((prey != searchde_board.size() - 1) && (!searchde_board[prey + 1][prex])) return predir;
		else return getusedir_212(searchde_board, ++predir, prex, prey);
	else if (predir == 3)
		if ((prex != 0) && (!searchde_board[prey][prex - 1])) return predir;
		else return getusedir_212(searchde_board, ++predir, prex, prey);
	else
		return predir;
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words)
{
	if (words.size() == 0) return vector<string>{};
	if (board.size() == 0) return vector<string>{};
	if (board[0].size() == 0) return vector<string>{};

	Trie* allwords = new Trie();
	//超大回溯,写起来烦的一比
	//words需要生成一个字典树,使用208题的前缀树
	for (auto word : words)
		allwords->insert(word);

	vector<string> res = {};

	//DFS,遍历起始点:
	//维护一个stack,表明可以回溯的点
	stack<vector<int>> st;  //每个列表4个元素,分别是x,y,不包含下一个方向的点对应的words下标,下一个方向(0:north,1:east,2:south,3:west)

	int m = board.size();
	int n = board[0].size();
	int starty = 0;
	int startx = 0;

	//开始回溯+DFS
	//维护一个searchde_board表示已经搜索过的地方
	vector<vector<bool>> searchde_board(m, vector<bool>(n, false));
	//维护一个是否需要回溯的标记
	bool isneed_recall;
	//维护一个当前字符串以及当前字符串长度
	string prestr;
	int prelen;  //prelen这个好像没用,我先放在这里
	int prex;
	int prey;
	int predir;      //当前可用方向,在回溯中会动态变化
	bool isthislocend;

	while (true)
	{
		//vector<vector<bool>> searchde_board(m, vector<bool>(n, false));
		isneed_recall = false;
		//维护一个当前字符串以及当前字符串长度
		prestr = "";
		prelen = 0;  //prelen这个好像没用,我先放在这里
		predir = 0;      //当前可用方向,在回溯中会动态变化
		isthislocend = false;
		prex = startx;
		prey = starty;

		while (!isthislocend)
		{
			if (!isneed_recall)
			{
				//存储当前路径/字符串
				string temp = prestr + board[prey][prex];

				if (allwords->search(temp))
				{
					vector<string>::iterator iter = find(res.begin(), res.end(), temp);
					if (iter == res.end())
						res.push_back(temp);
				}

				if (allwords->startsWith(temp))  //这里必定会重复搜索一层,玛德
				{
					//记录可回溯路径(next路径)
					//获取实际可用方向
					int usedir = getusedir_212(searchde_board, predir, prex, prey);
					if (usedir <= 3)
					{
						st.push(vector<int> {prex, prey, prelen, usedir + 1});
						prelen++;
						searchde_board[prey][prex] = true;
						switch (usedir)
						{
						case 0:
						{
							prey--;
							break;
						}
						case 1:
						{
							prex++;
							break;
						}
						case 2:
						{
							prey++;
							break;
						}
						case 3:
						{
							prex--;
							break;
						}
						default:   //理论上绝对不会到这里
							break;
						}
						prestr = temp;
					}
					else isneed_recall = true;
				}
				else isneed_recall = true;
			}
			else  //回溯
			{
				//重置prex,prey,重置searchde_board,重置prestr,重置prelen
				while (true)
				{
					if (st.empty())
					{
						isthislocend = true;
						break;
					}

					vector<int> hisinfo = st.top();
					int i_prex = hisinfo[0];
					int i_prey = hisinfo[1];
					int i_predir = hisinfo[3];
					int i_usedir = getusedir_212(searchde_board, i_predir, i_prex, i_prey);
					if (i_usedir <= 3)
					{
						prex = i_prex;
						prey = i_prey;
						st.top()[3]++;
						switch (i_usedir)
						{
						case 0:
						{
							prey--;
							break;
						}
						case 1:
						{
							prex++;
							break;
						}
						case 2:
						{
							prey++;
							break;
						}
						case 3:
						{
							prex--;
							break;
						}
						default:   //理论上绝对不会到这里
							break;
						}
						isneed_recall = false;
						break;
					}
					else
					{
						searchde_board[i_prey][i_prex] = false;
						prestr.pop_back();
						prelen--;
						st.pop();
					}
				}
			}
		}

		//一轮搜索结束了
		if (startx == n - 1)
		{
			if (starty == m - 1)
				break;
			else
			{
				starty++;
				startx = 0;
			}
		}
		else startx++;
	}

	return res;
}

#else
#endif
