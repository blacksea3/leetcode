#include "public.h"

//12ms, 85.62%
//����ת���ַ���Ȼ���Զ�����������Ȼ���������ַ�������������ȥ����ͷ��0

class Solution {
private:
	//num1 != num2
	//���Ƕ��������ֵ����Ƚ� �����λ��ʼ�Ƚ�
	//return false: num1 <= num2, true: num1 > num2;
	static bool msort(string const& num1, string const& num2)
	{
		string s1 = num1 + num2;
		string s2 = num2 + num1;
		return s1 > s2 ? true : false;
	}

public:
	string largestNumber(vector<int>& nums) {
		vector<string> strs;
		for (auto& n : nums) strs.emplace_back(to_string(n));

		sort(strs.begin(), strs.end(), msort);

		//����,����string
		string res = "";
		for (auto& s : strs) res += s;

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
