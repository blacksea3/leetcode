#include "public.h"

//TLE
//���͵��߶���
//Ŀǰ���������ǵ��߶���, ʱ�临�Ӷ�O(nnlogn) �ȱ�������...

class Solution {
private:
	struct Node
	{
		int l = -1;
		int r = -1;
		long long sum = -999;
	};
	vector<Node*> nodes;
	vector<int> values;
	void build(int l, int r, int nindex)
	{
		nodes[nindex]->l = l;
		nodes[nindex]->r = r;
		if (l == r)
		{
			nodes[nindex]->sum = values[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, 2 * nindex + 1);
		build(mid + 1, r, 2 * nindex + 2);
		nodes[nindex]->sum = nodes[2 * nindex + 1]->sum + nodes[2 * nindex + 2]->sum;
	}

	//���µ���Ľڵ�ֵ, ʵ�ʴ���absv����ֵ������
	//ע��: ������������Ǵ��!
	void update(int l, int r, int nindex, const int& modifyloc, const int& absv)
	{
		nodes[nindex]->sum += modifyloc;

		if (l == r) return;
		int mid = (l + r) / 2;
		if (modifyloc <= mid) update(l, mid, nindex + 1, modifyloc, absv);
		else update(mid + 1, r, nindex + 2, modifyloc, absv);
	}

	//��ѯ[ql, qr]�������
	long long query(int l, int r, int nindex, const int& ql, const int& qr)
	{
		if (l == r) return nodes[nindex]->sum;
		else
		{
			int mid = (l + r) / 2;
			if (qr <= mid) return query(l, mid, 2 * nindex + 1, ql, qr);
			else if (ql > mid) return query(mid + 1, r, 2 * nindex + 2, ql, qr);
			else return query(l, mid, 2 * nindex + 1, ql, qr) + query(mid + 1, r, 2 * nindex + 2, ql, qr);
		}
	}

public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.empty()) return 0;

		int nsize = nums.size();
		nodes.resize(nsize << 2);
		for (int i = 0; i < nsize << 2; ++i)
			nodes[i] = new Node();

		values = nums;
		build(0, nsize - 1, 0);

		int res = 0;
		for (int left = 0; left < nums.size(); ++left)
		{
			for (int right = left; right < nums.size(); ++right)
			{
				long long pre = query(0, nsize - 1, 0, left, right);
				if (pre <= upper && pre >= lower) res++;
				//cout << left << " " << right << " " << pre << endl;
			}
		}
		return res;
	}
};

int main()
{
	Solution* s = new Solution();
	vector<int> nums = {-2,5,-1};
	cout << s->countRangeSum(nums, -2, 2);
	return 0;
}
