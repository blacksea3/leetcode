#include "public.h"

//12ms, 89.74%
//��������
//��ʼ�����ڴ�С��k+1, ���������չһ�����ں�, ��ǰ���ڳ���-���������ĸ��<=k�����չ, 
//�����ȥһ��/�����ߴ���

class Solution {
public:
	int characterReplacement(string s, int k) {
		vector<int> count(256, 0);
		int res = 0, maxCount = 0;
		for (int l = 0, r = 0; r < s.length(); ++r) {
			count[s[r]]++;
			maxCount = max(maxCount, count[s[r]]);
			while (r - l + 1 - maxCount > k) {
				count[s[l]]--;
				++l;
			}
			res = max(res, r - l + 1);
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//auto res = s->characterReplacement("KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF", 4);
	auto res = s->characterReplacement("ABAA", 0);
	return 0;
}
