#include "public.h"

//4ms, 90.36%
//���鼯, ��ԭ�������ṹ, �˴����޸ĳ�unordered_set�ṹ, ���ڲ��洢���������
//��Ŀ��˵: ����ì��, �Ҳ������Ϊ0, ��������

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<unordered_map<string, double>> nums; //map: char: pseudo_value

		for (int i = 0; i < equations.size(); ++i)
		{
			//Ѱ�������ַ������ڵ�nums�±�
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

			//���࿼��
			if ((firstloc == -1) && (secondloc == -1)) //��������
			{
				unordered_map<string, double> newus;
				newus[secondch] = 1.0;
				newus[firstch] = values[i];
				nums.push_back(newus);
			}
			else if (firstloc == -1)  //equations[i][1]����
			{
				double temp_first_val = nums[secondloc][secondch] * values[i];
				nums[secondloc][firstch] = temp_first_val;
			}
			else if (secondloc == -1)  //equations[i][0]����
			{
				double temp_first_val = nums[firstloc][firstch] / values[i];
				nums[firstloc][secondch] = temp_first_val;
			}
			else //������
			{
				if (firstloc != secondloc) //��Ȼ��Ŀ˵��ì��, �����ʱ������
				{
					//����˻�����
					double first_mulpara = nums[secondloc][secondch] * values[i] / nums[firstloc][firstch];
					//�޸�firstloc
					for (auto& mdict : nums[firstloc]) mdict.second *= first_mulpara;
					//�ϲ�secondloc��firstloc
					for (auto& mdict : nums[secondloc]) nums[firstloc][mdict.first] = mdict.second;
					//ɾ��secondloc
					nums.erase(nums.begin() + secondloc);
				}
			}
		}

		//��������
		vector<double> res(queries.size(), 0);
		for (int i = 0; i < queries.size(); ++i)
		{
			int firstloc = -1;
			int secondloc = -1;
			string firstch = queries[i][0];
			string secondch = queries[i][1];
			//Ѱ�������ַ������ڵ�nums�±�
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
