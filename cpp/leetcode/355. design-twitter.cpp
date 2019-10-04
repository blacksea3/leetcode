#include "public.h"

//104ms, 55.48%
//暴力, 也许还可以优化?
//用vector<pair<int, int>>记录: 用户ID, 推文ID, 直接按时间排序过了
//用unordered_map<int, unordered_set<int>>记录: 用户ID, 此用户关注的用户IDs(也包括自己)

class Twitter {
private:
	unordered_map<int, unordered_set<int>> users;
	vector<pair<int, int>> infos;

public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		infos.emplace_back(pair<int, int>{userId, tweetId});
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		//强制让用户关注自己
		follow(userId, userId);
		unordered_set<int>& targetIds = users[userId];
		vector<int> res;
		for (int loc = infos.size() - 1; loc >= 0; loc--)
		{
			if (targetIds.find(infos[loc].first) != targetIds.end())
			{
				res.emplace_back(infos[loc].second);
				if (res.size() == 10) break;
			}
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		unordered_set<int>& targetIds = users[followerId];
		if (targetIds.find(followeeId) == targetIds.end())
			targetIds.insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		unordered_set<int>& targetIds = users[followerId];
		if (targetIds.find(followeeId) != targetIds.end())
			targetIds.erase(followeeId);
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

/*
int main()
{
	Twitter* obj = new Twitter();
	obj->postTweet(1, 5);
	
	//obj->follow(1, 1);
	obj->unfollow(1, 1);
	vector<int> param_2 = obj->getNewsFeed(1);
	return 0;
}
*/
