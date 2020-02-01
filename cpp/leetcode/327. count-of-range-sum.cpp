#include "public.h"

//68ms, 13.42%
//离散线段树

class Solution {
private:
	//离散化, 求某个区间内的数字的个数, update和query同时进行
	map<long long, int> gblum;		//离散化用:转换
	long long t[50005 << 2];			//t为线段树，t的大小是a的四倍, 用来防止下标溢出RE, 线段树区间记录此区间的值数量
	long long startV;					//用于build, 线段树的起始值, 端点的
	int rightLoc;				//数据总量

	void Pushup(int k) {        //更新函数，这里是实现最大值 ，同理可以变成，最小值，区间和等
		t[k] = t[k << 1] + t[k << 1 | 1];
	}
	
	//递归方式建树 build(1,1,n);
	//此函数仅在main调用一次, 线段树的结构在pushup过程中不变
	void build(int k, int l, int r) {    //k为当前需要建立的结点，l为当前需要建立区间的左端点，r则为右端点
		if (l == r)    //左端点等于右端点，即为叶子节点，直接赋值即可
			t[k] = startV;
		else {
			int m = l + ((r - l) >> 1);    //m则为中间点，左儿子的结点区间为[l,m],右儿子的结点区间为[m+1,r]
			build(k << 1, l, m);    //递归构造左儿子结点
			build(k << 1 | 1, m + 1, r);    //递归构造右儿子结点
			Pushup(k);    //更新父节点
		}
	}

	//递归更新区间 updata(P,1,n,1);, 实际上此函数变成了单点更新:), 单点值+1
	void update(int P, int l, int r, int k) {    //[L,R]即为要更新的区间，l，r为结点区间，k为结点下标
		if (P <= l && r <= P) {    //如果当前结点的区间真包含于要更新的区间内
			t[k] += 1;    //这个数加一个:)
		}
		else {
			int m = l + ((r - l) >> 1);
			if (P <= m)    //如果左子树和需要更新的区间交集非空
				update(P, l, m, k << 1);
			if (m < P)    //如果右子树和需要更新的区间交集非空
				update(P, m + 1, r, k << 1 | 1);
			Pushup(k);    //更新父节点
		}
	}

	//递归方式区间查询 query(L,R,1,n,1);
	//查找[L,R]的区间和
	int query(int L, int R, int l, int r, int k) {    //[L,R]即为要查询的区间，l，r为结点区间，k为结点下标
		if (L <= l && r <= R)    //如果当前结点的区间真包含于要查询的区间内，则返回结点信息且不需要往下递归
			return t[k];
		else {
			//Pushdown(k);    //每次都需要更新子树的Lazy标记, 用不到这个
			int res = 0;      //返回值变量，根据具体线段树查询的什么而自定义
			int m = l + ((r - l) >> 1);    //m则为中间点，左儿子的结点区间为[l,m],右儿子的结点区间为[m+1,r]
			if (L <= m)    //如果左子树和需要查询的区间交集非空
				res += query(L, R, l, m, k << 1);
			if (R > m)    //如果右子树和需要查询的区间交集非空，注意这里不是else if，因为查询区间可能同时和左右区间都有交集
				res += query(L, R, m + 1, r, k << 1 | 1);

			return res;    //返回当前结点得到的信息
		}
	}
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		if (nums.empty()) return 0;

		//全局变量初始化
		gblum.clear();
		memset(t, 0, (50005 << 2) * sizeof(long long));
		startV = 0;
		
		long long preSum = 0;
		//计算离散map, 以及数据量总数
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
		
		//建树
		this->build(1, 1, rightLoc);

		//搞起来:)
		this->update(gblum.at(0), 1, rightLoc, 1);
		int ret = 0;
		preSum = 0;
		for (auto& n : nums) {
			preSum += (long long)n;

			//包括n 以及至少一个前面的
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
			else {  //不可能找到值了!
				;
			}
			this->update(gblum.at(preSum), 1, rightLoc, 1);
		}
		return ret;
	}
};

/*
//TLE
//典型的线段树
//目前是无懒惰标记的线段树, 时间复杂度O(nnlogn) 比暴力还大...
//待更久之后研究, 线段树难度太大

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

	//更新单点的节点值, 实际传入absv的是值增加量
	//注意: 这个函数可能是错的!
	void update(int l, int r, int nindex, const int& modifyloc, const int& absv)
	{
		nodes[nindex]->sum += modifyloc;

		if (l == r) return;
		int mid = (l + r) / 2;
		if (modifyloc <= mid) update(l, mid, nindex + 1, modifyloc, absv);
		else update(mid + 1, r, nindex + 2, modifyloc, absv);
	}

	//查询[ql, qr]的区间和
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
