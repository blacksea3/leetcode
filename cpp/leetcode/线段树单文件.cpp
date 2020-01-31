#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

//此函数为求区间最大值写法

const int maxn = 200002;
int a[maxn], t[maxn << 2];        //a为原来区间，t为线段树，t的大小是a的四倍, 用来防止下标溢出RE
int lazy[maxn << 2];              //懒惰标记, 的大小是a的四倍, 用来防止下标溢出RE

void Pushup(int k) {        //更新函数，这里是实现最大值 ，同理可以变成，最小值，区间和等
    t[k] = max(t[k << 1], t[k << 1 | 1]);
}

//递归方式建树 build(1,1,n);
//此函数仅在main调用一次, 线段树的结构在pushup过程中不变
void build(int k, int l, int r) {    //k为当前需要建立的结点，l为当前需要建立区间的左端点，r则为右端点
    if (l == r)    //左端点等于右端点，即为叶子节点，直接赋值即可
        t[k] = a[l];
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
        int res = -INT_MAX;    //返回值变量，根据具体线段树查询的什么而自定义
        int m = l + ((r - l) >> 1);    //m则为中间点，左儿子的结点区间为[l,m],右儿子的结点区间为[m+1,r]
        if (L <= m)    //如果左子树和需要查询的区间交集非空
            res = max(res, query(L, R, l, m, k << 1));
        if (R > m)    //如果右子树和需要查询的区间交集非空，注意这里不是else if，因为查询区间可能同时和左右区间都有交集
            res = max(res, query(L, R, m + 1, r, k << 1 | 1));

        return res;    //返回当前结点得到的信息
    }
}

int main() {
    //freopen("testData/线段树0.txt", "r", stdin);

    int numPeople, numOp;

    while (~scanf("%d%d", &numPeople, &numOp)) {
        for (int index = 1; index <= numPeople; ++index) {
            scanf("%d", &a[index]);
        }
        build(1, 1, numPeople);
        for (int index = 0; index < numOp; ++index) {
            char op[5];
            int v1, v2;
            scanf("%s%d%d", op, &v1, &v2);
            if (op[0] == 'Q') {
                int ret = query(v1, v2, 1, numPeople, 1);
                printf("%d\n", ret);
            }
            else {
                int oldv = query(v1, v1, 1, numPeople, 1);
                if (oldv < v2) {   //如果值确实变大了, 更新那个差值
                    update(v1, v1, v2 - oldv, 1, numPeople, 1);
                }
            }
        }
    }
    return 0;
}

