#include "public.h"

//here, you should carry out a solution to store the unique res of the recombination of the number of each letter
// Two ways:  one: caculate the number of each letter then generate a string: 1#9#5#.....#10#0 means one a, nine b, five c
// ... ten y and zero z.
// two: for each letter, give a prime number, then multiple all the numbers
// for exm: a has 2, b has 3, c has 5....

//then use the unique res as the key of an unordered_map, the problem will be solved

// first: 260ms, 12.05%

/*class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> allstrs = {};

		//one traverse
		for (int i = 0; i < strs.size(); i++)
		{
			//combine the number of each letter with # insertion
			vector<int> pre_num(26, 0);
			for (int j = 0; j < strs[i].size(); j++)
				pre_num[strs[i][j] - 'a'] += 1;
			string key = "";
			for (int j = 0; j < 26; j++)
			{
				key += to_string(pre_num[j]) + "#";
			}
			allstrs[key].push_back(strs[i]);
		}

		vector<vector<string>> returnres = {};
		for (unordered_map<string, vector<string>>::iterator iter = allstrs.begin(); iter != allstrs.end(); iter++) {
			returnres.push_back(iter->second);
		}

		return returnres;
	}
};*/

//40ms, 99.80%

//second:
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<unsigned int, vector<string>> allstrs = {};
		//note, the size of strs[0] should not be too high, otherwise overflow of key will happen
		unsigned char alpha[26] = { 2,3,5,7,11,13,17,19,23,29,31,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103 };
		
		//one traverse
		for (int i = 0; i < strs.size(); i++)
		{
			//combine the number of each letter with # insertion
			unsigned int temp = 1;
			for (auto iis:strs[i]) temp*= alpha[iis -'a'];
			allstrs[temp].push_back(strs[i]);
		}
		vector<vector<string>> returnres = {};
		for (unordered_map<unsigned int, vector<string>>::iterator iter = allstrs.begin(); iter != allstrs.end(); iter++) {
			returnres.push_back(iter->second);
		}
		return returnres;
	}
};