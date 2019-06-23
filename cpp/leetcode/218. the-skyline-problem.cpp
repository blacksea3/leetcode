#include "public.h"

//44ms, 98.65%
//��ע��
//����˼·/�㷨

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//ά��һ�����ȶ���,�������߶�
		//��buildings��Ϣ�������·�ʽ����:����[2,9,10]����:(2,-10),(9,10)��ʾ��2����10���9�½�10
		//������Щ��,���յ�һ:pos���򡢵ڶ�height��������(height�����и�,�����������½��ķ���ͬ����ͬ),Ȼ�����Щ�㰴���������ȼ�����,����ܹ��������߶�(��������(����)һ�����߶Ȼ���ɾ��(�½�)һ�����߶�),��ô��¼��ǰ���߶��뵱ǰλ��,���򲻲���

		vector<vector<int>> res = {};
		if (buildings.size() == 0) return res;

		//ʹ��multiset:�ɺ��ظ�Ԫ�صļ���(��֤����)

		multiset<pair<int, int>, less<pair<int, int>>> points;   //��¼λ��,�߶�(�������ŵ�),��������,С�±��ֵС�ڴ��±��
		multiset<int, greater<int>> maxheights = { 0 }; //ֵ���Ԫ����С���±괦,��һ��0ȷ����multiset��Ϊ��

		for (auto building : buildings)
		{
			points.insert(pair<int, int> {building[0], -1 * building[2]});
			points.insert(pair<int, int> {building[1], building[2]});
		}

		int hisheight = 0;
		for (auto point : points)
		{
			if (point.second < 0) //��¥��ʼ����,�߶�����
				maxheights.insert(-1 * point.second);
			else                 //��¥��ʼ����,�߶��½�,���õ���erase��ָ��λ��,��Ϊ�㷨��������һ����Ԫ�ر��Ƴ�
				maxheights.erase(maxheights.find(point.second));
			multiset<int, greater<int>>::iterator it = maxheights.begin();
			if (hisheight != *it)
				res.push_back(vector<int> {point.first, *it});
			hisheight = *it;
		}

		return res;
	}
};
