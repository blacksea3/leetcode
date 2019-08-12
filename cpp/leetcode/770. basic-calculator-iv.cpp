#include "public.h"

//44ms, 66.67%
//先转换expression至vector<string>, 然后调用主cal函数, 最后整理返回值

class Solution {
private:
	vector<string> gblevalvars;  //全局的变量字符串
	vector<int> gblevalints;     //全局的变量值

	//如果isconstant:true 则为常数, multi_factor有效
	//否则表示多个val中的string的int次方乘multi_factor
	struct SingleVariable
	{
		unordered_map<string, int> val;
		bool isconstant = true;
		int multi_factor = 1;
	};

	//计算从vexpression[startloc]到最近的一个右括号的值, 将被递归调用, 注意: vexpression[startloc]一定是一个左括号
	//采用三元素循环法: 每次提取前三个值以及前两个操作符, 根据优先级决定如何计算
	//边界条件很复杂

	//输入应该保证startloc不越界
	//返回值first: 键是元素, 值是乘积因子, 如果是个常数, 那么键是"!", 返回值second:右括号的下一个位置(可能这个位置是vexpression末尾)
	//键的元素含义: 键是一个字符串加#加一个数字, 表示这个字符串的数字次方
	pair<vector<SingleVariable>, int> calsubblock(const vector<string>& vexpression, int startloc)
	{
		//代表: val1 op1 val2 op2 val3, 注意没有括号, 如果有括号, 将会递归提前计算至对应的um中
		vector<SingleVariable> val1;
		vector<SingleVariable> val2;
		vector<SingleVariable> val3;
		int op1 = -1;  //-1: 未定义(即只有val1的意思), 0:+, 1:-, 2:*
		int op2 = -1;  //-1: 未定义(即只有val1\op1\val2的意思)

		startloc++; //跳过当前层次的左括号
		if (vexpression[startloc] == "(")
		{
			pair<vector<SingleVariable>, int> next = calsubblock(vexpression, startloc);
			val1 = next.first;
			startloc = next.second;
		}
		else
		{
			val1 = extract(vexpression, startloc);
			startloc++;
		}

		while (startloc < vexpression.size() && vexpression[startloc] != ")")
		{
			//读取op1和val2
			if (op1 == -1)
			{
				op1 = readop(vexpression, startloc);
				startloc++;
				if (vexpression[startloc] == "(")
				{
					pair<vector<SingleVariable>, int> next = calsubblock(vexpression, startloc);
					val2 = next.first;
					startloc = next.second;
				}
				else
				{
					val2 = extract(vexpression, startloc);
					startloc++;
				}
			}
			//读取op2和val3
			else if (op2 == -1)
			{
				op2 = readop(vexpression, startloc);
				startloc++;
				if (vexpression[startloc] == "(")
				{
					pair<vector<SingleVariable>, int> next = calsubblock(vexpression, startloc);
					val3 = next.first;
					startloc = next.second;
				}
				else
				{
					val3 = extract(vexpression, startloc);
					startloc++;
				}
			}
			//计算
			else
			{
				if (op1 == 2)
				{
					val1 = mergeMul(val1, val2);
					val2 = val3;
					op1 = op2;
					op2 = -1;
				}
				else if (op2 == 2)
				{
					val2 = mergeMul(val2, val3);
					op2 = -1;
				}
				else if (op1 == 0)
				{
					val1 = mergeAdd(val1, val2);
					val2 = val3;
					op1 = op2;
					op2 = -1;
				}
				else  //op1 == 1
				{
					val1 = mergeMinus(val1, val2);
					val2 = val3;
					op1 = op2;
					op2 = -1;
				}
			}
		}

		//结束了: 判断op1和op2, 最后再计算一轮
		if (op1 == -1)  //这出现在一个括号内就单独的一个变量/数字, 不用计算了
			;
		else if (op2 == -1) //这出现在一个括号内就单独的一个运算符
		{
        op2_none:
			if (op1 == 2)
				val1 = mergeMul(val1, val2);
			else if (op1 == 0)
				val1 = mergeAdd(val1, val2);
			else  //op1 == 1
				val1 = mergeMinus(val1, val2);
		}
		else
		{
			//计算两次, 注意这个goto
			if (op1 == 2)  //先计算第一个乘法, 再计算一次
			{
				val1 = mergeMul(val1, val2);
				val2 = val3;
				op1 = op2;
				goto op2_none;
			}
			else if (op2 == 2)
			{
				val2 = mergeMul(val2, val3);
				goto op2_none;
			}
			else if (op1 == 0)
			{
				val1 = mergeAdd(val1, val2);
				val2 = val3;
				op1 = op2;
				goto op2_none;
			}
			else  //op1 == 1
			{
				val1 = mergeMinus(val1, val2);
				val2 = val3;
				op1 = op2;
				goto op2_none;
			}
		}
		return pair<vector<SingleVariable>, int>{val1, startloc + 1}; //得跳过右括号
	}

