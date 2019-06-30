#include "public.h"

//ִ����ʱ :
//20 ms, ������ C++ �ύ�л�����95.00%���û���  �ٶȲ��ȶ�����������ٶ� :(  ��
//�ڴ����� :15.2 MB, ������ C++ �ύ�л�����100.00%���û�

//�������µ�˼·: ���ݹ�д��
//����ĳ���ݹ麯�������ص�ǰ������unordered_set�����
//  �Լ�һ��int���꣬�����}���ʾ�Ҵ����ŵ���һ�����꣬����һ����expression.size()����������Χ
//�˺�������
//  unordered_set<string> res;��ʾ�˺����Ľ����unordered_set<string> preset;��ʾ��ǰ���ַ�������
//����ѭ����ȡ�ַ�
// �����ȡ�����ţ���ô��preset�ӵ�res�ϣ���ǰ����+1
// �����ȡ��{�ţ���ô�ݹ���һ�㣬�����ķ���set�˵�preset�ϣ����µ�ǰ��������Ӧ���Ҵ����ŵ���һ������/�����ַ���ĩβ
// �����ȡ��}�ţ���ô��preset�ӵ�res�ϣ�����unordered_set��res�Լ�int����ǰ����+1
// ���򣨼���ĸ����ֱ��ͻ����ȡ������ĸ��Ȼ�������ַ����˵�preset�ϣ���ǰ����=������ĸĩβ 

//ѭ��������ʾ���굽expressionĩβ�ˣ���ô��preset�ӵ�res�ϣ�����unordered_set��res�Լ�int����ǰ���꣨��expressionĩβ��

//��ں�����������ݹ麯����������ֵunordered_setת����vectorȻ���Ÿ���

class Solution {
private:
	//add source to raw
	//�ӷ�
	void mergeAdd(unordered_set<string>& raw, const unordered_set<string>& source)
	{
		for (auto s : source) raw.insert(s);
	}

	//Mul source to raw
	//here if source is empty, then raw will be set {}  :)
	//�ѿ��������˷�
	void mergeMul(unordered_set<string>& raw, const unordered_set<string>& source)
	{
		if (raw.empty()) raw = source;
		else
		{
			unordered_set<string> res;
			for (auto r : raw)
				for (auto s : source)	
					res.insert(r + s);
			raw = res;
		}
	}

	pair<unordered_set<string>, int> recu_braceExpansionII(const string& expression, int startloc)
	{
		unordered_set<string> res;
		unordered_set<string> preset;
		while (startloc < expression.size())
		{
			if (expression[startloc] == ',')
			{
				mergeAdd(res, preset);
				preset.clear();
				startloc++;
			}
			else if (expression[startloc] == '{')
			{
				pair<unordered_set<string>, int> inner = recu_braceExpansionII(expression, startloc + 1);
				mergeMul(preset, inner.first);
				startloc = inner.second;
			}
			else if (expression[startloc] == '}')
			{
				mergeAdd(res, preset);
				pair<unordered_set<string>, int> returns;
				returns.first = res;
				returns.second = startloc + 1;
				return returns;
			}
			else
			{
				string curr = "";
				while (startloc < expression.size() && expression[startloc] >= 'a' && expression[startloc] <= 'z') {
					curr.push_back(expression[startloc++]);
				}
				mergeMul(preset, unordered_set<string>{curr});
			}
		}
		//������һ�����±�startloc == expression.size()
		mergeAdd(res, preset);
		pair<unordered_set<string>, int> returns;
		returns.first = res;
		returns.second = startloc;
		return returns;
	}

public:
	vector<string> braceExpansionII(string expression) {
		pair<unordered_set<string>, int> totalres = recu_braceExpansionII(expression, 0);
		vector<string> returnres(totalres.first.begin(), totalres.first.end());
		sort(returnres.begin(), returnres.end());
		return returnres;
	}
};


/*
int main()
{
	Solution* s = new Solution();
	vector<string> res = s->braceExpansionII("{a,b}{c{d,e}}");
	return 0;
}*/