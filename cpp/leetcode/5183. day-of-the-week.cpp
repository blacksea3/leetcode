#include "public.h"
//
//��2019��1��1��Ϊ��׼, ��������������ֵ

class Solution {
private:
	bool isRunNian(int year)
	{
		return (((year % 4) == 0) && (((year % 100) != 0) || (year % 400) == 0));
	}

	//1971 1 1 ������
	string getWeek(int absday, bool isFuture)
	{
		vector<string> v = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
		return v[absday % 7];
	}

public:
	string dayOfTheWeek(int day, int month, int year) {
		int absday = 0;
		vector<int> monthDays = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 }; //����ͨ�괦��,ֱ����ǰ�·ݵ�ǰ���·�������֮��, �±�����·�

		if (year >= 1971)
		{
			int preyear = 1971;
			while (preyear < year)
			{
				if (isRunNian(preyear))
				{
					absday += 366;
				}
				else
				{
					absday += 365;
				}
				preyear++;
			}

			//���˵���
			bool isPreYearRunNian = isRunNian(preyear);
			absday += monthDays[month] + day - 1;
			return getWeek(absday, true);
		}
		else
		{
			return "DUMP";
		}
	}
};
