#include "public.h"

//
//线段树

class Solution {
private:
	#define LC(a) ((a<<1))
	#define RC(a) ((a<<1)+1)
	#define MID(a,b) ((a+b)>>1)
	int sizeN = 5e4 + 5;
	typedef long long ll;

	vector<vector<ll>> v; //每个都是N大小
	vector<ll> Start, End;//每个员工所有下属的开始和结束节点，包含本身
	ll ans, cnt;//cnt用于记录节点的编号
	vector<bool> used;

	void dfs(ll rt)
	{
		Start[rt] = ++cnt;
		for (int i = 0; i < v[rt].size(); i++) {
			dfs(v[rt][i]);
		}
		End[rt] = cnt;
	}

	struct node {
		ll l, r;
		ll task;//task=-2表示下属工作不同 
	};

	vector<node> tree; //有4*N个node

	void pushup(ll p) {
		tree[p].task = (tree[LC(p)].task == tree[RC(p)].task ? tree[LC(p)].task : -2);
	}

	void pushdown(ll p) {
		tree[LC(p)].task = tree[RC(p)].task = tree[p].task;
	}

	void build(ll p, ll l, ll r) {
		tree[p].l = l;
		tree[p].r = r;
		tree[p].task = -1;
		if (l == r) {
			return;
		}
		build(LC(p), l, MID(l, r));
		build(RC(p), MID(l, r) + 1, r);
	}

	void update(ll p, ll l, ll r, ll task) {
		if (r<tree[p].l || l>tree[p].r)
			return;
		if (l <= tree[p].l&&r >= tree[p].r) {
			tree[p].task = task;
			return;
		}
		if (tree[p].task != -2)
			pushdown(p);
		update(LC(p), l, r, task);
		update(RC(p), l, r, task);
		pushup(p);
	}

	void query(ll p, ll t) {
		if (tree[p].task != -2) {
			ans = tree[p].task;
			return;
		}
		ll mid = MID(tree[p].l, tree[p].r);
		if (t <= mid)
			query(LC(p), t);
		else
			query(RC(p), t);
	}

public:
	vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
		Start.resize(sizeN);
		End.resize(sizeN);
		used.resize(sizeN);
	}
};

