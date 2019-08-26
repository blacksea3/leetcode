#include "public.h"

//260ms, 8.16%
//暴力
//用vector<pair<int, int>>记录: 用户ID, 推文ID
//用unordered_map<int, vector<int>>记录: 用户ID, 应显示的用户IDs(不包括自己)

class Twitter {
private:
	unordered_map<int, vector<int>> users;
	vector<pair<int, int>> infos;

public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		infos.push_back(pair<int, int>{userId, tweetId});
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		int remaininfos = 10;
		vector<int> res;
		for (int loc = infos.size() - 1; loc >= 0; loc--)
		{
			if (infos[loc].first == userId || find(users[userId].begin(), users[userId].end(), infos[loc].first) != users[userId].end())
			{
				res.push_back(infos[loc].second);
				remaininfos--;
				if (remaininfos == 0) break;
			}
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		vector<int>::iterator iter = find(users[followerId].begin(), users[followerId].end(), followeeId);
		if (iter == users[followerId].end()) users[followerId].push_back(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		vector<int>::iterator iter = find(users[followerId].begin(), users[followerId].end(), followeeId);
		if (iter != users[followerId].end()) users[followerId].erase(iter);
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
	Twitter* obj = new Twitter();
	obj->postTweet(1, 5);
	
	//obj->follow(1, 1);
	obj->unfollow(1, 1);
	vector<int> param_2 = obj->getNewsFeed(1);
	return 0;
}
