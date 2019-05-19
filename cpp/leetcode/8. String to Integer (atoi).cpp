#include "public.h"

//4ms 99.86%

//写成状态机的形式,按照当前状态+输入->下一状态进行操作
//具体算法就不描述了

class Solution {
public:
	int myAtoi(string str) {
		bool state = false;   //false:idle(need find sign or number), true:run(need find number)
		bool ispositive = true;

		int returnnum = 0;
		int num_times = 0;    //means returnnum的位数

		for (int loc = 0; loc < str.size(); loc++)
		{
			if (!state)
			{
				if ((str[loc] <= '9') && (str[loc] >= '0'))
				{
					state = true;
					returnnum = returnnum * 10 + (str[loc] - '0');  //char->int
					num_times++;
					if (returnnum == 0) num_times--;
				}
				else if (str[loc] == '-')
				{
					ispositive = false;
					state = true;
				}
				else if (str[loc] == '+')
				{
					state = true;
				}
				else if (str[loc] == ' ');
				else return 0;
			}
			else
			{
				if ((str[loc] <= '9') && (str[loc] >= '0'))
				{
					if (num_times == 9)
					{
						if (returnnum > 214748364) return (ispositive) ? INT_MAX : INT_MIN;
						else if (returnnum == 214748364)
						{
							if ((ispositive) && (str[loc] >= '7'))
								return INT_MAX;
							if ((!ispositive) && (str[loc] >= '8'))
								return INT_MIN;
						}
					}
					else if (num_times == 10) return (ispositive) ? INT_MAX : INT_MIN;
					returnnum = returnnum * 10 + (str[loc] - '0');  //char->int
					num_times++;
					if (returnnum == 0) num_times--;
				}
				else break;
			}

		}
		return (ispositive) ? returnnum : -1 * returnnum;
	}
};

