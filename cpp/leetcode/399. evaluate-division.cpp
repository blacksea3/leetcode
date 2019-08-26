#include "public.h"

//4ms, 90.36%
//并查集, 其原本是树结构, 此处我修改成unordered_set结构, 其内部存储假设的数据
//题目所说: 不会矛盾, 且不会除数为0, 都是正的

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<unordered_map<string, double>> nums; //map: char: pseudo_value

		for (int i = 0; i < equations.size(); ++i)
		{
			//寻找两个字符串所在的nums下标
			int firstloc = -1;
			int secondloc = -1;
			string firstch = equations[i][0];
			string secondch = equations[i][1];

			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[j].find(firstch) != nums[j].end()) firstloc = j;
				if (nums[j].find(secondch) != nums[j].end()) secondloc = j;
				if ((firstloc != -1) && (secondloc != -1)) break;
			}

			//分类考虑
			if ((firstloc == -1) && (secondloc == -1)) //都不存在
			{
				unordered_map<string, double> newus;
				newus[secondch] = 1.0;
				newus[firstch] = values[i];
				nums.push_back(newus);
			}
			else if (firstloc == -1)  //equations[i][1]存在
			{
				double temp_first_val = nums[secondloc][secondch] * values[i];
				nums[secondloc][firstch] = temp_first_val;
			}
			else if (secondloc == -1)  //equations[i][0]存在
			{
				double temp_first_val = nums[firstloc][firstch] / values[i];
				nums[firstloc][secondch] = temp_first_val;
			}
			else //都存在
			{
				if (firstloc != secondloc) //既然题目说不矛盾, 则相等时不处理
				{
					//计算乘积因子
					double first_mulpara = nums[secondloc][secondch] * values[i] / nums[firstloc][firstch];
					//修改firstloc
					for (auto& mdict : nums[firstloc]) mdict.second *= first_mulpara;
					//合并secondloc至firstloc
					for (auto& mdict : nums[secondloc]) nums[firstloc][mdict.first] = mdict.second;
					//删除secondloc
					nums.erase(nums.begin() + secondloc);
				}
			}
		}

		//计算结果咯
		vector<double> res(queries.size(), 0);
		for (int i = 0; i < queries.size(); ++i)
		{
			int firstloc = -1;
			int secondloc = -1;
			string firstch = queries[i][0];
			string secondch = queries[i][1];
			//寻找两个字符串所在的nums下标
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[j].find(firstch) != nums[j].end()) firstloc = j;
				if (nums[j].find(secondch) != nums[j].end()) secondloc = j;
				if ((firstloc != -1) && (secondloc != -1)) break;
			}

			if ((firstloc == secondloc) && (firstloc != -1)) res[i] = nums[firstloc][firstch] / nums[secondloc][secondch];
			else res[i] = -1.0;
		}
		return res;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
	vector<double> values = { 2.0, 3.0 };
	vector<vector<string>> queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
	auto res = s->calcEquation(equations, values, queries);
	return 0;
}
*/
