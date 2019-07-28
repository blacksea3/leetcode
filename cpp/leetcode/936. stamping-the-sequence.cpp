#include "public.h"

//28ms, 86.67%
//init: ��ȥ���������stamp, �ĳ�?, �⽫ʣ�´����ļ�ϲ���, ����vector<vector<int,int>> v
//������:��v��Ԫ����������: ��ÿ��Ԫ�ص���ߺ�stamp���ұ����ص�����, ����ȥ���ص�����; ��ÿ��Ԫ�ص��ұߺ�stamp��������ص�����, ����ȥ���ص�����
//���Ԫ�س���ȥ����, ��ôɾ����, ����Ԫ��һ������, �����и��������: ���Ԫ�س���<stamp������v���м�ĳһ��, ��ôҲ��ȥ��
//�տ�ʼ�޷���ȥ������stamp����v��ĳ��Ԫ�����Ҷ�û����v�ص�, ��ô����ӡ������
//ʵ�ʵ�˳�������ĳ���˳���Ƿ���

class Solution {
private:
	//�ж�target[begin:end+1] �ǲ���stamp���Ӵ�, ���򷵻���ʼλ��, �����򷵻�-1
	//maxsleft��������������, maxsright���ұ����������
	int issubstr(const string& target, int begin, int end, string stamp, int maxsleft, int maxsright)
	{
		int len = end - begin + 1;
		string s = target.substr(begin, len);
		for (int i = max(0, (int)stamp.size() - maxsright - 1); i <= stamp.size() - len; ++i)
		{
			if (i > maxsleft) break;
			if (stamp.substr(i, len) == s) return i;
		}
		return -1;
	}
	//��ÿ��Ԫ�ص���ߺ�stamp���ұ����ص�����, ���ع�������
	int overlap_tleft_sright(const string& target, int begin, int end, string stamp)
	{
		int lenm1 = min((int)stamp.size() - 1, end - begin + 1) - 1;
		int ssize = stamp.size();
		for (int i = lenm1; i >= 0; --i)
		{
			string t = target.substr(begin, i + 1);
			string s = stamp.substr(ssize - i - 1, i + 1);
			if (target.substr(begin, i + 1) == stamp.substr(ssize - i - 1, i + 1)) return i + 1;
		}
		return 0;
	}

	//��ÿ��Ԫ�ص��ұߺ�stamp��������ص�����, ���ع�������
	int overlap_tright_sleft(const string& target, int begin, int end, string stamp)
	{
		int lenm1 = min((int)stamp.size() - 1, end - begin + 1) - 1;
		for (int i = lenm1; i >= 0; --i)
		{
			string t = target.substr(end - i, i + 1);
			string s = stamp.substr(0, i + 1);
			if (target.substr(end - i, i + 1) == stamp.substr(0, i + 1)) return i+1;
		}
		return 0;
	}

public:
	vector<int> movesToStamp(string stamp, string target) {
		//��ʼ��
		//����
		int lastright = -1;
		vector<int> res;

		vector<vector<int>> v;
		bool notgood = true;
		for (int i = 0; i <= target.size() - stamp.size();)
		{
			if (target.substr(i, stamp.size()) == stamp)
			{
				res.push_back(i);
				notgood = false;
				//���
				if (i > lastright + 1)
				{
					v.push_back({ lastright + 1, i - 1 });
				}
				lastright = i + stamp.size() - 1;
				i += stamp.size();
			}
			else i++;
		}
		if (notgood) return {}; //ǿ���˳�

		if (target.size() > lastright + 1) v.push_back({ lastright + 1, (int)target.size() - 1 });

		//����������v
		while (!v.empty())
		{
			vector<vector<int>> next;
			//���������Ӵ�
			for (auto& iv : v)
			{
				if ((iv[1] - iv[0] + 1) < stamp.size())
				{
					int tempres = issubstr(target, iv[0], iv[1], stamp, iv[0], target.size() - iv[1] - 1);
					if (tempres != -1)
					{
						res.push_back(iv[0] - tempres);
					}
					else
					{
						next.push_back({ iv[0],iv[1] });
					}
				}
				else next.push_back({ iv[0],iv[1] });
			}
			//��һ����������ȥ��һЩ�����Ӵ�
			//�����ٶ�next��������, �������ܲ��ܱ��
			vector<vector<int>> next2;
			for (auto& in : next)
			{
				//��ÿ��Ԫ�ص���ߺ�stamp���ұ����ص�����
				int templen1 = overlap_tleft_sright(target, in[0], in[1], stamp);
				//��ÿ��Ԫ�ص��ұߺ�stamp��������ص�����
				int templen2 = overlap_tright_sleft(target, in[0], in[1], stamp);
				//�����������ȺϷ���:
				if ((in[1] - templen2 + 1 + stamp.size()) > target.size()) templen2 = 0;
				if (in[0] - ((int)stamp.size() - templen1) < 0) templen1 = 0;

				//���
				int totallen = templen1 + templen2;
				if (totallen == 0) return {}; //ǿ���˳�
				else
				{
					int tlen = in[1] - in[0] + 1;
					if (totallen >= tlen)
					{
						//���templen1, �ұ�templen2
						if (templen2) res.push_back(in[1] - templen2 + 1);
						if (templen1) res.push_back(in[0] - ((int)stamp.size() - templen1));
					}
					else
					{
						//���templen1, �ұ�templen2
						if (templen2) res.push_back(in[1] - templen2 + 1);
						if (templen1) res.push_back(in[0] - ((int)stamp.size() - templen1));
						next2.push_back({ in[0] + templen1, in[1] - templen2 });
					}
				}
			}
			v = next2;
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	//auto res = s->movesToStamp("abca", "aabcaca");
	//auto res = s->movesToStamp("oz", "ooozz");
	//auto res = s->movesToStamp("vba", "vvbvbavbaa");
	//auto res = s->movesToStamp("cab", "cabbb");
	//auto res = s->movesToStamp("ffebb", "fffeffebbb");
	auto res = s->movesToStamp("abca", "aabcaca");
	return 0;
}
