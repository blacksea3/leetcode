#include "public.h"

//288ms, 27.45%
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
	set<int> starts;

public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		set<int>::iterator iter = upper_bound(starts.begin(), starts.end(), val);
		if (iter == starts.begin())  //û��С�ڵ���val�Ŀ�ʼֵ...
		{
			//�жϺ�һ�������Ƿ���Ժϲ�
			if ((iter != starts.end()) && (val == *iter - 1)) //�ϲ�
			{
				starts.erase(iter);
				starts.insert(val);
				int end = intervals[val+1];
				intervals.erase(val+1);
				intervals.insert(pair<int, int>{val, end});
			}
			else
			{
				starts.insert(val);
				intervals.insert(pair<int, int>{val, val});
			}
		}
		else
		{
			set<int>::iterator afteriter = iter;
			iter--;
			//�ж��Ƿ��Ѿ���������
			if ((intervals[*iter] >= val) && (*iter <= val)); //�Ѿ�����, �������
			else if (intervals[*iter] == val - 1) //ǰһ��������Ժϲ�
			{
				//�жϺ�һ�������Ƿ���Ժϲ�
				if ((afteriter != starts.end()) && (val == *afteriter - 1)) //��һ��Ҳ�ϲ�
				{
					starts.erase(*afteriter);
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals[*iter] = end;
				}
				else //���ϲ�ǰһ��
				{
					intervals[*iter]++;
				}
			}
			else
			{
				//�жϺ�һ�������Ƿ���Ժϲ�
				if ((afteriter != starts.end()) && (val == *afteriter - 1)) //��һ���ɺϲ�
				{
					starts.erase(afteriter);
					starts.insert(val);
					int end = intervals[val + 1];
					intervals.erase(val + 1);
					intervals.insert(pair<int, int>{val, end});
				}
				else
				{
					starts.insert(val);
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
