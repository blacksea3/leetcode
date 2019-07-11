#include "public.h"

//4ms, 91.18%
//Backtracking
//迭代写法

class Solution {
public:
	int sum(vector<int>& v) {
		int n = 0;
		for (int i : v)
			n += i;
		return n;
	}
	int lengthLongestPath(string input) {
		const int length = input.size();
		vector<int> v;  //相当于stack
		bool cal = false;  //是否需要计算
		int level = 0;  //级别
		int det = 0;    //差值(temp变量)
		int answer = 0; //结果
		int j = -1;   //前一个连续文件/文件夹字符串结尾loc(即'\n')
		for (int i = 0; i < length;) {  //i是当前loc
			while (input[i] == '\t')
				++i;
			level = i - j - 1;
			det = v.size() - level;
			for (int k = 0; k < det; ++k) v.pop_back();  //设置前置文件夹
			for (j = i; j < length && input[j] != '\n'; ++j)  //突进读取, 直到j='\n'
				if (input[j] == '.')
					cal = true;
			v.push_back(level ? j - i + 1 : j - i);  //如果不是根目录, 则长度还需要加上\
            level = 0;
			if (cal) {
				answer = max(answer, sum(v));
				cal = false;
			}
			i = j + 1;  //更新i的位置(当前loc位置)
		}
		return answer;
	}
};


