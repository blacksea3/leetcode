#include "public.h"

//628ms, 9.19%
//注意: 内存消耗 42.2MB 97.74%
//可以针对时间再优化
//维持一个排序vector

class MedianFinder {
private:
	vector<int> v;
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		//二分插入
		if (v.empty() || num >= v[v.size() - 1])
		{
			v.push_back(num);
			return;
		}
		if (num <= v[0])
		{
			v.insert(v.begin(), num);
			return;
		}

		int left = 0;
		int right = v.size() - 1;

		while (left < right)
		{
			int mid = (left + right) / 2;
			if (num < v[mid]) right = mid - 1;
			else if (num > v[mid]) left = mid + 1;
			else
			{
				v.insert(v.begin() + mid, num);
				return;
			}
		}

		if (num <= v[left]) v.insert(v.begin() + left, num);
		else v.insert(v.begin() + left + 1, num);
	}

	double findMedian() {
		if (v.size() % 2) return v[v.size() / 2];
		else return ((double)v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
	MedianFinder* obj = new MedianFinder();
	double param_2;
	obj->addNum(12);
	param_2 = obj->findMedian();
	obj->addNum(10);
	param_2 = obj->findMedian();
	obj->addNum(13);
	param_2 = obj->findMedian();
	obj->addNum(11);
	param_2 = obj->findMedian();
	obj->addNum(5);
	param_2 = obj->findMedian();
	obj->addNum(15);
	param_2 = obj->findMedian();
	obj->addNum(1);
	param_2 = obj->findMedian();
	obj->addNum(11);
	param_2 = obj->findMedian();
	obj->addNum(6);
	param_2 = obj->findMedian();
	obj->addNum(17);
	param_2 = obj->findMedian();
	obj->addNum(14);
	param_2 = obj->findMedian();
	obj->addNum(8);
	param_2 = obj->findMedian();
	obj->addNum(17);
	param_2 = obj->findMedian();
	obj->addNum(6);
	param_2 = obj->findMedian();
	obj->addNum(4);
	param_2 = obj->findMedian();
	obj->addNum(16);
	param_2 = obj->findMedian();
	obj->addNum(8);
	param_2 = obj->findMedian();
	obj->addNum(10);
	param_2 = obj->findMedian();
	obj->addNum(2);
	param_2 = obj->findMedian();
	obj->addNum(0);
	param_2 = obj->findMedian();
	return 0;
}
