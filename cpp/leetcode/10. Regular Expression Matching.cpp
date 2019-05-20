#include "public.h"

//���ݷ�,�൱����,������ʹ��
//ʱ��Ҳ�ܳ� 76ms
/*

class Solution {
public:
bool isMatchSpace(string p)
{
	unsigned int plen = p.size();
	if ((plen % 2) == 1) return false;
	unsigned int loc = 0;
	while (loc < plen)
	{
		if (p[loc] == '*') return false;
		if (p[loc + 1] != '*') return false;
		else loc += 2;
	}
	return true;
}

bool isMatch(string s, string p)
{
	//���������?*���,��¼��stack��

	struct star { int sloc; int ploc; int number; };  //sloc:s����ʼloc, ploc:?*��ϵ�?����p��loc, number:ƥ������ٸ�s�е�?�ַ�
	stack<star> recall = {};

	int sloc = 0;
	int ploc = 0;
	int ssize = s.size();
	int psize = p.size();

	bool isneedjudge = false;  //�����õ��ж�

	while (true)
	{
		if (isneedjudge)
		{
			if (recall.empty()) return false;
			star last = recall.top();
			if (p[last.ploc] == '.')
			{
				//�߽��ж� //�ٴλ���
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
			}
			else
			{
				//�߽��ж� //�ٴλ���
				if ((last.sloc + last.number) >= ssize)
				{
					recall.pop();
					isneedjudge = true;
				}
				else if (s[last.sloc + last.number] == p[last.ploc])
				{
					recall.top().number++;
					sloc = last.sloc + last.number + 1;
					ploc = last.ploc + 2;
					isneedjudge = false;
				}
				else //�ٴλ���
				{
					recall.pop();
					isneedjudge = true;
				}
			}
		}
		else
		{
			if (sloc == ssize)
			{
				if (ploc == psize)
					break;
				else
				{
					//�ж�p֮�������
					if (isMatchSpace(p.substr(ploc))) break;
					else //����
						isneedjudge = true;
				}
			}
			else if (ploc == psize)
			{
				isneedjudge = true;
				//����
			}
			else
			{
				if ((p[ploc] <= 'z') && (p[ploc] >= 'a'))
				{
					//���p���������и�?*���,��ôֱ�Ӽ���stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//����ջ
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else if (s[sloc] == p[ploc])
					{
						sloc++;
						ploc++;
					}
					else //����
					{
						isneedjudge = true;
					}
				}
				else if (p[ploc] == '.')
				{
					//���p���������и�?*���,��ôֱ�Ӽ���stack
					if ((ploc < psize - 1) && (p[ploc + 1] == '*'))
					{
						//����ջ
						star pre = star();
						pre.sloc = sloc;
						pre.ploc = ploc;
						pre.number = 0;
						recall.push(pre);
						ploc += 2;
					}
					else
					{
						sloc++;
						ploc++;
					}
				}
				else  //���Ǻ���
				{
					//�ж��ǺźϷ���
					if (ploc == 0) return false;
					if (p[ploc - 1] == '*') return false;

					//����ջ
					star pre = star();
					pre.sloc = sloc - 1;
					pre.ploc = ploc - 1;
					pre.number = 0;
					recall.push(pre);
					sloc--;
					ploc++;
				}
			}
		}

	}

	return true;
}
};

*/

//��̬�滮 //8ms 99.33%

//�������¹������
//dp[i][j]��ʾsֱ����i���ַ���pֱ����j�ַ��Ƿ�ƥ��  0<=i<=s.size(),  0<=j<=p.size()
//dp��ʼ������ȫfalse���д���
//��һ�ֳ�ʼ�����ղ鿴�Ƿ����������?*��Ͻ���ѡ���Ƿ�ֵtrue

//�������µ��ƹ�ϵ
//if (p[j] = ��ĸ) if (p[j] == s[i]) dp[i][j] = d[i-1][j-1] else dp[i][j] = false;
//else if (p[j] == '.') dp[i][j] = d[i-1][j-1]
//else ̰��ƥ��*
//    if 
//    else if (p[j-1] != s[i])  dp[i][j] = d[i][j-2] ��ʾҲ�����������?*���
//    else if (p[])

class Solution {
public:
	bool isMatch(string s, string p) {

		int ssize = s.size();
		int psize = p.size();

		vector<vector<bool>> dp(ssize + 1, vector<bool>(psize + 1, false));

		dp[0][0] = true;
		//init
		for (int j = 2; j <= psize; j+=2)
			if (((p[j - 1] == '*') && (p[j - 2] != '*')) && (dp[0][j - 2]))
			    dp[0][j] = true;

		//main dp
		for (int i = 1; i <= ssize; i++)
			for (int j = 1; j <= psize; j++)
				if ((p[j - 1] == s[i - 1]) || (p[j - 1] == '.'))
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')//̰��ƥ��*
					if (j != 1) //p�ǿ�ͷ��*
					{
						if ((p[j - 2] == s[i - 1]) || (p[j - 2] == '.')) //���*ǰ������ĸ��s��Ӧλ����Ȼ�����.
						{
							//�ֱ��Ӧ*�Ե������s�ַ�;*�����ַ�,��ԭ�ַ�����;��������?*
							dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
						}
						else if (p[j - 2] == '*') return false; //ǿ���˳�,p�ַ������Ϸ�
						else //*ǰ������ĸ���Ǻ�s��Ӧλ�ò���
							dp[i][j] = dp[i][j - 2];  //���Ƿ��ܹ�����
					}
					else return false; //ǿ���˳�,p�ַ������Ϸ�
				else
					continue;

		return dp[ssize][psize];
	}
};

int main()
{
	Solution s = Solution();
	cout << s.isMatch("aa", "a*");
	cout << s.isMatch("aa", "a**");
	cout << s.isMatch("aa", "");
	cout << s.isMatch("", "a");
	cout << s.isMatch("", "");
	cout << s.isMatch("", "*");

    cout << s.isMatch("ab", ".*");
	cout << s.isMatch("aab", "c*a*b");
	cout << s.isMatch("mississippi", "mis*is*p*.");

	cout << s.isMatch("mississippi", "mis*is*ip*.");

	cout << s.isMatch("bbbba", ".*a*a");

	cout << s.isMatch("a", ".*");
	return 0;
}

