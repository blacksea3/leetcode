#include "public.h"

//8ms, 98.69%

//����ת���ַ���Ȼ���Զ�����������Ȼ���������ַ�������������ȥ����ͷ��0

class Solution {
private:
	//num1 != num2
	//���Ƕ��������ֵ����Ƚ� �����λ��ʼ�Ƚ�
	//return false: num1 <= num2, true: num1 > num2;
	static bool cmpnum_179(const string& num1, const string& num2)
	{
		//ֱ�Ӱ�num1ƴ��num2����ȥ��
		//��string �Ƚ�!
		string s1 = num1 + num2;
		string s2 = num2 + num1;
		return s1 > s2 ? true : false;
	}

public:
	string largestNumber(vector<int>& nums) {
		//�൱�ڸ�nums����
		//���Ƕ��������ֵ����Ƚ� �����λ��ʼ�Ƚ�
		//ʹ������sort
		vector<string> strs;
		for (auto& n : nums) strs.push_back(to_string(n));

		sort(strs.begin(), strs.end(), cmpnum_179);

		//����,����string
		string res = "";
		for (auto s : strs) res += s;

		//�б�Ҫȥ����ͷ��0, FUCK
		//������������ȫ��0�����......
		while (res.size() > 1)
			if (res[0] == '0')
				res.erase(res.begin());
			else
				break;

		return res;
	}
};
