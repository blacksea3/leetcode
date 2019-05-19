#include "public.h"

//8ms 99.53%

class Solution {
public:
	string longestPalindrome(string s) {
		//Manacher algorithm
		//特别注意边界问题
		//我目前说不清楚
	    //请查看https://mp.weixin.qq.com/s?__biz=MzIzMTE1ODkyNQ==&mid=2649410225&idx=1&sn=ed045e8edc3c49a436a328e5f0f37a55&chksm=f0b60f53c7c18645b4c04a69ad314723cce94ed56994d6f963c2275a2db8d85f973f15f508e4&mpshare=1&scene=23&srcid=1001JCsBlpxgUWjgixasChNQ#rd
		//O(n)时间复杂度

		//这样做可以不用考虑偶数长度的回文子串
		//扩展s至原来的2倍+1长度
		string newstr = string("#");
		unsigned int iSize = s.size();
		for (unsigned int i = 0; i < iSize; i++)
		{
			newstr += s[i];
			newstr += "#";
		}

		int new_len = newstr.size();
		vector<int> radius(new_len, 0);
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
				radius[index] = newradius;
				right_border = R - 1;
				center_index = index;
				if (newradius > longest_radius)
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
				if (newradius > longest_radius)
				{
					longest_radius = newradius;
					longest_center_index = index;
				}
			}
			else radius[index] = radius[2 * center_index - index];
		}

		float real_index = (longest_center_index + 1) / 2.0 - 1;  //may be xxx.5  4->1.5 2->0.5, 3->1, 1->0
		float real_radius = (longest_radius) / 2.0 - 1;         //5 ->1.5,  3->0.5  4->1, 2->0

		return s.substr(int(real_index - real_radius), int(2 * real_radius + 1));
	}
};

int main()
{
	Solution* s = new Solution();

	string res = s->longestPalindrome("babad");
	int i = 1;
}
