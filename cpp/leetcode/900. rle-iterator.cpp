#include "public.h"

//24ms, 12.82%
//Ä£Äâ

class RLEIterator {
private:
	vector<int> cpA;
public:
	RLEIterator(vector<int>& A) {
		for (int i = 0; i < A.size() / 2; ++i)
		{
			if (A[2 * i] == 0) continue;
			else
			{
				cpA.push_back(A[2 * i]);
				cpA.push_back(A[2 * i + 1]);
			}
		}
	}

	int next(int n) {
		while (true)
		{
			if (cpA.empty()) return -1;
			else
			{
				if (cpA[0] > n)
				{
					cpA[0] -= n;
					return cpA[1];
				}
				else if (cpA[0] == n)
				{
					int re = cpA[1];
					cpA.erase(cpA.begin());
					cpA.erase(cpA.begin());
					return re;
				}
				else
				{
					n -= cpA[0];
					cpA.erase(cpA.begin());
					cpA.erase(cpA.begin());
				}
			}
		}
		return -2; //dump
	}
};

/*
int main()
{
	vector<int> A = {3, 8, 0, 9, 1, 5};
	RLEIterator* obj = new RLEIterator(A);
	cout << obj->next(2);
	cout << obj->next(1);
	cout << obj->next(1);
	cout << obj->next(2);
	return 0;
}
*/
