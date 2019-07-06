#include "public.h"

/*回溯
作者：LeetCode
链接：https://leetcode-cn.com/problems/expression-add-operators/solution/gei-biao-da-shi-tian-jia-yun-suan-fu-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
private:
	vector<string> res = {};
	int N;
	int pub_target;
	string pub_num;
	void recurse(int index, long prev_operand, long current_operand, long value, string& prestring)
	{
		if (index == N)
		{
			if ((value == pub_target) && (current_operand == 0))
				res.push_back(prestring.substr(1));
		}
		else
		{
			current_operand = current_operand*10+pub_num[index] - '0';
			string str_op = to_string(current_operand);

			//如果current_operand大于0, 说明current_operand的字符串不全是0, 可以往后叠加
			if (current_operand > 0)
				recurse(index + 1, prev_operand, current_operand, value, prestring);

			//+
			string originstr = prestring;
			prestring += "+";
			prestring += str_op;
			recurse(index + 1, current_operand, 0, value + current_operand, prestring);
			prestring = originstr;

			if (prestring.size() > 0)
			{
				//-
				prestring += "-";
				prestring += str_op;
				recurse(index + 1, -1 * current_operand, 0, value - current_operand, prestring);
				prestring = originstr;

				//*
				prestring += "*";
				prestring += str_op;
				recurse(index + 1, current_operand*prev_operand, 0, value - prev_operand + (current_operand * prev_operand), prestring);
				prestring = originstr;
			}
		}
	}

public:
	vector<string> addOperators(string num, int target) {
		N = num.size();
		pub_target = target;
		pub_num = num;
		string prestr = "";
		recurse(0, 0, 0, 0, prestr);
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<string> res = s->addOperators("105",5);
	return 0;
}
*/
