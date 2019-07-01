#include "public.h"

//8ms, 93.16%
//分治得出所有情况

class Solution {
private:
	//cal
	int cal(int num1, int num2, vector<char>& ops, int oploc)
	{
		int res;
		switch (ops[oploc])
		{
		case '+':
		{
			res = num1 + num2;
			break;
		}
		case '-':
		{
			res = num1 - num2;
			break;
		}
		case '*':
		{
			res = num1 * num2;
			break;
		}
		default:
			break;
		}
		return res;
	}

	//outside must ensure that numstart - numend - 1 = opstart - opend, numend >= numstart
	// numsstart = opstart
	vector<int> recu_Cimpute(vector<int>& nums, int numstart, int numend,
		vector<char>& ops, int opstart, int opend)
	{
		vector<int> pre;
		if (numstart == numend)
		{
			pre.push_back(nums[numstart]);
			return pre;
		}
		else
		{
			for (int i = opstart; i <= opend; ++i)
			{
				vector<int> r1 = recu_Cimpute(nums, numstart, i,
					 ops, opstart, i - 1);
				vector<int> r2 = recu_Cimpute(nums, i + 1, numend,
					ops, i + 1, opend);
				for (auto& left : r1)
					for (auto& right : r2)
						pre.push_back(cal(left, right ,ops, i));
			}
			return pre;
		}
	}

public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char> ops;
		int preval = 0;
		for (auto& i : input)
		{
			if (isdigit(i))
			{
				preval = preval * 10 + (i - '0');
			}
			else
			{
				nums.push_back(preval);
				ops.push_back(i);
				preval = 0;
			}
		}
		nums.push_back(preval);

		vector<int> res = recu_Cimpute(nums, 0, nums.size() - 1,
			ops, 0, ops.size() - 1);
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> res = s->diffWaysToCompute("2-1-1");
	return 0;
}

