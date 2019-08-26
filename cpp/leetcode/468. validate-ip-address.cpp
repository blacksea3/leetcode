#include "public.h"

//4ms, 81.45%
//ģ��

class Solution {
public:
	string validIPAddress(string IP) {
		vector<string> splits;
		int nextloc = 0;
		int preloc = 0;

		//��.��:����
		if (IP.find('.') != IP.npos)
		{
			//�ٿ�IP���Ա��ֳɼ���
			while (preloc < IP.size())
			{
				while (preloc < IP.size() && IP[preloc] != '.') preloc++;
				if (preloc == nextloc) return "Neither"; //.��������
				else splits.push_back(IP.substr(nextloc, preloc - nextloc));
				preloc++;
				nextloc = preloc;
			}
			if (IP[IP.size() - 1] == '.') return "Neither";
		}
		else if (IP.find(':') != IP.npos)
		{
			//�ٿ�IP���Ա��ֳɼ���
			while (preloc < IP.size())
			{
				while (preloc < IP.size() && IP[preloc] != ':') preloc++;
				if (preloc == nextloc) return "Neither"; //ð�Ų�������
				else splits.push_back(IP.substr(nextloc, preloc - nextloc));
				preloc++;
				nextloc = preloc;
			}
			if (IP[IP.size() - 1] == ':') return "Neither";
		}

		if (splits.size() != 4 && splits.size() != 8) return "Neither";
		else
		{
			if (splits.size() == 4)
			{
				//�ȿ���û��0��ͷ��
				if ((splits[0][0] == '0' && (splits[0].size() > 1)) || 
					(splits[1][0] == '0' && (splits[1].size() > 1)) ||
					(splits[2][0] == '0' && (splits[2].size() > 1)) || 
					(splits[3][0] == '0' && (splits[3].size() > 1))) return "Neither";
				else
				{
					//�ٿ����ַ�Χ(�ǲ���ȫ������)
					for (auto& num : splits)
					{
						if (num.size() > 3) return "Neither";
						for (auto& iter_num : num)
						{
							if (!isdigit(iter_num)) return "Neither";
						}
						int temp = atoi(num.c_str());
						if (temp > 255) return "Neither";
					}
					return "IPv4";
				}
			}
			else
			{
				//���ǲ���ȫ��ʮ��������
				for (auto& num : splits)
				{
					if (num.size() > 4) return "Neither";
					for (auto& iter_num : num)
					{
						if (!isdigit(iter_num) && !((iter_num <= 'f' && iter_num >= 'a')
							|| (iter_num <= 'F' && iter_num >= 'A')
							))
							return "Neither";
					}
				}
				return "IPv6";
			}
		}
	}
};

int main()
{
	Solution* s = new Solution();
	cout << s->validIPAddress("192.0.0.1");
	//cout << s->validIPAddress("172.16.254.1");
	//cout << s->validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:");
	//cout << s->validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
	return 0;
}
