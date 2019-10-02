#include "public.h"

//12ms, 100%
//����

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int cSize = citations.size();
		// ����
		if (cSize == 0 || citations[cSize - 1] == 0) return 0;

		int left = 0;
		int right = cSize - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			// �ȳ���С���͵�ȥ����ֵ
			if (citations[mid] < cSize - mid) {
				left = mid + 1;
			}
			else {
				// �ȳ��ȴ�������ģ�����Ӧ�ü����� mid ������ȥ���Կ���û�и�С�� mid ֵ
				// �������� mid ��Ӧ��ֵ���ڵ��ڴ� [mid, cSize - 1] �ĳ���
				right = mid;
			}
		}
		return cSize - left;
	}
};


//20ms, 91.95%
//O(n)
//����274��, һƪһƪ���ô������� �� ������

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int i = 0;
		int cSize = citations.size();

		while ((i < cSize) && (citations[cSize - i - 1] > i)) i++;
		return i;
	}
};
