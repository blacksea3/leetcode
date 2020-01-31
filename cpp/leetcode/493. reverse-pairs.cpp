#include "public.h"

//��ɢ�߶���

class Solution {
private:
    //��ɢ��, �����/С��ĳ��ֵ�ĸ���, update��queryͬʱ����
    map<int, int> gblum; //��ɢ����:ת��
    int t[50005 << 2];        //aΪԭ�����䣬tΪ�߶�����t�Ĵ�С��a���ı�, ������ֹ�±����RE, �߶��������¼�������ֵ����
    //int lazy[50005 << 2];              //������, �Ĵ�С��a���ı�, ������ֹ�±����RE, �����ò���
    int startV;   //����build, �߶�������ʼֵ, �˵��

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

    //�ò������
    void Pushdown(int k) {    //����������lazyֵ��������RMQ�ĺ�����Ҫʵ������͵�����Ҫ�޸ĺ�������
        /*
        if (lazy[k]) {    //�����lazy���
            lazy[k << 1] += lazy[k];    //������������lazyֵ
            lazy[k << 1 | 1] += lazy[k];    //������������lazyֵ
            t[k << 1] += lazy[k];        //����������ֵ����lazyֵ
            t[k << 1 | 1] += lazy[k];    //����������ֵ����lazyֵ
            lazy[k] = 0;    //lazyֵ��0
        }
        */
    }

    //�ݹ�������� updata(P,1,n,1);, ʵ���ϴ˺�������˵������:), ����ֵ+1
    void update(int P, int l, int r, int k) {    //[L,R]��ΪҪ���µ����䣬l��rΪ������䣬kΪ����±�
        if (P <= l && r <= P) {    //�����ǰ���������������Ҫ���µ�������
            //lazy[k] += v;    //������
            t[k] += 1;    //�������һ��:)
        }
        else {
            //Pushdown(k);    //���ѵ㣬��ѯlazy��ǣ���������, �ò������
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
            //Pushdown(k);    /**ÿ�ζ���Ҫ����������Lazy���*/, �ò������
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
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;

        //gbl��ֵ
        gblum.clear();
        memset(t, 0, (50005 << 2)*sizeof(int));
        startV = 0;

        //ͳ�ƹ��ж���������, ����ɢ��map
        set<int> s;
        for (auto& n : nums) s.insert(n);
        
        int index = 1;
        for (auto& iters : s) gblum[iters] = index++;
        int rootRi = index - 1;
        int rootLe = 1;
        int rootIndex = 1;

        //build
        this->build(rootIndex, rootLe, rootRi);

        //������:)�Ȳ����һ��
        this->update(gblum[nums[0]], rootLe, rootRi, rootIndex);

        int ret = 0;
        for (int index = 1; index < nums.size(); ++index) {
            //����һ��
            if (nums[index] >= INT_MAX / 2) {
                ;
            }
            else if (nums[index] > INT_MIN / 2) {  //�����ǰ�ж�
                int queryHigherThan = 2 * nums[index];
                auto tempret = gblum.upper_bound(queryHigherThan);
                if (tempret != gblum.end()) {   //��������ֵ��
                    int lBound = tempret->second;
                    ret += this->query(lBound, rootRi, rootLe, rootRi, rootIndex);
                }
            }
            else {
                ret += this->query(rootLe, rootRi, rootLe, rootRi, rootIndex);
            }

            //����һ��
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
