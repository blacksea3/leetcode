#include "public.h"

//28ms, 86.67%
//init: 撤去多个完整的stamp, 改成?, 这将剩下大量的间断部分, 存入vector<vector<int,int>> v
//接下来:对v内元素这样操作: 对每个元素的左边和stamp的右边求重叠部分, 并且去掉重叠部分; 对每个元素的右边和stamp的左边求重叠部分, 并且去掉重叠部分
//如果元素彻底去掉了, 那么删掉它, 否则元素一定缩短, 这里有个特殊情况: 如果元素长度<stamp并且是v的中间某一段, 那么也能去掉
//刚开始无法撤去完整的stamp或者v内某个元素左右都没法和v重叠, 那么不能印出序列
//实际的顺序和这里的撤的顺序是反的

class Solution {
private:
	//判断target[begin:end+1] 是不是stamp的子串, 是则返回起始位置, 不是则返回-1
	//maxsleft是左边最多留多少, maxsright是右边最多留多少
	int issubstr(const string& target, int begin, int end, string stamp, int maxsleft, int maxsright)
	{
		int len = end - begin + 1;
		string s = target.substr(begin, len);
		for (int i = max(0, (int)stamp.size() - maxsright - 1); i <= stamp.size() - len; ++i)
		{
			if (i > maxsleft) break;
			if (stamp.substr(i, len) == s) return i;
		}
		return -1;
	}
	//看每个元素的左边和stamp的右边求重叠部分, 返回公共长度
	int overlap_tleft_sright(const string& target, int begin, int end, string stamp)
	{
		int lenm1 = min((int)stamp.size() - 1, end - begin + 1) - 1;
		int ssize = stamp.size();
		for (int i = lenm1; i >= 0; --i)
		{
			string t = target.substr(begin, i + 1);
			string s = stamp.substr(ssize - i - 1, i + 1);
			if (target.substr(begin, i + 1) == stamp.substr(ssize - i - 1, i + 1)) return i + 1;
		}
		return 0;
	}

	//看每个元素的右边和stamp的左边求重叠部分, 返回公共长度
	int overlap_tright_sleft(const string& target, int begin, int end, string stamp)
	{
		int lenm1 = min((int)stamp.size() - 1, end - begin + 1) - 1;
		for (int i = lenm1; i >= 0; --i)
		{
			string t = target.substr(end - i, i + 1);
			string s = stamp.substr(0, i + 1);
			if (target.substr(end - i, i + 1) == stamp.substr(0, i + 1)) return i+1;
		}
		return 0;
	}

public:
	vector<int> movesToStamp(string stamp, string target) {
		//初始化
		//暴力
		int lastright = -1;
		vector<int> res;

		vector<vector<int>> v;
		bool notgood = true;
		for (int i = 0; i <= target.size() - stamp.size();)
		{
			if (target.substr(i, stamp.size()) == stamp)
			{
				res.push_back(i);
				notgood = false;
				//拆分
				if (i > lastright + 1)
				{
					v.push_back({ lastright + 1, i - 1 });
				}
				lastright = i + stamp.size() - 1;
				i += stamp.size();
			}
			else i++;
		}
		if (notgood) return {}; //强制退出

		if (target.size() > lastright + 1) v.push_back({ lastright + 1, (int)target.size() - 1 });

		//接下来操作v
		while (!v.empty())
		{
			vector<vector<int>> next;
			//查找完整子串
			for (auto& iv : v)
			{
				if ((iv[1] - iv[0] + 1) < stamp.size())
				{
					int tempres = issubstr(target, iv[0], iv[1], stamp, iv[0], target.size() - iv[1] - 1);
					if (tempres != -1)
					{
						res.push_back(iv[0] - tempres);
					}
					else
					{
						next.push_back({ iv[0],iv[1] });
					}
				}
				else next.push_back({ iv[0],iv[1] });
			}
			//这一轮搜下来将去掉一些完整子串
			//我们再对next进行搜索, 看左右能不能变短
			vector<vector<int>> next2;
			for (auto& in : next)
			{
				//看每个元素的左边和stamp的右边求重叠部分
				int templen1 = overlap_tleft_sright(target, in[0], in[1], stamp);
				//看每个元素的右边和stamp的左边求重叠部分
				int templen2 = overlap_tright_sleft(target, in[0], in[1], stamp);
				//检验两个长度合法性:
				if ((in[1] - templen2 + 1 + stamp.size()) > target.size()) templen2 = 0;
				if (in[0] - ((int)stamp.size() - templen1) < 0) templen1 = 0;

				//拆分
				int totallen = templen1 + templen2;
				if (totallen == 0) return {}; //强制退出
				else
				{
					int tlen = in[1] - in[0] + 1;
					if (totallen >= tlen)
					{
						//左边templen1, 右边templen2
						if (templen2) res.push_back(in[1] - templen2 + 1);
						if (templen1) res.push_back(in[0] - ((int)stamp.size() - templen1));
					}
					else
					{
						//左边templen1, 右边templen2
						if (templen2) res.push_back(in[1] - templen2 + 1);
						if (templen1) res.push_back(in[0] - ((int)stamp.size() - templen1));
						next2.push_back({ in[0] + templen1, in[1] - templen2 });
					}
				}
			}
			v = next2;
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//auto res = s->movesToStamp("abca", "aabcaca");
	//auto res = s->movesToStamp("oz", "ooozz");
	//auto res = s->movesToStamp("vba", "vvbvbavbaa");
	//auto res = s->movesToStamp("cab", "cabbb");
	//auto res = s->movesToStamp("ffebb", "fffeffebbb");
	auto res = s->movesToStamp("abca", "aabcaca");
	return 0;
}
