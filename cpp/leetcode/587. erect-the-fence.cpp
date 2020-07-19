#include "BinaryTree.h"
#include "listnode.h"

//Graham ɨ��
//������leetcode�ٷ�����JAVA�汾��Graham����
//

class Solution {
private:
    //��������� 3 ���������ֱ��ǵ�ǰ͹���ϵĵ� p����һ����ӵ�͹����ĵ� q��������ռ��ڵ��κ�һ���� r����� q ������� r ����˵�ڵ� p ����ʱ�뷽���ϵĻ��������������һ����ֵ��
    int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    //��p��q�ľ���ƽ��
    int distance(const vector<int>& p, const vector<int>& q) {
        return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
    }

    vector<int> bottomLeft(const vector<vector<int>> points) {
        int stY = points[0][1];
        int stX = points[0][0];
        int stIndex = 0;
        for (int index = 1; index < points.size(); ++index) {
            if (points[index][1] < stY) {
                stY = points[index][1];
                stX = points[index][0];
                stIndex = index;
            }
            else if (points[index][1] == stY) {
                if (points[index][0] < stX) {
                    stY = points[index][1];
                    stX = points[index][0];
                    stIndex = index;
                }
            }
        }
        return points[stIndex];
    }

public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() <= 1) return points;
        vector<int> bL = this->bottomLeft(points);
        sort(points.begin(), points.end(), [this, &bL](vector<int> p, vector<int> q)
        {
            int diff = this->orientation(bL, p, q) - this->orientation(bL, q, p);
            if (diff == 0) {
                return (this->distance(bL, p) - this->distance(bL, q)) > 0;
            }
            else {
                return diff > 0 ? true : false;
            }
        }
        );

        int i = points.size() - 1;
        while (i >= 0 && orientation(bL, points[points.size() - 1], points[i]) == 0)
            i--;
        for (int l = i + 1, h = points.size() - 1; l < h; l++, h--) {
            vector<int> temp = points[l];
            points[l] = points[h];
            points[h] = temp;
        }

        vector<vector<int>> st;
        st.push_back(points[0]);
        st.push_back(points[1]);
        for (int j = 2; j < points.size(); j++) {
            vector<int> top = st.back();
            st.pop_back();
            while (orientation(st.back(), top, points[j]) > 0) {
                top = st.back();
                st.pop_back();
            }
            st.push_back(top);
            st.push_back(points[j]);
        }

        return st;
    }
};

int main() {
    Solution* s = new Solution();
    vector<vector<int>> points1 = { {1, 1},{2, 2 }, {2, 0}, {2, 4}, { 3, 3}, {4, 2} };
    auto ret = s->outerTrees(points1);

    return 0;
}