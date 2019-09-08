#include "public.h"

//4ms, 78.33%
//实现一个分数类

class Fraction {
private:
	int mother;
	int son;
public:
	//外部注意分子可正可负可0, 分母必须正整数
	Fraction(int inputSon = 0, int inputMother = 1)
	{
		mother = inputMother;
		son = inputSon;
	}

	//外部注意相加的时候至少一个数不为0
	//支持分子是负数
	void add(Fraction& inputF)
	{
		int newMother = inputF.mother * this->mother;
		int newSon = inputF.son * this->mother + inputF.mother * this->son;
		int publicMulFactor = gcd(abs(newMother), abs(newSon));
		this->mother = newMother / publicMulFactor;
		this->son = newSon / publicMulFactor;
	}

	int getSon()
	{
		return this->son;
	}

	int getMother()
	{
		return this->mother;
	}
};

class Solution {
public:
	string fractionAddition(string expression) {
		//获取第一个数
		bool isPositive;
		int index = 0;
		int oldindex = 0;
		Fraction preF = Fraction();
		if (expression[index] != '-')
		{
			isPositive = true;
			while (expression[index] != '/') index++;
			int tempson = atoi(expression.substr(0, index).c_str());
			index++;
			oldindex = index;
			while (index < expression.size() && expression[index] != '+' && expression[index] != '-') index++;
			int tempmother = atoi(expression.substr(oldindex, index - oldindex).c_str());
			Fraction tempF = Fraction(tempson, tempmother);
			preF = tempF;
			cout << "son:" << tempson << " mother:" << tempmother << endl;
		}
		else
		{
			isPositive = false;
			index++;
			while (expression[index] != '/') index++;
			int tempson = atoi(expression.substr(1, index).c_str());
			index++;
			oldindex = index;
			while (index < expression.size() && expression[index] != '+' && expression[index] != '-') index++;
			int tempmother = atoi(expression.substr(oldindex, index - oldindex).c_str());
			tempson *= -1;
			Fraction tempF = Fraction(tempson, tempmother);
			preF = tempF;
			cout << "son:" << tempson << " mother:" << tempmother << endl;
		}

		while (index < expression.size())
		{
			if (expression[index] == '+') isPositive = true;
			else isPositive = false;
			index++;
			oldindex = index;

			while (expression[index] != '/') index++;
			int tempson = atoi(expression.substr(oldindex, index - oldindex).c_str());
			index++;
			oldindex = index;
			while (index < expression.size() && expression[index] != '+' && expression[index] != '-') index++;
			int tempmother = atoi(expression.substr(oldindex, index - oldindex).c_str());
			if (!isPositive) tempson *= -1;
			Fraction tempF = Fraction(tempson, tempmother);
			preF.add(tempF);
			cout << "son:" << tempson << " mother:" << tempmother << endl;
		}
		return to_string(preF.getSon()) + "/" + to_string(preF.getMother());
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->fractionAddition("-1/2+1/2");
	return 0;
}
*/
