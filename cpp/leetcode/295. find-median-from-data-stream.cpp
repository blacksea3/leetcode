#include "public.h"

//168ms, 99.54%
//同时维持一个最大堆和最小堆

class MedianFinder {
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;      //大顶堆, 放小数字, 大小>小顶堆或相等
	priority_queue<int, vector<int>, greater<int>> minHeap;   //小顶堆, 放大数字
public:
	/** initialize your data structure here. */
	MedianFinder() {
		;
	}

	void addNum(int num) {
		if (maxHeap.empty() || maxHeap.top() < num) minHeap.push(num);
		else maxHeap.push(num);
		if (maxHeap.size() < minHeap.size()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
	}

	double findMedian() {
		if (maxHeap.size() == minHeap.size()) {
			return (maxHeap.top() + minHeap.top()) / 2.;
		}
		return maxHeap.top();
	}
};

/*
//324ms, 43.12%
//维持一个排序vector

class MedianFinder {
private:
	vector<int> v;
public:
	MedianFinder() {

	}

	void addNum(int num) {
		v.insert(upper_bound(v.begin(), v.end(), num), num);
	}

	double findMedian() {
		if (v.size() % 2) return v[v.size() / 2];
		else return ((double)v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
	}
};
*/

/*
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
*/
