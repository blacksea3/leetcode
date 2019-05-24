#include "public.h"

//24ms, 99.42%

//for starloc, You can divide them into several groups:
//  for example: if words[0].size() == 3;
//  you can search startloc as : first group: 0,3,6,9..
//   second group: 1,4,7,10...
//   third group: 2,5,8,11,   then in one group, the history infomation can be reused!

// the algorithm is similar to sliding window

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		//divide the startlocs into words.size() groups
		int wsize = words.size();
		if (wsize == 0) return vector<int> {};  //fuck special condition
		int iter_length = words[0].size();
		if (iter_length == 0) return vector<int> {}; //fuck special condition

		int ssize = s.size();
		if (ssize < iter_length) return vector<int> {};

		//init map
		unordered_map<string, int> allwords = {};
		for (int i = 0; i < wsize; i++)
			allwords[words[i]] += 1;

		//find locs
		vector<int> returnv = {};
		for (int i = 0; i < iter_length; i++)
		{
			unordered_map<string, int> findwords = {};
			int find_words_number = 0;
			for (int j = 0; j <= (ssize - i - (wsize - find_words_number)* iter_length) / iter_length; j++)
			{
				string pre_str = s.substr(i + j * iter_length, iter_length);
				if (allwords.find(pre_str) != allwords.end())
				{
					findwords[pre_str] += 1;
					find_words_number++;
					if (findwords[pre_str] > allwords[pre_str])
					{
						while (true)
						{
							string oldstr = s.substr(i + (j - find_words_number + 1)*iter_length, iter_length);
							findwords[oldstr] -= 1;
							find_words_number--;
							if (oldstr == pre_str) break;
						}
					}
					else
					{
						if (find_words_number == wsize)
						{
							returnv.push_back(i + (j - find_words_number + 1)*iter_length);
							//remove the first value because here finding a matching
							findwords[s.substr(i + (j - find_words_number + 1)*iter_length, iter_length)] -= 1;
							find_words_number--;
						}
					}
				}
				else
				{
					//reset
					findwords = {};
					find_words_number = 0;
				}
			}
		}
		return returnv;
	}
};
