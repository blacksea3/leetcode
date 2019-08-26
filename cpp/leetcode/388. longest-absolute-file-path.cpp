#include "public.h"

//4ms, 91.18%
//Backtracking
//����д��

class Solution {
public:
	int sum(vector<int>& v) {
		int n = 0;
		for (int i : v)
			n += i;
		return n;
	}
	int lengthLongestPath(string input) {
		const int length = input.size();
		vector<int> v;  //�൱��stack
		bool cal = false;  //�Ƿ���Ҫ����
		int level = 0;  //����
		int det = 0;    //��ֵ(temp����)
		int answer = 0; //���
		int j = -1;   //ǰһ�������ļ�/�ļ����ַ�����βloc(��'\n')
		for (int i = 0; i < length;) {  //i�ǵ�ǰloc
			while (input[i] == '\t')
				++i;
			level = i - j - 1;
			det = v.size() - level;
			for (int k = 0; k < det; ++k) v.pop_back();  //����ǰ���ļ���
			for (j = i; j < length && input[j] != '\n'; ++j)  //ͻ����ȡ, ֱ��j='\n'
				if (input[j] == '.')
					cal = true;
			v.push_back(level ? j - i + 1 : j - i);  //������Ǹ�Ŀ¼, �򳤶Ȼ���Ҫ����\
            level = 0;
			if (cal) {
				answer = max(answer, sum(v));
				cal = false;
			}
			i = j + 1;  //����i��λ��(��ǰlocλ��)
		}
		return answer;
	}
};


