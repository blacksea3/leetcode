#include "public.h"

//44ms, 69.11%
//真:线段树

class NumArray {
private:
	//此函数为求区间和写法
	vector<int> raw;
	int t[100002 << 2];        //a为原来区间，t为线段树，t的大小是a的四倍, 用来防止下标溢出RE
	int lazy[100002 << 2];              //懒惰标记, 的大小是a的四倍, 用来防止下标溢出RE
	int rIndex;  //最大下标

	void Pushup(int k) {        //更新函数，这里是实现最大值 ，同理可以变成，最小值，区间和等
		t[k] = t[k << 1] + t[k << 1 | 1];
	}

	//递归方式建树 build(1,1,n);
	//此函数仅在main调用一次, 线段树的结构在pushup过程中不变
	void build(int k, int l, int r) {    //k为当前需要建立的结点，l为当前需要建立区间的左端点，r则为右端点
		if (l == r)    //左端点等于右端点，即为叶子节点，直接赋值即可
			t[k] = raw[l];
		else {
			int m = l + ((r - l) >> 1);    //m则为中间点，左儿子的结点区间为[l,m],右儿子的结点区间为[m+1,r]
			build(k << 1, l, m);    //递归构造左儿子结点
			build(k << 1 | 1, m + 1, r);    //递归构造右儿子结点
			Pushup(k);    //更新父节点
		}
	}

	void Pushdown(int k) {    //更新子树的lazy值，这里是RMQ的函数，要实现区间和等则需要修改函数内容
		if (lazy[k]) {    //如果有lazy标记
			lazy[k << 1] += lazy[k];    //更新左子树的lazy值
			lazy[k << 1 | 1] += lazy[k];    //更新右子树的lazy值
			t[k << 1] += lazy[k];        //左子树的最值加上lazy值
			t[k << 1 | 1] += lazy[k];    //右子树的最值加上lazy值
			lazy[k] = 0;    //lazy值归0
		}
	}

	//递归更新区间 updata(L,R,v,1,n,1);
	//v是待增加的值, 可能是个负的!
	void update(int L, int R, int v, int l, int r, int k) {    //[L,R]即为要更新的区间，l，r为结点区间，k为结点下标
		if (L <= l && r <= R) {    //如果当前结点的区间真包含于要更新的区间内
			lazy[k] += v;    //懒惰标记
			t[k] += v;    //最大值加上v之后，此区间的最大值也肯定是加v
		}
		else {
			Pushdown(k);    //重难点，查询lazy标记，更新子树
			int m = l + ((r - l) >> 1);
			if (L <= m)    //如果左子树和需要更新的区间交集非空
				update(L, R, v, l, m, k << 1);
			if (m < R)    //如果右子树和需要更新的区间交集非空
				update(L, R, v, m + 1, r, k << 1 | 1);
			Pushup(k);    //更新父节点
		}
	}

	//递归方式区间查询 query(L,R,1,n,1);
	int query(int L, int R, int l, int r, int k) {    //[L,R]即为要查询的区间，l，r为结点区间，k为结点下标
		if (L <= l && r <= R)    //如果当前结点的区间真包含于要查询的区间内，则返回结点信息且不需要往下递归
			return t[k];
		else {
			Pushdown(k);    /**每次都需要更新子树的Lazy标记*/
			int res = 0;    //返回值变量，根据具体线段树查询的什么而自定义
			int m = l + ((r - l) >> 1);    //m则为中间点，左儿子的结点区间为[l,m],右儿子的结点区间为[m+1,r]
			if (L <= m)    //如果左子树和需要查询的区间交集非空
				res += query(L, R, l, m, k << 1);
			if (R > m)    //如果右子树和需要查询的区间交集非空，注意这里不是else if，因为查询区间可能同时和左右区间都有交集
				res += query(L, R, m + 1, r, k << 1 | 1);

			return res;    //返回当前结点得到的信息
		}
	}

public:
	NumArray(vector<int>& nums) {
		int nSize = nums.size();
		if (nSize == 0) return;
		raw = nums;
		raw.insert(raw.begin(), -99999);  //相当于移动下标
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
//分段求和, 伪线段树
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
		//初始化sums: 下标i 存放 nums中的[segSize*(i-1): segSize*i)的和
		for (int index = 0; index < sSize; ++index)
		{
			sums[index] = accumulate(nums.begin() + segSize * index,
				nums.begin() + segSize * (index + 1),
				0);
		}
	}

	void update(int i, int val) {
		//求i的segSize的整数倍数, 向下取整
		int mulIndex = i / segSize;
		if (mulIndex != sSize) sums[mulIndex] += val - cpNums[i];
		cpNums[i] = val;
	}

	int sumRange(int i, int j) {
		//按区间求和
		//求i/j的segSize整数倍数, 向上/下取整
		//sti是实际连续求和段的起始sums坐标, enj是结束坐标
		int muli, mulj, sti, enj;
		int res = 0;

		muli = i / segSize;
		if (i%segSize != 0)  //例如: segSize:3, i:1, j=7; 一共是 012 345 678
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
//纯暴力
//vector<int>保存下标0至当前的元素和

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
