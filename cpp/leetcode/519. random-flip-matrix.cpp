#include "public.h"

//�ر�ע: �˷�����Ҫ�Ľ�, һ�������ϴ��total��ģ, ��flip�����ӽ�total, ��ô��ʱ����������
//Ӧ���滻������еĺڰ׷�����
//56ms, 23.88%
//�ܾ�����, ����������ת��һ������, �Ӵ������������
//�������/����1, ��ô�������
//

class Solution {
private:
	unordered_set<int> fliped;
	int total;
	int cols;

public:
	Solution(int n_rows, int n_cols) {
		total = n_rows * n_cols;
		cols = n_cols;
	}

	vector<int> flip() {
		//ǧ��Ҫ�ھ�����û��ֵΪ 0 ʱ, ���� flip ����
		while (1)
		{
			int pre = rand() % total;
			if (fliped.count(pre) > 0)
			{
				continue;
			}
			else
			{
				fliped.insert(pre);
				return { pre / cols, pre%cols };
			}
		}
		return { -999,-999 }; //dump
	}

	void reset() {
		unordered_set<int> empty;
		fliped = empty;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
