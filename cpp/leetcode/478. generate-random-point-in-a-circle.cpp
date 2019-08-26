#include "public.h"

//284ms, 33.67%
//拒绝采样, 先生成正方形结果, 然后去除圆周围部分

class Solution {
private:
	double m_radius;
	double m_x_center;
	double m_y_center;

public:
	Solution(double radius, double x_center, double y_center) {
		m_radius = radius;
		m_x_center = x_center;
		m_y_center = y_center;
	}

	vector<double> randPoint() {
		double dx = m_radius * (rand() % 20001 - 10000)*0.0001;
		double dy = m_radius * (rand() % 20001 - 10000)*0.0001;
		while (dx*dx + dy * dy > m_radius*m_radius) {
			dx = m_radius * (rand() % 20001 - 10000)*0.0001;
			dy = m_radius * (rand() % 20001 - 10000)*0.0001;
		}
		return{ m_x_center + dx, m_y_center + dy };
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

/*
int main()
{
	Solution* s = new Solution(0.01, 0, 0);
	vector<double> param_1 = s->randPoint();
	vector<double> param_2 = s->randPoint();
	vector<double> param_3 = s->randPoint();
	vector<double> param_4 = s->randPoint();
	vector<double> param_5 = s->randPoint();
	return 0;
}
*/
