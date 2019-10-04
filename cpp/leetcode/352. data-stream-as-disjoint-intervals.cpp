#include "public.h"

//116ms, 100%
//��map��¼���俪ʼ/�������, ����������
//��set��¼���俪ʼ, ���ڶ��ֲ��Ҷ�λ

//ÿ���Ȳ��ҳ�����С�ڵ���val�Ŀ�ʼֵ, Ȼ���������:
//  ���val��[��ʼֵ, ����ֵ]��, �򲻱�
//  ���val==����ֵ+1, ������
//  ���val > ����ֵ+1, ���½�
//  ����, �ж�val����һ���俪ʼֵ��ϵ
//  ���val==��һ��ʼֵ-1, ��ϲ�

//���ݲ�=��ͬ���, ����map��set

class SummaryRanges {
private:
	map<int, int> intervals;
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		map<int, int>::iterator iter = intervals.upper_bound(val);
		if (iter == intervals.begin())  //û��С�ڵ���val�Ŀ�ʼֵ...
		{
			//�жϺ�һ�������Ƿ���Ժϲ�
			if ((iter != intervals.end()) && (val == iter->first - 1)) //�ϲ�
			{
				int end = intervals[val+1];
				intervals.erase(val+1);
				intervals.insert(pair<int, int>{val, end});
			}
			else
			{
				intervals.insert(pair<int, int>{val, val});
			}
		}
		else
		{
			map<int, int>::iterator afteriter = iter;
			iter--;
			//�ж��Ƿ��Ѿ���������
			if ((iter->second >= val) && (iter->first <= val)); //�Ѿ�����, �������
			else if (iter->second == val - 1) //ǰһ��������Ժϲ�
			{
				//�жϺ�һ�������Ƿ���Ժϲ�
				if ((afteriter != intervals.end()) && (val == afteriter->first - 1)) //��һ��Ҳ�ϲ�
				{
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals[iter->first] = end;
				}
				else //���ϲ�ǰһ��
				{
					intervals[iter->first]++;
				}
			}
			else
			{
				//�жϺ�һ�������Ƿ���Ժϲ�
				if ((afteriter != intervals.end()) && (val == afteriter->first - 1)) //��һ���ɺϲ�
				{
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals.insert(pair<int, int>{val, end});
				}
				else
				{
					intervals.insert(pair<int, int>{val, val});
				}
			}
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for (const auto& m : intervals)
		{
			res.push_back({m.first, m.second});
		}
		return res;
	}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

/*
int main()
{
	SummaryRanges* obj = new SummaryRanges();
	obj->addNum(65);
	vector<vector<int>> param_2 = obj->getIntervals();
	obj->addNum(64);
	param_2 = obj->getIntervals();
}
*/
