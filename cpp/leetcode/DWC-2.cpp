#include "public.h"

//this is Double-weekly-contest 2
class Solution {
public:
	int sumOfDigits(vector<int>& A) {
		int minn = INT_MAX;
		for (auto a : A) minn = min(minn, a);

		int each_loc_sum = 0;
		while (minn > 0)
		{
			each_loc_sum += minn % 10;
			minn /= 10;
		}
		return (each_loc_sum % 2 == 0) ? 1 : 0;
	}

private:
	struct fucktwo
	{
		int first;
		int second;
	};
	static bool mcompare(const vector<int> &x, const vector<int> &y)
	{
		return x[0] < y[0];
	}


public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
		unordered_map<int, vector<int>> um;

        for (auto i:items) um[i[0]].push_back(i[1]);
        vector<vector<int>> res = {};
        
        for (unordered_map<int, vector<int>>::iterator iter = um.begin(); iter != um.end(); ++iter)
        {
            vector<int> pre = iter->second;
            sort(pre.begin(),pre.end(), greater<int>());
            int aver = (pre[0] + pre[1] + pre[2] + pre[3] + pre[4])/5;
			res.push_back({ iter->first , aver});
        }
		sort(res.begin(), res.end(), mcompare);

		return res;
    }

	int confusingNumberII(int N) {
		//if N == 10^9, consider as a special input
		if (N == 1000000000) return 4 * 5 * 5 * 5 * 5 * 5 * 5 * 5 - 4 * 4 * 4 * 4 + 1;   //may modify
		else if (N < 10)
		{
			if (N < 6) return 0;
			else return 1;
		}

		vector<int> specials = { 0,1,6,8,9 };
		//count the loc

		int loc = 0;
		vector<int> allnums = {};
		while (N > 0)
		{
			allnums.insert(allnums.begin(), N % 10);
			loc++;
			N /= 10;
		}

		int res = 0;

		//add all the (valid numbers - same numbers) lower than real loc;
		vector<int> v = { 0,4 - 2,4 * 5 - 4,4 * 5 * 5 - 4 * 5,4 * 5 * 5 * 5 - 4 * 4,4 * 5 * 5 * 5 * 5 - 4 * 4 * 5,4 * 5 * 5 * 5 * 5 * 5 - 4 * 4 * 4,4 * 5 * 5 * 5 * 5 * 5 * 5 - 4 * 4 * 4 * 5,4 * 5 * 5 * 5 * 5 * 5 * 5 * 5 - 4 * 4 * 4 * 4 }; // 
		for (int i = 0; i < loc; ++i)
		{
			res += v[i];
		}

		//cal the biggest loc..., the most difficult
		//figure out all the num, these are in allnums
		int remaining_allnum = 0;
		//bool isneglected = false;

		int remaining_allnum_minus = 0;
		int lastnums = 0;

		for (int i = 0; i < loc; ++i)
		{
			if (i == 0)
			{
				if (find(specials.begin(), specials.end(), allnums[i]) == specials.end())
				{
					if (allnums[i] > 5) remaining_allnum += 2 * (int)(pow(5.0, loc - 1 - i));
					else remaining_allnum += (int)(pow(5.0, loc - 1 - i));
					break;
				}
				else
				{
					if (allnums[i] == 9) remaining_allnum += 3 * (int)(pow(5.0, loc - 1 - i));
					else if (allnums[i] == 8) remaining_allnum += 2 * (int)(pow(5.0, loc - 1 - i));
					else if (allnums[i] == 6) remaining_allnum += 1 * (int)(pow(5.0, loc - 1 - i));
					else;
				}
			}
			else
			{
				if (find(specials.begin(), specials.end(), allnums[i]) == specials.end())
				{
					if (allnums[i] > 5) remaining_allnum += 3 * (int)(pow(5.0, loc - 1 - i));
					else remaining_allnum += 2 * (int)(pow(5.0, loc - 1 - i));
					break;
				}
				else
				{
					if (allnums[i] == 9) remaining_allnum += 4 * (int)(pow(5.0, loc - 1 - i));
					else if (allnums[i] == 8) remaining_allnum += 3 * (int)(pow(5.0, loc - 1 - i));
					else if (allnums[i] == 6) remaining_allnum += 2 * (int)(pow(5.0, loc - 1 - i));
					else if (allnums[i] == 1) remaining_allnum += 1 * (int)(pow(5.0, loc - 1 - i));
					else;
				}
			}
		}


		//figure the same numbers
		bool isoddloc = (loc % 2 == 1);
		bool isneed_cal_latter_half = true;
		for (int i = 0; i < loc / 2; ++i)
		{
			if (i == 0)
			{
				if (find(specials.begin(), specials.end(), allnums[i]) == specials.end())
				{
					if (allnums[i] > 5) remaining_allnum_minus += 2 * (int)(pow(4.0, loc / 2 - 1 - i));
					else remaining_allnum_minus += (int)(pow(4.0, loc / 2 - 1 - i));
					isneed_cal_latter_half = false;
					break;
				}
				else
				{
					if (allnums[i] == 9) remaining_allnum_minus += 3 * (int)(pow(4.0, loc / 2 - 1 - i));
					else if (allnums[i] == 8) remaining_allnum_minus += 2 * (int)(pow(4.0, loc / 2 - 1 - i));
					else if (allnums[i] == 6) remaining_allnum_minus += 1 * (int)(pow(4.0, loc / 2 - 1 - i));
					else;
				}
			}
			else
			{
				if (find(specials.begin(), specials.end(), allnums[i]) == specials.end())
				{
					if (allnums[i] > 5) remaining_allnum_minus += 3 * (int)(pow(4.0, loc / 2 - 1 - i));
					else remaining_allnum_minus += 2 * (int)(pow(4.0, loc / 2 - 1 - i));
					isneed_cal_latter_half = false;
					break;
				}
				else
				{
					if (allnums[i] == 9) remaining_allnum_minus += 4 * (int)(pow(4.0, loc / 2 - 1 - i));
					else if (allnums[i] == 8) remaining_allnum_minus += 3 * (int)(pow(4.0, loc / 2 - 1 - i));
					else if (allnums[i] == 6) remaining_allnum_minus += 2 * (int)(pow(4.0, loc / 2 - 1 - i));
					else if (allnums[i] == 1) remaining_allnum_minus += 1 * (int)(pow(4.0, loc / 2 - 1 - i));
					else;
				}
			}
		}

		//生成后半段数字

		int generate_latter_half_num_raw = 0;
		if (isoddloc)
		{
			for (int i = loc / 2 + 1; i < loc; ++i)
			{
				generate_latter_half_num_raw *= 10;
				generate_latter_half_num_raw += allnums[i];
			}
		}
		else
		{
			for (int i = loc / 2 + 1; i < loc; ++i)
			{
				generate_latter_half_num_raw *= 10;
				generate_latter_half_num_raw += allnums[i];
			}
		}

		int generate_latter_half_num_template = 0;
		unordered_map<int, int> convert = { {1,1},{6,9},{8,8},{9,6} };
		if (isoddloc)
		{
			for (int i = loc / 2 - 1; i >= 0; --i)
			{
				generate_latter_half_num_template *= 10;
				generate_latter_half_num_template += convert[allnums[i]];
			}
		}
		else
		{
			for (int i = loc / 2 - 1; i >= 0; --i)
			{
				generate_latter_half_num_template *= 10;
				generate_latter_half_num_template += convert[allnums[i]];
			}
		}

		if (isneed_cal_latter_half)
		{

			if (isoddloc)
			{
				if (find(specials.begin(), specials.end(), allnums[loc / 2]) == specials.end())
				{
					if (allnums[loc / 2] > 5) lastnums += 3;
					else lastnums += 2;
				}
				else
				{
					if (allnums[loc / 2] == 9) remaining_allnum += 4 * (int)(pow(4.0, loc / 2));
					else if (allnums[loc / 2] == 8) remaining_allnum += 3 * (int)(pow(4.0, loc / 2));
					else if (allnums[loc / 2] == 6) remaining_allnum += 2 * (int)(pow(4.0, loc / 2));
					else if (allnums[loc / 2] == 1) remaining_allnum += 1 * (int)(pow(4.0, loc / 2));
					else;
					if (generate_latter_half_num_raw >= generate_latter_half_num_template) lastnums++;
				}
			}
			else
			{
				if (generate_latter_half_num_raw >= generate_latter_half_num_template) lastnums++;
				else lastnums = 0;
			}

		}

		return res + remaining_allnum - remaining_allnum_minus - lastnums;


	}

};

int main()
{
	Solution* s = new Solution();
	//vector<int> A = {33,1,44};
	//cout << s->sumOfDigits(A);

	//vector<vector<int>> items = { {1,91},{1,92}, {2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76} };

	//vector<vector<int>> res = s->highFive(items);

	cout << s->confusingNumberII(100);

	return 0;
}
