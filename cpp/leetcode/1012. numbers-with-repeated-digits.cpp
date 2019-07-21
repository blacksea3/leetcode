#include "public.h"

//8ms, 71.19%
//������, ����û���κ�1λ�ظ������ָ���

class Solution {
private:
	//����n!
	int muls(int n)
	{
		int res = 1;
		for (int i = 1; i <= n; ++i)
		{
			res *= i;
		}
		return res;
	}

	//����A(a,b), a <= b;
	int fac(int a, int b)
	{
		return muls(b) / muls(b - a);
	}

public:
	int numDupDigitsAtMostN(int N) {
		int cpN = N;
		int l = 0;
		vector<int> nums;
		while (N > 0)
		{
			l++;
			nums.insert(nums.begin(), N % 10);
			N /= 10;
		}

		//����λ��С��l�ķ��ظ����ָ���
		int nodup = 0;

		for (int i = 1; i < nums.size(); ++i)
		{
			nodup += 9 * fac(i - 1, 9);
		}

		//�����0λ����iλ�Ƿ����ظ���
		unordered_set<int> temp_outer;
		vector<bool> hasdup(nums.size(), true);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (find(temp_outer.begin(), temp_outer.end(), nums[i]) == temp_outer.end())
			{
				temp_outer.insert(nums[i]);
				hasdup[i] = false;
			}
			else break;
		}


		//����lλ, С�ڵ���N���ظ����ָ���, �ӵ�nodup��
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && hasdup[i-1]) //�����0����iλ���ظ���, ��break
				break;

			int first = nums[i];  //��iλ���ܷŶ���������
			if (i == 0) first--;
			if (i == nums.size() - 1) first++;

			unordered_set<int> temp;
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					if (find(temp.begin(), temp.end(), nums[j]) == temp.end())
					{
						first--;
						temp.insert(nums[j]);
					}
				}
				else if (nums[j] == nums[i] && i == nums.size() - 1)
				{
					if (find(temp.begin(), temp.end(), nums[j]) == temp.end())
					{
						first--;
						temp.insert(nums[j]);
					}
				}
			}

			int rem = 10;         //�����λ���ܷŶ���������
			unordered_set<int> pn;
			for (int j = 0; j < i; ++j)
			{
				if (find(pn.begin(), pn.end(), nums[j]) == pn.end())
				{
					pn.insert(nums[j]);
					rem--;
				}
			}
			rem--;  //������iλ��
    		nodup += first * fac(nums.size() - 1 - i, rem); //nums.size() - 1 - i: ���ж���λ
		}

		return cpN - nodup;
	}
};

int main()
{
	Solution* s = new Solution();
	//cout << s->numDupDigitsAtMostN(20) << endl;
	//cout << s->numDupDigitsAtMostN(100) << endl;
	//cout << s->numDupDigitsAtMostN(1000) << endl;
	cout << s->numDupDigitsAtMostN(110) << endl;
	return 0;
}
