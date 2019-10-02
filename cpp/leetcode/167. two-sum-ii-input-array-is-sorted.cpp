#include "public.h"

//4ms, 97.08%
//˫ָ��, �����˿�ʼ, ѡ��ĳ��ָ�����м��ƶ�
//��Ŀ�Ѹ�֪һ����Ψһ��

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (true)
		{
			if ((numbers[left] + numbers[right]) > target) right--;
			else if ((numbers[left] + numbers[right]) < target) left++;
			else return { left + 1, right + 1 };
		}
		return { -1, -1 }; //dump
	}
};
