#include "public.h"

//44ms, 66.67%
//��ת��expression��vector<string>, Ȼ�������cal����, ���������ֵ

class Solution {
private:
	vector<string> gblevalvars;  //ȫ�ֵı����ַ���
	vector<int> gblevalints;     //ȫ�ֵı���ֵ

	//���isconstant:true ��Ϊ����, multi_factor��Ч
	//�����ʾ���val�е�string��int�η���multi_factor
	struct SingleVariable
	{
		unordered_map<string, int> val;
		bool isconstant = true;
		int multi_factor = 1;
	};

	//�����vexpression[startloc]�������һ�������ŵ�ֵ, �����ݹ����, ע��: vexpression[startloc]һ����һ��������
	//������Ԫ��ѭ����: ÿ����ȡǰ����ֵ�Լ�ǰ����������, �������ȼ�������μ���
	//�߽������ܸ���

	//����Ӧ�ñ�֤startloc��Խ��
	//����ֵfirst: ����Ԫ��, ֵ�ǳ˻�����, ����Ǹ�����, ��ô����"!", ����ֵsecond:�����ŵ���һ��λ��(�������λ����vexpressionĩβ)
	//����Ԫ�غ���: ����һ���ַ�����#��һ������, ��ʾ����ַ��������ִη�
	pair<vector<SingleVariable>, int> calsubblock(const vector<string>& vexpression, int startloc)
	{
		//����: val1 op1 val2 op2 val3, ע��û������, ���������, ����ݹ���ǰ��������Ӧ��um��
		vector<SingleVariable> val1;
		vector<SingleVariable> val2;
		vector<SingleVariable> val3;
		int op1 = -1;  //-1: δ����(��ֻ��val1����˼), 0:+, 1:-, 2:*
		int op2 = -1;  //-1: δ����(��ֻ��val1\op1\val2����˼)

		startloc++; //������ǰ��ε�������
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
			//��ȡop1��val2
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
			//��ȡop2��val3
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
			//����
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

		//������: �ж�op1��op2, ����ټ���һ��
		if (op1 == -1)  //�������һ�������ھ͵�����һ������/����, ���ü�����
			;
		else if (op2 == -1) //�������һ�������ھ͵�����һ�������
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
			//��������, ע�����goto
			if (op1 == 2)  //�ȼ����һ���˷�, �ټ���һ��
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
		return pair<vector<SingleVariable>, int>{val1, startloc + 1}; //������������
	}

	//��ȡ������
	//���뱣֤vexpression[loc]��һ��������
	//����0:+, 1:-, 2:*
	int readop(const vector<string>& vexpression, const int& loc)
	{
		if (vexpression[loc] == "+") return 0;
		else if (vexpression[loc] == "-") return 1;
		else return 2;
	}

	//ֱ�ӷ���vexpression[loc]��Ӧ������(�ַ�������)
	//����ֵ:����Ԫ��, ֵ�ǳ˻�����, ����Ǹ�����, ��ô����"!"
	vector<SingleVariable> extract(const vector<string>& vexpression, const int& loc)
	{
		SingleVariable singlevar;
		//ֻҪ��һ���ַ��������Ǿ���������
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

    //�ѿ�����
	//����ֵ:����Ԫ��, ֵ�ǳ˻�����, ����Ǹ�����, ��ô����"!"
	vector<SingleVariable> mergeMul(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
	    //�ȼ���
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
					//�ϲ�����val
					unordered_map<string, int> newval;
					for (auto& iterv1 : v1.val) newval[iterv1.first] += iterv1.second;
					for (auto& iterv2 : v2.val) newval[iterv2.first] += iterv2.second;
					singleval.val = newval;
					singleval.isconstant = false;
					res.push_back(singleval);
				}
			}
		}
		//Ȼ�����ϲ���ͬ�η���
		//�ǳ�����!
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

	//�ӷ�
	//����ֵ:����Ԫ��, ֵ�ǳ˻�����, ����Ǹ�����, ��ô����"!"
	vector<SingleVariable> mergeAdd(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
		//�ȼ���
		vector<SingleVariable> res;
		for (auto& v1 : val1) res.push_back(v1);
		for (auto& v2 : val2) res.push_back(v2);
		//Ȼ�����ϲ���ͬ�η���
		//�ǳ�����!
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

	//����
	//����ֵ:����Ԫ��, ֵ�ǳ˻�����, ����Ǹ�����, ��ô����"!"
	vector<SingleVariable> mergeMinus(const vector<SingleVariable>& val1,
		const vector<SingleVariable>& val2)
	{
		//�ȼ���
		vector<SingleVariable> res;
		for (auto& v1 : val1) res.push_back(v1);
		for (auto& v2 : val2)
		{
			SingleVariable singlevariable = v2;
			singlevariable.multi_factor *= -1;
			res.push_back(singlevariable);
		}
		//Ȼ�����ϲ���ͬ�η���
		//�ǳ�����!
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
				loc = preloc - 1; //������Ҫ��ǰ��һ, ��Ϊ�����loc++
			}
			loc++;
		}
		return res;
	}

	//�������
	//�ⲿ��ʵ��֤�˲�����ִ�����ͬ, �ֵ�ֵ��ͬ�����
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
			//������ѡ�ֵ�ֵ��͵�, ��д������...
			//һ������һ�����!
			int count = 100;
			while (count-- > 0) //����һ��ѭ������, ���Բ��ᳬ����ô��ζ��㲻�����ģ�
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
				//һ��һ����
				while (!singlevar.val.empty())
				{
					//��ȡ�ֵ���С�ı���
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
					//Ȼ��ű�����
					for (int i = 0; i < s1time; ++i)
					{
						temp += ("*" + s1);
					}
					//ȥ���ֵ���С�ı���
					singlevar.val.erase(s1);
				}
				res.push_back(temp);
			}
		}
		return res;
	}

public:
	vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
		expression = "(" + expression + ")"; //��һ���������ڿ�ʼ�ݹ�
		vector<string> vexpression = split(expression);
		gblevalvars = evalvars;
		gblevalints = evalints;
		pair<vector<SingleVariable>, int> thefuckresult = calsubblock(vexpression, 0);
		//��first�е�vector����, ����׼��: �ߴ�����ǰ, �ֵ�ֵС����ǰ
		sort(thefuckresult.first.begin(), thefuckresult.first.end(), msort);
		//���ɽ��
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
