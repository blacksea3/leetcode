#include "public.h"

//0ms, 100%
//�޸��ӵ�̰����Ŀ
//��ͳ���ַ�����ȱʧ���Լ�����3�������ַ���������(�ŵ�vector), Ȼ�󳤶ȷ���
//����<6,   ��Ҫ��Ӻ�/���滻�ַ�, ʵ���Ͻ�������ȱʧ�ַ���������ȱʧ�ַ����ȵ����ֵ����
//����OK,   ����OK, �������滻�ַ�, ���������ճ���/3����
//����>20,  ��Ҫɾ����/���滻�ַ�
//   ���ȿ����ַ����಻ȫ, ���滻����:
//       �������������>=3���ַ���, �����滻 ����%3==2��, ���%3==1, ���%3==0, �滻��˳��ȼ���
//       ����Ĭ���滻���ұߵ��ַ�, ��δ��ұߵ�
//   Ȼ����ͼɾ���ַ�
//       �������������>=3���ַ���, ����ɾ��: ����%3==0��, ���%3==1, ���%3==2, ɾ����˳��ȼ�1
//       ����Ĭ��ɾ�����ұߵ��ַ�, ������ұ��ַ��Ƕ���������ɾ�����ұߵ�, �Դ�����, �˷���ּ�ڱ�֤�������µĹ����Ӵ�
//   ����ճ���OK����ʣ��Ĵ���3�������ַ���������, ����еĻ�

class Solution {
public:
	int strongPasswordChecker(string s) {
		if (s.empty()) return 6;

		bool hasLow, hasHigh, hasNum;
		hasLow = hasHigh = hasNum = false;
		int len = s.size();
		vector<int> lengthsBiggerThanThree;  //����3�������ַ���������

		int preLen = 0;
		char old = s[0] + 1;

		for (auto& iters : s)
		{
			if ('a' <= iters && iters <= 'z') hasLow = true;
			if ('A' <= iters && iters <= 'Z') hasHigh = true;
			if ('0' <= iters && iters <= '9') hasNum = true;
			if (old != iters)
			{
				if (preLen >= 3)
				{
					lengthsBiggerThanThree.emplace_back(preLen);
				}
				old = iters;
				preLen = 1;
			}
			else preLen++;
		}
		if (preLen >= 3)
		{
			lengthsBiggerThanThree.emplace_back(preLen);
		}

		//����С��6
		if (len < 6) //��Ҫ��Ӻ�/���滻�ַ�, ʵ���Ͻ�������ȱʧ�ַ���������ȱʧ�ַ����ȵ����ֵ����
		{
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			return max(lack, 6 - len);
		}
		else if (len > 20)  //�鷳, ��Ҫɾ����/���滻�ַ�
		{
			//��ͳ��ȱʧ�ַ�����
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			int res = 0;
			//Ȼ�����Ƿ���Ҫ�滻��������ַ�, �����������Ļ�, ��ô�����滻 ����%3==2��, ���%3==1, ���%3==0
			while (lack > 0)
			{
				if (!lengthsBiggerThanThree.empty())
				{
					//Ѱ�ҳ���%3==2��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 2)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
					//Ѱ�ҳ���%3==1��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 1)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
					//Ѱ�ҳ���%3==0��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 0)
						{
							lengthsBiggerThanThree[i] -= 3;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlack;
						}
					}
				}
				//û��, ��ôֱ���滻, û�ж������
			nextlack: //�����res��lack��Ϣ
				res++;
				lack--;
			}
			//Ȼ���ǵ�ǰ����: ����ɾ��: ����ɾ���ظ��ַ���: �����Ͼ��Բ����ܾ���ɾ�������µ��ظ��ַ�, ��Ϊ����ɾ����������<3�����ַ����ڵ��ַ�
			while (len > 20)
			{
				//ɾ�����ȼ�: ����%3==0��, ���%3==1, ���%3==2
				for (auto& iters : lengthsBiggerThanThree)
				{
					//Ѱ�ҳ���%3==0��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 0)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
					//Ѱ�ҳ���%3==1��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 1)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
					//Ѱ�ҳ���%3==2��
					for (int i = 0; i < lengthsBiggerThanThree.size(); ++i)
					{
						if (lengthsBiggerThanThree[i] % 3 == 2)
						{
							lengthsBiggerThanThree[i]--;
							if (lengthsBiggerThanThree[i] < 3) lengthsBiggerThanThree.erase(lengthsBiggerThanThree.begin() + i);
							goto nextlen;
						}
					}
				}
				//ɶ���Ҳ���, ��ôĬ�ϴ����ұ߿�ʼɾ���ַ�, ���ɾ���Ǹ��ַ�����ĳ������ȱʧ, ��ôɾ�������ڶ���...
				//ע��: ���Բ�����ɾ��ĳ���ַ����³��������ַ���>=3, ������ΪҪôɾ�����ұߵ��ַ�
				//Ҫô���ұ��ַ��Ƕ�һ�޶�����
			nextlen:
				len--;
				res++;
			}
			//����滻�ַ�
			for (auto& iters : lengthsBiggerThanThree)
			{
				res += iters / 3;
			}
			return res;
		}
		else  //����OK, �������滻�ַ�
		{
			int lack = 0;
			if (!hasLow) lack++;
			if (!hasHigh) lack++;
			if (!hasNum) lack++;
			int subMultipleChar = 0;
			for (auto& iters : lengthsBiggerThanThree)
			{
				subMultipleChar += iters / 3;
			}
			return max(lack, subMultipleChar);
		}
	}
};

/*
int main()
{
	Solution* s = new Solution();
	cout << s->strongPasswordChecker("") << endl;							//6
	cout << s->strongPasswordChecker("aaa111") << endl;						//2
	cout << s->strongPasswordChecker("ABABABABABABABABABAB1") << endl;		//2
	return 0;
}
*/
