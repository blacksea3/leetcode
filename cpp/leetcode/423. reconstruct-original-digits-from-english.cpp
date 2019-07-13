#include "public.h"

//20ms, 96.26%
//统计字符频率频, 然后一个一个减

// one two three four five six seven eight nine zero

//顺序: zero, two, eight, one, six, four, five, seven, nine, three

class Solution {
public:
	string originalDigits(string s) {
		vector<int> chars(256, 0);

		for (auto& iis : s) chars[iis]++;

		//一个一个来
		string res = "";

		map<char, int> lens;

		//按注释中的顺序
		lens['0'] = chars['z'];
		chars['e'] -= lens['0'];
		chars['r'] -= lens['0'];
		chars['o'] -= lens['0'];

		lens['2'] = chars['w'];
		chars['t'] -= lens['2'];
		chars['o'] -= lens['2'];

		lens['8'] = chars['g'];
		chars['e'] -= lens['8'];
		chars['i'] -= lens['8'];
		chars['h'] -= lens['8'];
		chars['t'] -= lens['8'];

		lens['4'] = chars['u'];
		chars['f'] -= lens['4'];
		chars['o'] -= lens['4'];
		chars['r'] -= lens['4'];

		lens['1'] = chars['o'];
		chars['w'] -= lens['1'];
		chars['e'] -= lens['1'];

		lens['6'] = chars['x'];
		chars['s'] -= lens['6'];
		chars['i'] -= lens['6'];

		lens['5'] = chars['f'];
		chars['i'] -= lens['5'];
		chars['v'] -= lens['5'];
		chars['e'] -= lens['5'];

		lens['7'] = chars['s'];
		chars['e'] -= lens['7'];
		chars['v'] -= lens['7'];
		chars['e'] -= lens['7'];
		chars['n'] -= lens['7'];

		lens['9'] = chars['i'];
		chars['n'] -= lens['9'];
		chars['n'] -= lens['9'];
		chars['e'] -= lens['9'];

		lens['3'] = chars['r'];
		chars['t'] -= lens['3'];
		chars['h'] -= lens['3'];
		chars['e'] -= lens['3'];
		chars['e'] -= lens['3'];

		for (auto& len : lens)
		{
			for (int i = 0; i < len.second; ++i)
				res += len.first;
		}
		return res;
	}
};
