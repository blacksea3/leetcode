#include "public.h"

//0ms, 100%
//����״̬��

class Solution {
public:
	bool isNumber(string s) {
		//ȥ����ͷ�Ŀո�
		int slen = s.size();
		if (slen == 0) return false;
		int loc = 0;


		while (s[loc] == ' ')
		{
			if (loc == slen - 1) return false;  //ȫ�ǿո�
			loc++;
		}

		//ȥ��ĩβ�ո�
		int last = slen - 1;
		while (s[last] == ' ') last--;

		int state = 0;   //0:�ȴ����ֻ���Ż���С����, 1:(���˷���)�ȴ�һ�����ֻ���С����, 2:������Ч����/�������
		//�ȴ����ܵ�С����/'e'������������(���߱�������),
		//3:����С����,�ȴ�e������������(���߱�������, 4:����e,�ȴ��������ֻ��߷���,(��������ֱ�ӽ���)
		//5:����e�Լ�����,�ȴ���������,(��������ֱ�ӽ���)
		//6:����e,�ȴ���������(���߱�������)

		bool no_number_before_point = false;   //���С����ǰ��û������,Ҫ�Ǻ���Ҳû�������򷵻�false
		loc -= 1;

		//ע��������Щ����,�Ҹ�loc�ȼ���1,���ر���Ҫע��for��ѭ������
		for (int i = loc; i < last; i++)
		{
			loc++;
			switch (state)
			{
			case 0:
			{
				if ((s[loc] == '+') || (s[loc] == '-')) state = 1;
				else if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
				else if (s[loc] == '.')
				{
					state = 3;
					no_number_before_point = true;
				}
				else return false;
				break;
			}
			case 1:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 2;
				else if (s[loc] == '.')
				{
					state = 3;
					no_number_before_point = true;
				}
				else return false;
				break;
			}
			case 2:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0'));
				else if (s[loc] == '.') state = 3;
				else if (s[loc] == 'e') state = 4;
				else return false;
				break;
			}
			case 3:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) no_number_before_point = false;
				else if (s[loc] == 'e')
				{
					if (no_number_before_point) return false;
					state = 4;
				}
				else return false;
				break;
			}
			case 4:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
				else if ((s[loc] == '+') || (s[loc] == '-')) state = 5;
				else return false;
				break;
			}
			case 5:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0')) state = 6;
				else return false;
				break;
			}
			case 6:
			{
				if ((s[loc] <= '9') && (s[loc] >= '0'));
				else return false;
				break;
			}
			}
		}

		switch (state)
		{
		case 0:
		case 1:
		case 4:
		case 5:
			return false;
		case 2:
		case 6:
			return true;
		case 3:
			return !(no_number_before_point);
		default:
			return false;
		}
	}
};