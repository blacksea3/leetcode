#include "public.h"

//40ms, 91.86%
//�ֶ����, α�߶���

class NumArray {
private:
	vector<int> sums;
	vector<int> cpNums;
	int segSize;
	int sSize;

public:
	NumArray(vector<int>& nums) {
		int nSize = nums.size();
		if (nSize == 0) return;

		cpNums = nums;
		segSize = (int)sqrt(nSize);
		sSize = nSize / segSize;
		sums.resize(sSize);
		//��ʼ��sums: �±�i ��� nums�е�[segSize*(i-1): segSize*i)�ĺ�
		for (int index = 0; index < sSize; ++index)
		{
			sums[index] = accumulate(nums.begin() + segSize * index,
				nums.begin() + segSize * (index + 1),
				0);
		}
	}

	void update(int i, int val) {
		//��i��segSize����������, ����ȡ��
		int mulIndex = i / segSize;
		if (mulIndex != sSize) sums[mulIndex] += val - cpNums[i];
		cpNums[i] = val;
	}

	int sumRange(int i, int j) {
		//���������
		//��i/j��segSize��������, ����/��ȡ��
		//sti��ʵ��������Ͷε���ʼsums����, enj�ǽ�������
		int muli, mulj, sti, enj;
		int res = 0;

		muli = i / segSize;
		if (i%segSize != 0)  //����: segSize:3, i:1, j=7; һ���� 012 345 678
		{
			res += accumulate(cpNums.begin() + i, cpNums.begin() + (muli + 1)*segSize, 0);
			sti = muli + 1;
		}
		else sti = muli;

		mulj = j / segSize;
		if ((j + 1) % segSize != 0)
		{
			res += accumulate(cpNums.begin() + mulj * segSize, cpNums.begin() + j + 1, 0);
			enj = mulj - 1;
		}
		else enj = mulj;

		if (sti == enj + 2) return res - sums[enj + 1];
		else if (sti <= (enj + 1))
		{
			return res + accumulate(sums.begin() + sti, sums.begin() + enj + 1, 0);
		}
		else return -99999; //dump
	}
};

/*
//224ms, 24.73%
//������
//vector<int>�����±�0����ǰ��Ԫ�غ�

class NumArray {
private:
	vector<int> sums;
public:
	NumArray(vector<int>& nums) {
		sums.resize(nums.size());
		int presum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			presum += nums[i];
			sums[i] = presum;
		}
	}

	void update(int i, int val) {
		int preval;
		if (i == 0) preval = sums[0];
		else preval = sums[i] - sums[i - 1];
		int extra_add = val - preval;

		for (int loc = i; loc < sums.size(); ++loc)
			sums[loc] += extra_add;
	}

	int sumRange(int i, int j) {
		if (i == 0) return sums[j];
		else return sums[j] - sums[i - 1];
	}
};
*/

/*
int main()
{
	vector<int> nums = { 1,3,5 };
	NumArray* n = new NumArray(nums);
	cout << n->sumRange(0, 2) << endl;  //9
	n->update(1, 2);
	cout << n->sumRange(0, 2) << endl;  //8
	cout << n->sumRange(0, 1) << endl;  //3
	cout << n->sumRange(0, 0) << endl;  //1
}
*/
