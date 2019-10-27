//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
int main()
{
	{
		int n;
		cin >> n;
		vector<long long> v;
		for (int i = 0; i < n; ++i)
		{
			int op;
			cin >> op;
			if (op == 1)
			{
				long long x, y, z;
				cin >> x >> y >> z;
				int d = ceil(sqrt(x * x + y * y + z * z));
				
				vector<long long>::iterator iter = lower_bound(v.begin(), v.end(), d);
				if (iter == v.end()) v.push_back(d);
				else v.insert(iter, d);
			}
			else
			{
				int loc;
				cin >> loc;
				if (loc > v.size()) cout << -1 << endl;
				else cout << v[loc - 1] << endl;
			}
		}
	}
	return 0;
}
*/