	//读取操作符
	//必须保证vexpression[loc]是一个操作符
	//返回0:+, 1:-, 2:*
	int readop(const vector<string>& vexpression, const int& loc)
	{
		if (vexpression[loc] == "+") return 0;
		else if (vexpression[loc] == "-") return 1;
		else return 2;
	}

	//直接返回vexpression[loc]对应的内容(字符或数字)
	//返回值:键是元素, 值是乘积因子, 如果是个常数, 那么键是"!"
	vector<SingleVariable> extract(const vector<string>& vexpression, const int& loc)
	{
		SingleVariable singlevar;
		//只要第一个字符是数字那就是数字了
		if (isdigit(vexpression[loc][0])) singlevar.multi_factor = atoi(vexpression[loc].c_str());
		else
		{
			vector<string>::iterator iter = find(gblevalvars.begin(), gblevalvars.end(), vexpression[loc]);
			if (iter != gblevalvars.end()) singlevar.multi_factor = gblevalints[iter - gblevalvars.begin()];
			else
			{
				singlevar.isconstant = false;
				singlevar.val[vexpression[loc]] = 1;
			}
		}
		vector<SingleVariable> res;
		res.push_back(singlevar);
		return res;
	}

    //笛卡尔积
	//返回值:键是元素, 值是乘积因子, 如果是个常数, 那么键是"!"
	vector<SingleVariable> mergeMul(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
	    //先计算
		vector<SingleVariable> res;
		for (auto& v1 : val1)
		{
			for (auto& v2 : val2)
			{
				if (v1.isconstant)
				{
					if (v2.isconstant)
					{
						SingleVariable singleval;
						singleval.multi_factor = v1.multi_factor*v2.multi_factor;
						res.push_back(singleval);
					}
					else
					{
						SingleVariable singleval;
						singleval.multi_factor = v1.multi_factor*v2.multi_factor;
						singleval.val = v2.val;
						singleval.isconstant = false;
						res.push_back(singleval);
					}
				}
				else if (v2.isconstant)
				{
					SingleVariable singleval;
					singleval.multi_factor = v1.multi_factor*v2.multi_factor;
					singleval.val = v1.val;
					singleval.isconstant = false;
					res.push_back(singleval);
				}
				else
				{
					SingleVariable singleval;
					singleval.multi_factor = v1.multi_factor*v2.multi_factor;
					//合并两个val
					unordered_map<string, int> newval;
					for (auto& iterv1 : v1.val) newval[iterv1.first] += iterv1.second;
					for (auto& iterv2 : v2.val) newval[iterv2.first] += iterv2.second;
					singleval.val = newval;
					singleval.isconstant = false;
					res.push_back(singleval);
				}
			}
		}
		//然后暴力合并相同次方项
		//非常暴力!
		vector<SingleVariable> removedup;
		while (!res.empty())
		{
			SingleVariable singleval1 = res[0];
			int loc = 1;
			while (loc < res.size())
			{
				if (singleval1.val == res[loc].val)
				{
					singleval1.multi_factor += res[loc].multi_factor;
					res.erase(res.begin() + loc);
				}
				else loc++;
			}
			removedup.push_back(singleval1);
			res.erase(res.begin());
		}
		return removedup;
	}

	//加法
	//返回值:键是元素, 值是乘积因子, 如果是个常数, 那么键是"!"
	vector<SingleVariable> mergeAdd(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
		//先计算
		vector<SingleVariable> res;
		for (auto& v1 : val1) res.push_back(v1);
		for (auto& v2 : val2) res.push_back(v2);
		//然后暴力合并相同次方项
		//非常暴力!
		vector<SingleVariable> removedup;
		while (!res.empty())
		{
			SingleVariable singleval1 = res[0];
			int loc = 1;
			while (loc < res.size())
			{
				if (singleval1.val == res[loc].val)
				{
					singleval1.multi_factor += res[loc].multi_factor;
					res.erase(res.begin() + loc);
				}
				else loc++;
			}
			removedup.push_back(singleval1);
			res.erase(res.begin());
		}
		return removedup;
	}

	//减法
	//返回值:键是元素, 值是乘积因子, 如果是个常数, 那么键是"!"
	vector<SingleVariable> mergeMinus(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
		//先计算
		vector<SingleVariable> res;
		for (auto& v1 : val1) res.push_back(v1);
		for (auto& v2 : val2)
		{
			SingleVariable singlevariable = v2;
			singlevariable.multi_factor *= -1;
			res.push_back(singlevariable);
		}
		//然后暴力合并相同次方项
		//非常暴力!
		vector<SingleVariable> removedup;
		while (!res.empty())
		{
			SingleVariable singleval1 = res[0];
			int loc = 1;
			while (loc < res.size())
			{
				if (singleval1.val == res[loc].val)
				{
					singleval1.multi_factor += res[loc].multi_factor;
					res.erase(res.begin() + loc);
				}
				else loc++;
			}
			removedup.push_back(singleval1);
			res.erase(res.begin());
		}
		return removedup;
	}

