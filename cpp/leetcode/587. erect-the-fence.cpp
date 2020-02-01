#include "BinaryTree.h"
#include "listnode.h"

//Graham 扫描
//翻译至leetcode官方题解的JAVA版本的Graham方法
//

class Solution {
private:
    //这个函数有 3 个参数，分别是当前凸包上的点 p，下一个会加到凸包里的点 q，其他点空间内的任何一个点 r。如果 q 点相对于 r 点来说在点 p 的逆时针方向上的话，这个函数返回一个负值。
    int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    //求p和q的距离平方
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