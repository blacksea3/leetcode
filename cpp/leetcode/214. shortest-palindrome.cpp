#include "public.h"

//复用Manacher算法, 16ms, 33.12%

//注意:最后应当先扣取s的后一部分字符串然后反转再加上s的前一部分字符串
//不可随意使用res.insert(res.begin(),char x), 这太慢了, 直接TLE

class Solution {
public:
	string shortestPalindrome(string s) {
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

		int new_len = newstr.size();   //y一定是奇数
		vector<int> radius(new_len, 0);
		int right_border = -1;
		int center_index = -1;
		int longest_radius = -1;
		int longest_center_index = -1;
		for (int index = 0; index <= new_len/2; index++)  //因为我要搜索包含开头的最长回文串,所以最多搜到中间
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
				radius[index] = newradius;
				right_border = R - 1;
				center_index = index;
				if ((L < 0) && (newradius > longest_radius))
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
				radius[index] = newradius;
				right_border = R - 1;
				center_index = index;
				if ((L < 0) && (newradius > longest_radius))
				{
					longest_radius = newradius;
					longest_center_index = index;
				}
			}
			else radius[index] = radius[2 * center_index - index];
		}

		float real_index = (longest_center_index + 1) / 2.0 - 1;  //may be xxx.5  4->1.5 2->0.5, 3->1, 1->0
		float real_radius = (longest_radius) / 2.0 - 1;         //5 ->1.5,  3->0.5  4->1, 2->0

		string res = s;
		string extra = s.substr(int(2 * real_radius + 1));
		reverse(extra.begin(), extra.end());
		return extra + res;
	}
};

int main()
{
	Solution* s = new Solution();
	//string res = s->shortestPalindrome("aaaaaaaabaaababababaaaaababababaaaaaaaaaaababaaaaaaaa");
	string res = s->shortestPalindrome("abb");
	//string res = s->shortestPalindrome("");
	return 0;
}
