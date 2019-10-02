#include "public.h"

/*
//12ms, 37.73%
//simple solution
//����

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), greater<int>());

		int i = 0;

		while ((i < citations.size()) && (citations[i] > i)) i++;
		return i;
	}
};
*/

//4ms, 89.19%
//DP����, ��Ŀ��˼�ȽϹŹ�
//������, ���Ƚ����ó������������������������ó���������
//Ȼ���������ô�����ʼ������>=��ǰ��������������, ��¼��һ��vector����

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> papers(n + 1,0);
		// ����
		for (auto& c : citations)
			papers[min(n, c)]++;
		// �ҳ����� k
		int k = n;
		for (int s = papers[n]; k > s; s += papers[k])
			k--;
		return k;
	}
};
