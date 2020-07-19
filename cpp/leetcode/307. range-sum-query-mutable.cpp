#include "public.h"

//44ms, 69.11%
//��:�߶���

class NumArray {
private:
	//�˺���Ϊ�������д��
	vector<int> raw;
	int t[100002 << 2];        //aΪԭ�����䣬tΪ�߶�����t�Ĵ�С��a���ı�, ������ֹ�±����RE
	int lazy[100002 << 2];              //������, �Ĵ�С��a���ı�, ������ֹ�±����RE
	int rIndex;  //����±�

	void Pushup(int k) {        //���º�����������ʵ�����ֵ ��ͬ����Ա�ɣ���Сֵ������͵�
		t[k] = t[k << 1] + t[k << 1 | 1];
	}

	//�ݹ鷽ʽ���� build(1,1,n);
	//�˺�������main����һ��, �߶����Ľṹ��pushup�����в���
	void build(int k, int l, int r) {    //kΪ��ǰ��Ҫ�����Ľ�㣬lΪ��ǰ��Ҫ�����������˵㣬r��Ϊ�Ҷ˵�
		if (l == r)    //��˵�����Ҷ˵㣬��ΪҶ�ӽڵ㣬ֱ�Ӹ�ֵ����
			t[k] = raw[l];
		else {
			int m = l + ((r - l) >> 1);    //m��Ϊ�м�㣬����ӵĽ������Ϊ[l,m],�Ҷ��ӵĽ������Ϊ[m+1,r]
			build(k << 1, l, m);    //�ݹ鹹������ӽ��
			build(k << 1 | 1, m + 1, r);    //�ݹ鹹���Ҷ��ӽ��
			Pushup(k);    //���¸��ڵ�
		}
	}

	void Pushdown(int k) {    //����������lazyֵ��������RMQ�ĺ�����Ҫʵ������͵�����Ҫ�޸ĺ�������
		if (lazy[k]) {    //�����lazy���
			lazy[k << 1] += lazy[k];    //������������lazyֵ
			lazy[k << 1 | 1] += lazy[k];    //������������lazyֵ
			t[k << 1] += lazy[k];        //����������ֵ����lazyֵ
			t[k << 1 | 1] += lazy[k];    //����������ֵ����lazyֵ
			lazy[k] = 0;    //lazyֵ��0
		}
	}

	//�ݹ�������� updata(L,R,v,1,n,1);
	//v�Ǵ����ӵ�ֵ, �����Ǹ�����!
	void update(int L, int R, int v, int l, int r, int k) {    //[L,R]��ΪҪ���µ����䣬l��rΪ������䣬kΪ����±�
		if (L <= l && r <= R) {    //�����ǰ���������������Ҫ���µ�������
			lazy[k] += v;    //������
			t[k] += v;    //���ֵ����v֮�󣬴���������ֵҲ�϶��Ǽ�v
		}
		else {
			Pushdown(k);    //���ѵ㣬��ѯlazy��ǣ���������
			int m = l + ((r - l) >> 1);
			if (L <= m)    //�������������Ҫ���µ����佻���ǿ�
				update(L, R, v, l, m, k << 1);
			if (m < R)    //�������������Ҫ���µ����佻���ǿ�
				update(L, R, v, m + 1, r, k << 1 | 1);
			Pushup(k);    //���¸��ڵ�
		}
	}

	//�ݹ鷽ʽ�����ѯ query(L,R,1,n,1);
	int query(int L, int R, int l, int r, int k) {    //[L,R]��ΪҪ��ѯ�����䣬l��rΪ������䣬kΪ����±�
		if (L <= l && r <= R)    //�����ǰ���������������Ҫ��ѯ�������ڣ��򷵻ؽ����Ϣ�Ҳ���Ҫ���µݹ�
			return t[k];
		else {
			Pushdown(k);    /**ÿ�ζ���Ҫ����������Lazy���*/
			int res = 0;    //����ֵ���������ݾ����߶�����ѯ��ʲô���Զ���
			int m = l + ((r - l) >> 1);    //m��Ϊ�м�㣬����ӵĽ������Ϊ[l,m],�Ҷ��ӵĽ������Ϊ[m+1,r]
			if (L <= m)    //�������������Ҫ��ѯ�����佻���ǿ�
				res += query(L, R, l, m, k << 1);
			if (R > m)    //�������������Ҫ��ѯ�����佻���ǿգ�ע�����ﲻ��else if����Ϊ��ѯ�������ͬʱ���������䶼�н���
				res += query(L, R, m + 1, r, k << 1 | 1);

			return res;    //���ص�ǰ���õ�����Ϣ
		}
	}

public:
	NumArray(vector<int>& nums) {
		int nSize = nums.size();
		if (nSize == 0) return;
		raw = nums;
		raw.insert(raw.begin(), -99999);  //�൱���ƶ��±�
		memset(t, 0, (100002 << 2) * sizeof(int));
		memset(lazy, 0, (100002 << 2) * sizeof(int));

		rIndex = nums.size();
		this->build(1, 1, rIndex);
	}

	void update(int i, int val) {
		int old = this->query(i + 1, i + 1, 1, rIndex, 1);
		this->update(i + 1, i + 1, val - old, 1, rIndex, 1);
	}

	int sumRange(int i, int j) {
		return this->query(i + 1, j + 1, 1, rIndex, 1);
	}
};

//40ms, 91.86%
//�ֶ����, α�߶���
/*
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
*/

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
