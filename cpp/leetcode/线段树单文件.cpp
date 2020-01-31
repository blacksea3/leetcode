#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

//�˺���Ϊ���������ֵд��

const int maxn = 200002;
int a[maxn], t[maxn << 2];        //aΪԭ�����䣬tΪ�߶�����t�Ĵ�С��a���ı�, ������ֹ�±����RE
int lazy[maxn << 2];              //������, �Ĵ�С��a���ı�, ������ֹ�±����RE

void Pushup(int k) {        //���º�����������ʵ�����ֵ ��ͬ����Ա�ɣ���Сֵ������͵�
    t[k] = max(t[k << 1], t[k << 1 | 1]);
}

//�ݹ鷽ʽ���� build(1,1,n);
//�˺�������main����һ��, �߶����Ľṹ��pushup�����в���
void build(int k, int l, int r) {    //kΪ��ǰ��Ҫ�����Ľ�㣬lΪ��ǰ��Ҫ�����������˵㣬r��Ϊ�Ҷ˵�
    if (l == r)    //��˵�����Ҷ˵㣬��ΪҶ�ӽڵ㣬ֱ�Ӹ�ֵ����
        t[k] = a[l];
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
        int res = -INT_MAX;    //����ֵ���������ݾ����߶�����ѯ��ʲô���Զ���
        int m = l + ((r - l) >> 1);    //m��Ϊ�м�㣬����ӵĽ������Ϊ[l,m],�Ҷ��ӵĽ������Ϊ[m+1,r]
        if (L <= m)    //�������������Ҫ��ѯ�����佻���ǿ�
            res = max(res, query(L, R, l, m, k << 1));
        if (R > m)    //�������������Ҫ��ѯ�����佻���ǿգ�ע�����ﲻ��else if����Ϊ��ѯ�������ͬʱ���������䶼�н���
            res = max(res, query(L, R, m + 1, r, k << 1 | 1));

        return res;    //���ص�ǰ���õ�����Ϣ
    }
}

int main() {
    //freopen("testData/�߶���0.txt", "r", stdin);

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
                if (oldv < v2) {   //���ֵȷʵ�����, �����Ǹ���ֵ
                    update(v1, v1, v2 - oldv, 1, numPeople, 1);
                }
            }
        }
    }
    return 0;
}

