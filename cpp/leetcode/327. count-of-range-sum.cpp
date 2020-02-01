#include "public.h"

//68ms, 13.42%
//��ɢ�߶���

class Solution {
private:
	//��ɢ��, ��ĳ�������ڵ����ֵĸ���, update��queryͬʱ����
	map<long long, int> gblum;		//��ɢ����:ת��
	long long t[50005 << 2];			//tΪ�߶�����t�Ĵ�С��a���ı�, ������ֹ�±����RE, �߶��������¼�������ֵ����
	long long startV;					//����build, �߶�������ʼֵ, �˵��
	int rightLoc;				//��������

	void Pushup(int k) {        //���º�����������ʵ�����ֵ ��ͬ����Ա�ɣ���Сֵ������͵�
		t[k] = t[k << 1] + t[k << 1 | 1];
	}
	
	//�ݹ鷽ʽ���� build(1,1,n);
	//�˺�������main����һ��, �߶����Ľṹ��pushup�����в���
	void build(int k, int l, int r) {    //kΪ��ǰ��Ҫ�����Ľ�㣬lΪ��ǰ��Ҫ�����������˵㣬r��Ϊ�Ҷ˵�
		if (l == r)    //��˵�����Ҷ˵㣬��ΪҶ�ӽڵ㣬ֱ�Ӹ�ֵ����
			t[k] = startV;
		else {
			int m = l + ((r - l) >> 1);    //m��Ϊ�м�㣬����ӵĽ������Ϊ[l,m],�Ҷ��ӵĽ������Ϊ[m+1,r]
			build(k << 1, l, m);    //�ݹ鹹������ӽ��
			build(k << 1 | 1, m + 1, r);    //�ݹ鹹���Ҷ��ӽ��
			Pushup(k);    //���¸��ڵ�
		}
	}

	//�ݹ�������� updata(P,1,n,1);, ʵ���ϴ˺�������˵������:), ����ֵ+1
	void update(int P, int l, int r, int k) {    //[L,R]��ΪҪ���µ����䣬l��rΪ������䣬kΪ����±�
		if (P <= l && r <= P) {    //�����ǰ���������������Ҫ���µ�������
			t[k] += 1;    //�������һ��:)
		}
		else {
			int m = l + ((r - l) >> 1);
			if (P <= m)    //�������������Ҫ���µ����佻���ǿ�
				update(P, l, m, k << 1);
			if (m < P)    //�������������Ҫ���µ����佻���ǿ�
				update(P, m + 1, r, k << 1 | 1);
			Pushup(k);    //���¸��ڵ�
		}
	}

	//�ݹ鷽ʽ�����ѯ query(L,R,1,n,1);
	//����[L,R]�������
	int query(int L, int R, int l, int r, int k) {    //[L,R]��ΪҪ��ѯ�����䣬l��rΪ������䣬kΪ����±�
		if (L <= l && r <= R)    //�����ǰ���������������Ҫ��ѯ�������ڣ��򷵻ؽ����Ϣ�Ҳ���Ҫ���µݹ�
			return t[k];
		else {
			//Pushdown(k);    //ÿ�ζ���Ҫ����������Lazy���, �ò������
			int res = 0;      //����ֵ���������ݾ����߶�����ѯ��ʲô���Զ���
			int m = l + ((r - l) >> 1);    //m��Ϊ�м�㣬����ӵĽ������Ϊ[l,m],�Ҷ��ӵĽ������Ϊ[m+1,r]
			if (L <= m)    //�������������Ҫ��ѯ�����佻���ǿ�
				res += query(L, R, l, m, k << 1);
			if (R > m)    //�������������Ҫ��ѯ�����佻���ǿգ�ע�����ﲻ��else if����Ϊ��ѯ�������ͬʱ���������䶼�н���
				res += query(L, R, m + 1, r, k << 1 | 1);

			return res;    //���ص�ǰ���õ�����Ϣ
		}
	}
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.empty()) return 0;

		//ȫ�ֱ�����ʼ��
		gblum.clear();
		memset(t, 0, (50005 << 2) * sizeof(long long));
		startV = 0;
		
		long long preSum = 0;
		//������ɢmap, �Լ�����������
		set<long long> us;
		us.insert(0);
		for (auto& n : nums) {
			preSum += n;
			us.insert(preSum);
		}
		int index = 0;
		for (auto& iterus : us) {
			gblum[iterus] = ++index;
		}
		rightLoc = index;
		
		//����
		this->build(1, 1, rightLoc);

		//������:)
		this->update(gblum.at(0), 1, rightLoc, 1);
		int ret = 0;
		preSum = 0;
		for (auto& n : nums) {
			preSum += (long long)n;

			//����n �Լ�����һ��ǰ���
			//long long realLow = (long long)preSum - (long long)upper;
			//long long realHi = (long long)preSum - (long long)lower;

			auto loit = gblum.lower_bound(preSum - upper);
			auto hiit = gblum.upper_bound(preSum - lower);
			if (loit != gblum.end() && hiit != gblum.begin()) {
				int lowBoundV = loit->first;
				hiit--;
				int highBoundV = hiit->first;
				int preRet = this->query(loit->second, hiit->second, 1, rightLoc, 1);
				ret += preRet;
			}
			else {  //�������ҵ�ֵ��!
				;
			}
			this->update(gblum.at(preSum), 1, rightLoc, 1);
		}
		return ret;
	}
};

/*
//TLE
//���͵��߶���
//Ŀǰ���������ǵ��߶���, ʱ�临�Ӷ�O(nnlogn) �ȱ�������...
//������֮���о�, �߶����Ѷ�̫��

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
*/

/*
int main()
{
	Solution* s = new Solution();
	vector<int> nums = {-2,5,-1};
	cout << s->countRangeSum(nums, -2, 2) << endl;  //3
	vector<int> nums2 = { 0, -3, -3, 1, 1, 2 };
	cout << s->countRangeSum(nums2, 3, 5) << endl;  //2
	vector<int> nums3 = { -2147483647, 0, -2147483647, 2147483647 };
	cout << s->countRangeSum(nums3, -564, 3864) << endl;  //3
	vector<int> nums4 = { 2147483647,2147483647,0,-2147483647 };
	cout << s->countRangeSum(nums4, 4232, 7660) << endl;  //2
	return 0;
}
*/
