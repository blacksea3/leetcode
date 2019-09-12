#include "public.h"

//0ms, 100%
//复杂的模拟

class Solution {
private:
	string genstring_fullJustify(vector<string> words, int maxlength)
	{
		//计算空格数量
		int length = 0;
		for (auto word : words) length += word.size();
		int totalspace = maxlength - length;
		int spacegroupnum = words.size() - 1;
		if (spacegroupnum == 0)  //如果只有一个空格, 那么空格应该全在右边
			return genlaststring_fullJustify(words, maxlength);
		int upper_space = totalspace / spacegroupnum;
		int remaining_space = totalspace % spacegroupnum;

		string returns = words[0];
		for (int i = 1; i < (spacegroupnum + 1); i++)
		{
			if (i <= remaining_space)
				for (int j = 0; j < (upper_space + 1); j++)
					returns += " ";
			else
				for (int j = 0; j < upper_space; j++)
					returns += " ";
			returns += words[i];
		}
		return returns;
	}

	string genlaststring_fullJustify(vector<string> words, int maxlength)
	{
		string returns = words[0];
		for (int i = 1; i < words.size(); i++)
		{
			returns += " ";
			returns += words[i];
		}

		int leftspace = maxlength - returns.size();

		for (int i = 0; i < leftspace; i++)
			returns += " ";
		return returns;
	}

public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		//问题保证了
		//words.size()>0
		//words[0].size()>=maxWidth
		int wsize = words.size();

		vector<string> pre_words = {};
		int pre_length = 0;
		vector<string> res = {};

		for (int i = 0; i < wsize; i++)
		{
			if ((words[i].size() + pre_length) <= maxWidth)
			{
				pre_words.push_back(words[i]);
				pre_length += words[i].size() + 1;
			}
			else
			{
				res.push_back(genstring_fullJustify(pre_words, maxWidth));
				pre_words.clear();
				pre_words.push_back(words[i]);
				pre_length = words[i].size() + 1;
			}
		}

		res.push_back(genlaststring_fullJustify(pre_words, maxWidth));
		return res;
	}
};