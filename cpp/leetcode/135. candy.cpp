#include "public.h"

//�������,һ������һ�ַ���, 32ms, 88.65%

class Solution {
public:
	int candy(vector<int>& ratings) {
		//ȫ����ʼ����1
		//���������,�Ե�ǰ���ִ���ǰһ��,����ǰ����ǰһ��+1
		//�������,�Ե�ǰ���ִ��ں�һ��,�����ǰֵ�Ⱥ�һ��С�����,��ô�޸ĵ�ǰֵ���Ⱥ�һ��+1,�ⲻ��Ӱ���һ�ֱ������õ�(��ǰ���ִ���ǰһ��,����ǰ����ǰһ��+1,��Ϊ�����ɵ�ǰ��ֵ��ǰһ����Ķ�)

		vector<int> candies(ratings.size(), 1);
		for (int i = 1; i < ratings.size(); i++)
			if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;

		for (int i = ratings.size() - 2; i >= 0; i--)
			if (ratings[i] > ratings[i + 1])
				if (candies[i] <= candies[i + 1])
					candies[i] = candies[i + 1] + 1;

		int sum = 0;
		for (auto icandy : candies)
			sum += icandy;
		return sum;
	}
};