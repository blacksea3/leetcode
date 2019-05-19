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

int Solution::rob_199(vector<int>& nums, int startloc, int endloc)
{
	//dpi:偷窃开头直到包含i下标的最大金额
//只保存最后三个dp
//init
	int nsize = endloc - startloc + 1;

	if (nsize <= 0)
		return 0;
	else if (nsize == 1)
		return nums[startloc];
	else if (nsize == 2)
		return max(nums[startloc], nums[endloc]);
	else
	{
		int dp0 = nums[startloc];
		int dp1 = nums[startloc + 1];
		int dp2 = nums[startloc] + nums[startloc + 2];
		for (int i = startloc + 3; i <= endloc; i++)
		{
			dp0 = max(dp0, dp1) + nums[i];
			int temp = dp0;
			dp0 = dp1;
			dp1 = dp2;
			dp2 = temp;
		}
		return max(dp1, dp2);
	}
}

int Solution::rob_213(vector<int>& nums)
{
	//连续两遍198题
	if (nums.size() == 0) return 0;
	else if (nums.size() == 1) return nums[0];
	else return max(rob_199(nums, 0, nums.size() - 2), rob_199(nums, 1, nums.size() - 1));
}

string Solution::shortestPalindrome(string s)
{
	//找出从最左侧开始的最长回文串

	//从s的左半段开始扩展,O(n^2),从中间开始扩展,曹
	//不采用特殊算法会超时
	//故:复用题目5

	//Manacher algorithm
	//特别注意边界问题
	//https://mp.weixin.qq.com/s?__biz=MzIzMTE1ODkyNQ==&mid=2649410225&idx=1&sn=ed045e8edc3c49a436a328e5f0f37a55&chksm=f0b60f53c7c18645b4c04a69ad314723cce94ed56994d6f963c2275a2db8d85f973f15f508e4&mpshare=1&scene=23&srcid=1001JCsBlpxgUWjgixasChNQ#rd

	string newstr = string("#");
	unsigned int iSize = s.size();
	for (unsigned int i = 0; i < iSize; i++)
	{
		newstr += s[i];
		newstr += "#";
	}

	int new_len = newstr.size();
	vector<int> radius = {};
	int right_border = -1;
	int center_index = -1;
	int longest_radius = -1;
	int longest_center_index = -1;
	for (int index = 0; index < new_len; index++)
	{
		if (index > right_border)
		{
			//expand the right border
			int L = index;
			int R = index;
			while ((L >= 0) && (R < new_len) && (newstr[L] == newstr[R]))
			{
				L--;
				R++;
			}
			int newradius = (R - L + 1) / 2;    //此处将向下取整
			radius.insert(radius.end(), newradius);
			right_border = R - 1;
			center_index = index;
			if ((L == -1) && (newradius > longest_radius))
			{
				longest_radius = newradius;
				longest_center_index = index;
			}
		}
		else if ((index + radius[2 * center_index - index] - 1) >= right_border)
		{
			//also expand the right border
			int L = 2 * index - right_border;
			int R = right_border;
			while ((L >= 0) && (R < new_len) && (newstr[L] == newstr[R]))
			{
				L--;
				R++;
			}
			int newradius = (R - L + 1) / 2;    //此处将向下取整
			radius.insert(radius.end(), newradius);
			right_border = R - 1;
			center_index = index;
			if ((L == -1) && (newradius > longest_radius))
			{
				longest_radius = newradius;
				longest_center_index = index;
			}
		}
		else radius.insert(radius.end(), radius[2 * center_index - index]);
	}

	float real_index = (longest_center_index + 1) / 2.0 - 1;  //may be xxx.5  4->1.5 2->0.5, 3->1, 1->0
	float real_radius = (longest_radius) / 2.0 - 1;         //5 ->1.5,  3->0.5  4->1, 2->0

	string res = s;
	for (int i = int(2 * real_radius + 1); i < s.size(); i++)
		res.insert(res.begin(), s[i]);
	return res;
}

int Solution::findKthLargest(vector<int>& nums, int k)
{
	//折半:快速排序

	vector<int> smallnums = {};  //这一定包含了nums[0],<=nums[0]的有效数量应当减1
	vector<int> bignums = {};

	for (auto num : nums)
	{
		if (num > nums[0])
			bignums.push_back(num);
		else
			smallnums.push_back(num);
	}
	smallnums.erase(smallnums.begin());
	if (bignums.size() == (k - 1)) return nums[0];
	else if (bignums.size() > (k - 1)) return findKthLargest(bignums, k);
	else return findKthLargest(smallnums, k - 1 - bignums.size());
}