	vector<string> split(const string& expression)
	{
		vector<string> res;
		int loc = 0;
		while (loc < expression.size())
		{
			if (expression[loc] == '(') res.push_back("(");
			else if (expression[loc] == ')') res.push_back(")");
			else if (expression[loc] == ' ');
			else if (expression[loc] == '+') res.push_back("+");
			else if (expression[loc] == '-') res.push_back("-");
			else if (expression[loc] == '*') res.push_back("*");
			else
			{
				int preloc = loc;
				while (preloc < expression.size() && expression[preloc] != ' ' && expression[preloc] != ')') preloc++;
				res.push_back(expression.substr(loc, preloc - loc));
				loc = preloc - 1; //这里需要提前减一, 因为下面会loc++
			}
			loc++;
		}
		return res;
	}

	//结果排序
	//外部其实保证了不会出现次幂相同, 字典值相同的情况
	static bool msort(const SingleVariable& inputsv1, const SingleVariable& inputsv2)
	{
		SingleVariable sv1 = inputsv1;
		SingleVariable sv2 = inputsv2;
		int pow1 = 0;
		int pow2 = 0;
		if (sv1.isconstant) pow1 = 0;
		else
		{
			for (auto& iter_v : sv1.val) pow1 += iter_v.second;
		}
		if (sv2.isconstant) pow2 = 0;
		else
		{
			for (auto& iter_v : sv2.val) pow2 += iter_v.second;
		}

		if (pow1 < pow2) return false;
		else if (pow1 > pow2) return true;
		else
		{
			//暴力挑选字典值最低的, 我写不动了...
			//一定会有一个结果!
			int count = 100;
			while (count-- > 0) //设置一个循环上限, 绝对不会超出这么多次都算不出来的！
			{
				string s1 = "|";
				int s1time = -999;
				string s2 = "|";
				int s2time = -999;
				for (auto& iter_v : sv1.val)
				{
					if (iter_v.first < s1)
					{
						s1 = iter_v.first;
						s1time = iter_v.second;
					}
				}
				for (auto& iter_v : sv2.val)
				{
					if (iter_v.first < s2)
					{
						s2 = iter_v.first;
						s2time = iter_v.second;
					}
				}
				if (s1 > s2) return false;
				else if (s1 < s2) return true;
				else
				{
					if (s1time < s2time) return false;
					else if (s1time > s2time) return true;
					else
					{
						sv1.val.erase(s1);
						sv2.val.erase(s2);
						continue;
					}
				}
			}
			return true;
		}
	}

	vector<string> generateres(vector<SingleVariable> inputrawres)
	{
		vector<string> res;
		for (auto& singlevar : inputrawres)
		{
			if (singlevar.isconstant)
			{
				if (singlevar.multi_factor == 0) continue;
				res.push_back(to_string(singlevar.multi_factor));
			}
			else
			{
				if (singlevar.multi_factor == 0) continue;
				string temp = to_string(singlevar.multi_factor);
				//一个一个来
				while (!singlevar.val.empty())
				{
					//获取字典最小的变量
					string s1 = "|";
					int s1time = -999;
					for (auto& iter_v : singlevar.val)
					{
						if (iter_v.first < s1)
						{
							s1 = iter_v.first;
							s1time = iter_v.second;
						}
					}
					//然后放变量名
					for (int i = 0; i < s1time; ++i)
					{
						temp += ("*" + s1);
					}
					//去掉字典最小的变量
					singlevar.val.erase(s1);
				}
				res.push_back(temp);
			}
		}
		return res;
	}

public:
	vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
		expression = "(" + expression + ")"; //加一组括号用于开始递归
		vector<string> vexpression = split(expression);
		gblevalvars = evalvars;
		gblevalints = evalints;
		pair<vector<SingleVariable>, int> thefuckresult = calsubblock(vexpression, 0);
		//对first中的vector排序, 排序准则: 高次幂在前, 字典值小的在前
		sort(thefuckresult.first.begin(), thefuckresult.first.end(), msort);
		//生成结果
		vector<string> finalres = generateres(thefuckresult.first);
		return finalres;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<string> evalvars1 = {"e"};
	vector<int> evalints1 = {1};
	auto res1 = s->basicCalculatorIV("e + 8 - a + 5", evalvars1, evalints1);
	vector<string> evalvars2 = {  };
	vector<int> evalints2 = { };
	auto res2 = s->basicCalculatorIV("(e + 8) * (e - 8)", evalvars2, evalints2);
	vector<string> evalvars3 = {  };
	vector<int> evalints3 = {  };
	auto res3 = s->basicCalculatorIV("7 - 7", evalvars3, evalints3);

	vector<string> evalvars4 = {  };
	vector<int> evalints4 = {  };
	auto res4 = s->basicCalculatorIV("a * b * c + b * a * c * 4", evalvars4, evalints4);
	vector<string> evalvars5 = {  };
	vector<int> evalints5 = {  };
	auto res5 = s->basicCalculatorIV("((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))", evalvars5, evalints5);
	vector<string> evalvars6 = { "a", "ab" };
	vector<int> evalints6 = { 1,1 };
	auto res6 = s->basicCalculatorIV("a - ab", evalvars6, evalints6);
	return 0;
}
