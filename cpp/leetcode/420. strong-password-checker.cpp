#include "public.h"

//0ms, 100%
//巨复杂的贪婪题目
//先统计字符种类缺失数以及大于3的连续字符串长度数(放到vector), 然后长度分类
//长度<6,   需要添加和/或替换字符, 实际上仅仅考虑缺失字符种类数和缺失字符长度的最大值即可
//长度OK,   长度OK, 仅考虑替换字符, 操作数按照长度/3处理
//长度>20,  需要删除和/或替换字符
//   优先考虑字符种类不全, 用替换处理:
//       如果有连续长度>=3的字符串, 优先替换 长度%3==2的, 其次%3==1, 其次%3==0, 替换后此长度减三
//       否则默认替换最右边的字符, 其次次右边的
//   然后试图删除字符
//       如果有连续长度>=3的字符串, 优先删除: 长度%3==0的, 其次%3==1, 其次%3==2, 删除后此长度减1
//       否则默认删除最右边的字符, 如果最右边字符是独特类型则删除次右边的, 以此类推, 此方法旨在保证不引入新的过长子串
//   最后按照长度OK处理剩余的大于3的连续字符串长度数, 如果有的话

class Solution {
public:
	int strongPasswordChecker(string s) {
		if (s.empty()) return 6;

		bool hasLow, hasHigh, hasNum;
		hasLow = hasHigh = hasNum = false;
		int len = s.size();
		vector<int> lengthsBiggerThanThree;  //大于3的连续字符串长度数

		int preLen = 0;
		char old = s[0] + 1;

		for (auto& iters : s)
		{
			if ('a' <= iters && iters <= 'z') hasLow = true;
			if ('A' <= iters && iters <= 'Z') hasHigh = true;
			if ('0' <= iters && iters <= '9') hasNum = true;
			if (old != iters)
			{
				if (preLen >= 3)
				{
					lengthsBiggerThanThree.emplace_back(preLen);
				}
				old = iters;
				preLen = 1;
			}
			else preLen++;
		}
		if (preLen >= 3)
		{
			lengthsBiggerThanThree.emplace_back(preLen);
		}

		//长度小于6
		if (len < 6) //需要添加和/或替换字符, 实际上仅仅考虑缺失字符种类数和缺失字符长度的最大值即可
		{
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			return max(lack, 6 - len);
		}
		else if (len > 20)  //麻烦, 需要删除和/或替换字符
		{
			//先统计缺失字符种类
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			int res = 0;
			//然后考虑是否需要替换连续组的字符, 如果有连续组的话, 那么优先替换 长度%3==2的, 其次%3==1, 其次%3==0
			while (lack > 0)
			{
				if (!lengthsBiggerThanThree.empty())
				{
					//寻找长度%3==2的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 2)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
					//寻找长度%3==1的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 1)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
					//寻找长度%3==0的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 0)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
				}
				//没了, 那么直接替换, 没有额外操作
			nextlack: //最后处理res和lack信息
				res++;
				lack--;
			}
			//然后考虑当前长度: 进行删除: 优先删除重复字符的: 理论上绝对不可能经过删除产生新的重复字符, 因为不会删除连续长度<3的子字符串内的字符
			while (len > 20)
			{
				//删除优先级: 长度%3==0的, 其次%3==1, 其次%3==2
				for (auto& iters : lengthsBiggerThanThree)
				{
					//寻找长度%3==0的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 0)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
					//寻找长度%3==1的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 1)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
					//寻找长度%3==2的
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 2)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
				}
				//啥都找不到, 那么默认从最右边开始删除字符, 如果删除那个字符导致某个类型缺失, 那么删除右数第二个...
				//注意: 绝对不存在删除某个字符导致出现连续字符串>=3, 这是因为要么删除最右边的字符
				//要么最右边字符是独一无二类型
			nextlen:
				len--;
				res++;
			}
			//最后替换字符
			for (auto& iters : lengthsBiggerThanThree)
			{
				res += iters / 3;
			}
			return res;
		}
		else  //长度OK, 仅考虑替换字符
		{
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			int subMultipleChar = 0;
			for (auto& iters : lengthsBiggerThanThree)
			{
				subMultipleChar += iters / 3;
			}
			return max(lack, subMultipleChar);
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->strongPasswordChecker("") << endl;							//6
	cout << s->strongPasswordChecker("aaa111") << endl;						//2
	cout << s->strongPasswordChecker("ABABABABABABABABABAB1") << endl;		//2
	return 0;
}
*/
