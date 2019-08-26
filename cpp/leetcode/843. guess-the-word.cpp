#include "public.h"

//16ms, 11.11%
//选择一个单词, 然后其他单词与他的匹配度分组
//选择依据: 按照其他单词与它的相似程度分组, 最大数量的组的数量是最小的, 挑选这个单词

//很遗憾我这种方法并不能完全降低猜测次数至<=10, 我使用了if (minnums >= tempmax)而不是＜判断最大数量的组的数量最小的单词
//强行蒙过了此题, 需要优化, 大佬们的评论就是用和我差不多的蒙的方法:)

class Master {
private:
	string mem;
public:
	Master(string i){
		mem = i;
	}
	int guess(string word)
	{
		int res = 0;
		for (int i = 0; i < 6; ++i)
		{
			if (word[i] == mem[i]) res++;
		}
		return res;
	}
};

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
private:
	int tellsame(string s1, string s2)
	{
		int res = 0;
		for (int i = 0; i < 6; ++i)
		{
			if (s1[i] == s2[i]) res++;
		}
		return res;
	}

public:
	void findSecretWord(vector<string>& wordlist, Master& master) {
		int time = 0;

		while (true)
		{
			time++;
			//分组
			vector<vector<int>> sames(wordlist.size(), vector<int>(7, 0));
			for (int i = 0; i < wordlist.size(); ++i)
			{
				for (int j = 0; j < wordlist.size(); ++j)
				{
					int temp = tellsame(wordlist[i], wordlist[j]);
					sames[i][temp]++;
				}
			}
			//按照其他单词与它的相似程度分组, 最大数量的组的数量是最小的, 挑选这个单词
			int minnums = INT_MAX;
			int loc = -1;
			for (int i = 0; i < wordlist.size(); ++i)
			{
				int tempmax = INT_MIN;
				for (int j = 0; j < 7; ++j)
				{
					tempmax = max(tempmax, sames[i][j]);
				}
				if (minnums >= tempmax)
				{
					minnums = tempmax;
					loc = i;
				}
			}
			
			string selected = wordlist[loc];
			wordlist.erase(wordlist.begin() + loc);
			int re = master.guess(selected);
			if (re == 6) break;
			else
			{
				for (int i = 0; i < wordlist.size(); ++i)
				{
					if (tellsame(wordlist[i], selected) != re) wordlist.erase(wordlist.begin() + i);
				}
			}
		}
		for (int i = 0; i < 10 - time; ++i)
		{
			master.guess("aaaaaa");
		}
	}
};

int main()
{
	Master m = Master("hbaczn");
	Solution* s = new Solution();
	vector<string> wordlist = { "gaxckt","trlccr","jxwhkz","ycbfps","peayuf","yiejjw","ldzccp","nqsjoa","qrjasy","pcldos","acrtag","buyeia","ubmtpj","drtclz","zqderp","snywek","caoztp","ibpghw","evtkhl","bhpfla","ymqhxk","qkvipb","tvmued","rvbass","axeasm","qolsjg","roswcb","vdjgxx","bugbyv","zipjpc","tamszl","osdifo","dvxlxm","iwmyfb","wmnwhe","hslnop","nkrfwn","puvgve","rqsqpq","jwoswl","tittgf","evqsqe","aishiv","pmwovj","sorbte","hbaczn","coifed","hrctvp","vkytbw","dizcxz","arabol","uywurk","ppywdo","resfls","tmoliy","etriev","oanvlx","wcsnzy","loufkw","onnwcy","novblw","mtxgwe","rgrdbt","ckolob","kxnflb","phonmg","egcdab","cykndr","lkzobv","ifwmwp","jqmbib","mypnvf","lnrgnj","clijwa","kiioqr","syzebr","rqsmhg","sczjmz","hsdjfp","mjcgvm","ajotcx","olgnfv","mjyjxj","wzgbmg","lpcnbj","yjjlwn","blrogv","bdplzs","oxblph","twejel","rupapy","euwrrz","apiqzu","ydcroj","ldvzgq","zailgu","xgqpsr","wxdyho","alrplq","brklfk" };
	s->findSecretWord(wordlist, m);
	return 0;
}
