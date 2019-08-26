#include "public.h"

//4ms, 94.17%
//dp
//��clips����ʼʱ���С��������, Ȼ�����ƴ��

class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end());

		vector<int> dp(T + 1, INT_MAX);
		dp[0] = 0;

		for (auto& clip : clips)
		{
			if (clip[0] > T) break;
			if (clip[0] > 0 && dp[clip[0]] == INT_MAX) return -1; //�޷��������
			for (int update = clip[0] + 1; update <= min(clip[1], T); ++update)
				dp[update] = min(dp[clip[0]] + 1, dp[update]);
		}

		if (T > 0) return (dp[T] == INT_MAX) ? -1 : dp[T];
		else return 1;
	}
};

/*
int main()
{
	Solution* s = new Solution();
	vector<vector<int>> clips = { {5, 7},{1, 8},{0, 0},{2, 3},{4, 5},{0, 6},{5, 10},{7, 10} };
	auto res = s->videoStitching(clips, 5);
	return 0;
}
*/