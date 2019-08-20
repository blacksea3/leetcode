#include "public.h"

//8ms, 86.32%
//题目没有说, 但我假定C/D操作之前应当有合适数量的得分
//栈

class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> stackScores;
		int resScore = 0;

		for (auto& op : ops)
		{
			if (op == "+")
			{
				int newestScore = stackScores.top();
				stackScores.pop();
				int secondScore = stackScores.top();
				resScore += newestScore + secondScore;
				stackScores.push(newestScore);
				stackScores.push(newestScore + secondScore);
			}
			else if (op == "D")
			{
				int newestScore = stackScores.top();
				resScore += 2 * newestScore;
				stackScores.push(2 * newestScore);
			}
			else if (op == "C")
			{
				int newestScore = stackScores.top();
				stackScores.pop();
				resScore -= newestScore;
			}
			else
			{
				int preScore = atoi(op.c_str());
				stackScores.push(preScore);
				resScore += preScore;
			}
		}
		return resScore;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	//vector<string> ops = { "5","2","C","D","+" };
	//auto res = s->calPoints(ops);
	vector<string> ops2 = { "5","-2","4","C","D","9","+","+" };
	auto res = s->calPoints(ops2);
	return 0;
}
*/
