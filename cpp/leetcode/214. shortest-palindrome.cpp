#include "public.h"

//����Manacher�㷨, 16ms, 33.12%

//ע��:���Ӧ���ȿ�ȡs�ĺ�һ�����ַ���Ȼ��ת�ټ���s��ǰһ�����ַ���
//��������ʹ��res.insert(res.begin(),char x), ��̫����, ֱ��TLE

class Solution {
public:
	string shortestPalindrome(string s) {
		//�ҳ�������࿪ʼ������Ĵ�

		//��s�����ο�ʼ��չ,O(n^2),���м俪ʼ��չ,��
		//�����������㷨�ᳬʱ
		//��:������Ŀ5

		//Manacher algorithm
		//�ر�ע��߽�����
		//https://mp.weixin.qq.com/s?__biz=MzIzMTE1ODkyNQ==&mid=2649410225&idx=1&sn=ed045e8edc3c49a436a328e5f0f37a55&chksm=f0b60f53c7c18645b4c04a69ad314723cce94ed56994d6f963c2275a2db8d85f973f15f508e4&mpshare=1&scene=23&srcid=1001JCsBlpxgUWjgixasChNQ#rd

		string newstr = string("#");
		unsigned int iSize = s.size();
		for (unsigned int i = 0; i < iSize; i++)
		{
			newstr += s[i];
			newstr += "#";
		}

		int new_len = newstr.size();   //yһ��������
		vector<int> radius(new_len, 0);
		int right_border = -1;
		int center_index = -1;
		int longest_radius = -1;
		int longest_center_index = -1;
		for (int index = 0; index <= new_len/2; index++)  //��Ϊ��Ҫ����������ͷ������Ĵ�,��������ѵ��м�
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
				int newradius = (R - L + 1) / 2;    //�˴�������ȡ��
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
				int newradius = (R - L + 1) / 2;    //�˴�������ȡ��
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
