#include "public.h"

//离散线段树

class Solution {
private:
    //离散化, 求大于/小于某个值的个数, update和query同时进行
    map<int, int> gblum; //离散化用:转换
    int t[50005 << 2];        //a为原来区间，t为线段树，t的大小是a的四倍, 用来防止下标溢出RE, 线段树区间记录此区间的值数量
    //int lazy[50005 << 2];              //懒惰标记, 的大小是a的四倍, 用来防止下标溢出RE, 现在用不到
    int startV;   //用于build, 线段树的起始值, 端点的

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

    //用不到这个
    void Pushdown(int k) {    //更新子树的lazy值，这里是RMQ的函数，要实现区间和等则需要修改函数内容
        /*
        if (lazy[k]) {    //如果有lazy标记
            lazy[k << 1] += lazy[k];    //更新左子树的lazy值
            lazy[k << 1 | 1] += lazy[k];    //更新右子树的lazy值
            t[k << 1] += lazy[k];        //左子树的最值加上lazy值
            t[k << 1 | 1] += lazy[k];    //右子树的最值加上lazy值
            lazy[k] = 0;    //lazy值归0
        }
        */
    }

    //递归更新区间 updata(P,1,n,1);, 实际上此函数变成了单点更新:), 单点值+1
    void update(int P, int l, int r, int k) {    //[L,R]即为要更新的区间，l，r为结点区间，k为结点下标
        if (P <= l && r <= P) {    //如果当前结点的区间真包含于要更新的区间内
            //lazy[k] += v;    //懒惰标记
            t[k] += 1;    //这个数加一个:)
        }
        else {
            //Pushdown(k);    //重难点，查询lazy标记，更新子树, 用不到这个
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
            //Pushdown(k);    /**每次都需要更新子树的Lazy标记*/, 用不到这个
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
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;

        //gbl赋值
        gblum.clear();
        memset(t, 0, (50005 << 2)*sizeof(int));
        startV = 0;

        //统计共有多少种数字, 求离散化map
        set<int> s;
        for (auto& n : nums) s.insert(n);
        
        int index = 1;
        for (auto& iters : s) gblum[iters] = index++;
        int rootRi = index - 1;
        int rootLe = 1;
        int rootIndex = 1;

        //build
        this->build(rootIndex, rootLe, rootRi);

        //搞起来:)先插入第一个
        this->update(gblum[nums[0]], rootLe, rootRi, rootIndex);

        int ret = 0;
        for (int index = 1; index < nums.size(); ++index) {
            //查找一个
            if (nums[index] >= INT_MAX / 2) {
                ;
            }
            else if (nums[index] > INT_MIN / 2) {  //溢出提前判断
                int queryHigherThan = 2 * nums[index];
                auto tempret = gblum.upper_bound(queryHigherThan);
                if (tempret != gblum.end()) {   //不可能有值了
                    int lBound = tempret->second;
                    ret += this->query(lBound, rootRi, rootLe, rootRi, rootIndex);
                }
            }
            else {
                ret += this->query(rootLe, rootRi, rootLe, rootRi, rootIndex);
            }

            //插入一个
            this->update(gblum[nums[index]], rootLe, rootRi, rootIndex);
        }
        return ret;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> v = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout << s->reversePairs(v) << endl;
}
