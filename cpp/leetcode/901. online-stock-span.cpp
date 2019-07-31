#include "public.h"

//416ms, 28.72%
//栈: 存储pair<int, int> first是价格, second是此价格的跨度
//使用缓存

class StockSpanner {
private:
	stack<pair<int, int>> st;
	int cache_v = 100001;
	int cache_r = -1;
public:
	StockSpanner() {
		st.push({ 100001, 0 });
	}

	int next(int price) {
		if (price == cache_v)
		{
			st.top().second++;
			cache_r++;
			return cache_r;
		}

		int res = 1;
		while (true)
		{
			pair<int, int> p = st.top();
			if (p.first > price)
				break;
			else
			{
				res += p.second;
				st.pop();
			}
		}
		st.push({ price, res });
		cache_v = price;
		cache_r = res;
		return res;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