vector<vector<int>> Solution::combinationSum3(int k, int n)
{
	//回溯
	vector<vector<int>> res = {};
	if ((k <= 0) || (k > 9)) return res;
	if (k == 1) return ((n <= 9) && (n >= 1)) ? vector<vector<int>> {vector<int> {n}} : res;

	unordered_map<int, pair<int, int>> um; //可以有解的最大值与最小值
	um[2] = pair<int, int>{ 3,17 };
	um[3] = pair<int, int>{ 6,24 };
	um[4] = pair<int, int>{ 10,30 };
	um[5] = pair<int, int>{ 15,35 };
	um[6] = pair<int, int>{ 21,39 };
	um[7] = pair<int, int>{ 28,42 };
	um[8] = pair<int, int>{ 36,44 };
	um[9] = pair<int, int>{ 45,45 };
	if ((n > um[k].second) || (n < um[k].first)) return res;
	vector<int> pre = { 1 };
	int prelen = 1;
	int presum = 1;
	bool isneedrecall = false;

	while (true)
	{
		if (!isneedrecall)
		{
			if (prelen == (k - 1))
				if (((n - presum) > 9) || ((n - presum) < 1))
				{
					isneedrecall = true;
				}
				else if (pre[pre.size() - 1] < (n - presum))
				{
					res.push_back(pre);
					res[res.size() - 1].push_back(n - presum);
					isneedrecall = true;
				}
				else
					isneedrecall = true;
			else
			{
				if (pre[pre.size() - 1] == 9)
				{
					isneedrecall = true;
				}
				else
				{
					pre.push_back(pre[pre.size() - 1] + 1);
					prelen++;
					presum += pre[pre.size() - 1];
				}
			}
		}
		else
		{
			if (pre[pre.size() - 1] == 9)
			{
				presum -= pre[pre.size() - 1];
				pre.pop_back();
				prelen--;
				if (pre.empty()) break;
			}
			else
			{
				pre[pre.size() - 1]++;
				presum++;
				isneedrecall = false;
			}
		}
	}
	return res;
}

bool Solution::containsDuplicate(vector<int>& nums)
{
	unordered_set<int> us;
	for (auto num : nums)
		if (us.find(num) == us.end())
			us.insert(num);
		else
			return true;
	return false;
}

bool Solution::complare_218(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first)
		return true;
	else if (p1.first > p2.first)
		return false;
	else
		if (p1.second <= p2.second)
			return true;
		else
			return false;
}

vector<vector<int>> Solution::getSkyline(vector<vector<int>>& buildings)
{
	//维护一个优先队列,储存最大高度
	//把buildings信息按照以下方式排序:对于[2,9,10]记作:(2,-10),(9,10)表示从2上升10与从9下降10
	//对于这些点,按照第一:pos升序、第二height升序排序(height有正有负,根据上升与下降的方向不同而不同),然后把这些点按此升序优先级遍历,如果能够调整最大高度(包括增加(上升)一个最大高度或者删除(下降)一个最大高度),那么记录当前最大高度与当前位置,否则不操作

	vector<vector<int>> res = {};
	if (buildings.size() == 0) return res;

	//使用multiset:可含重复元素的集合(保证有序)

	multiset<pair<int, int>, less<pair<int, int>>> points;   //记录位置,高度(带正负号的),升序排序,小下标的值小于大下标的
	multiset<int, greater<int>> maxheights = { 0 }; //值大的元素在小的下标处,填一个0确保这multiset不为空

	for (auto building : buildings)
	{
		points.insert(pair<int, int> {building[0], -1 * building[2]});
		points.insert(pair<int, int> {building[1], building[2]});
	}

	int hisheight = 0;
	for (auto point : points)
	{
		if (point.second < 0) //大楼起始坐标,高度上升
			maxheights.insert(-1 * point.second);
		else                 //大楼起始坐标,高度下降,不用担心erase空指针位置,因为算法决定这里一定有元素被移除
			maxheights.erase(maxheights.find(point.second));
		multiset<int, greater<int>>::iterator it = maxheights.begin();
		if (hisheight != *it)   //注:如果这里出现什么形如it无法解地址运算,那么一定是这个FUCK multiset空了
			res.push_back(vector<int> {point.first, *it});
		hisheight = *it;
	}

	return res;
}

bool Solution::containsNearbyDuplicate(vector<int>& nums, int k)
{
	unordered_map<int, int> um;
	for (int i = 0; i < nums.size(); i++)
	{
		if (um.find(nums[i]) == um.end())
			um[nums[i]] = i;
		else
			if ((i - um[nums[i]]) <= k) return true;
			else um[nums[i]] = i;
	}
	return false;
}

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{



	//维护一个vector
	//暴力求解 O(n^2)
	//这会TIE
	/*
	if (k < 1) return false;
	if (t < 0) return false;

	vector<int> q;

	for (int i = 0; i < nums.size(); i++)
	{
		for (auto val : q)
		{
			if (abs((long)val - nums[i]) <= t) return true;
		}
		if (q.size() == k)
		{
			q.erase(q.begin());
		}
		q.push_back(nums[i]);
	}
	return false;*/

	//另一种暴力求解,先按值排序,同时记录排序后的对应下标
	//O(n^2)
	if (k < 1) return false;
	if (t < 0) return false;

	vector<pair<int, int>> vp(nums.size(), pair<int, int> {});
	for (int i = 0; i < nums.size(); ++i)
		vp[i] = pair<int, int>{ nums[i],i };

	sort(vp.begin(), vp.end()); //自动按照pair<int,int> val.first升序排序

	int j = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		while ((j < i) && ((vp[j].first + t) < vp[i].first))
			j++;
		for (int m = j; m < i; m++)
			if (abs(vp[m].second - vp[i].second) <= k)
				return true;
	}
	return false;



}

#else
#endif
