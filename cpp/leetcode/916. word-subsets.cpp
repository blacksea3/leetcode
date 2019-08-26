#include "public.h"

//448ms, 27.06%
//����, ͳ��A����ĸ����, B����ĸ����
//Ȼ���B�ĸ�����ĸ���ָ������max, �ó�һ������������ĸ������A�Ƚϼ���

class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<int> charnums(256, 0);
		for (int i = 0; i < B.size(); ++i)
		{
			vector<int> tempcharnums(256, 0);
			for (auto& iis : B[i])
			{
				tempcharnums[iis]++;
			}
			for (char c = 'a'; c <= 'z'; ++c)
			{
				charnums[c] = max(charnums[c], tempcharnums[c]);
			}
		}

		vector<string> res;
		for (int i = 0; i < A.size(); ++i)
		{
			vector<int> Anums(256, 0);
			for (auto& iis : A[i])
			{
				Anums[iis]++;
			}

			bool ispass = true;
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (Anums[c] < charnums[c])
				{
					ispass = false;
					break;
				}
			}
			if (ispass) res.push_back(A[i]);
		}
		return res;
	}
};
