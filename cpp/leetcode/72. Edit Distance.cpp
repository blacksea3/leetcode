#include "public.h"

//16ms, 96.30%
//DPÎÊÌâ

//here: use dp int[lenword1+1][lenword2+1] to store thing:
//dp int[i][j] means that how many distance between the word1.substr(0,i) and word2.substr(0,j)

//first, init procedure: dp[0][j] = j, dp[i][0] = i;, when i == 0, this means use cmp1 == "", j = 1 the same meaning

//then in two dimension iteration(traverse), if word1[i] == word2[j] dp[i][j] = dp[i-1][j-1];
//  else dp[i][j] = the min of the three thing: dp[i-1][j-1]+1 (word1[i]->word2[j]), dp[i][j-1] + 1(add word2[j]),
//    dp[i-1][j] + 1(add word1[i])

class Solution {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size();
		int size2 = word2.size();

		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

		for (int i = 0; i <= size1; i++)
			dp[i][0] = i;
		for (int j = 0; j <= size2; j++)
			dp[0][j] = j;

		for (int i = 1; i <= size1; i++)
			for (int j = 1; j <= size2; j++)
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));

		return dp[size1][size2];
	}
};

