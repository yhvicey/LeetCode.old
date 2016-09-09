#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Twitter {
	const int maxCount = 10;

	vector<pair<int, int>> _tweets;

	unordered_map<int, unordered_set<int>> _users;

public:
	Twitter() {

	}

	void postTweet(int userId, int tweetId) {
		_tweets.push_back(pair<int, int>{userId, tweetId});
	}

	vector<int> getNewsFeed(int userId) {
		vector<int> result;
		auto count = maxCount;
		for (int i = _tweets.size() - 1;count > 0 && i >= 0;i--)
		{
			if (userId == _tweets[i].first || _users[userId].find(_tweets[i].first) != _users[userId].end())
			{
				result.push_back(_tweets[i].second);
				count--;
			}
		}
		return result;
	}

	void follow(int followerId, int followeeId) {
		_users[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		_users[followerId].erase(followeeId);
	}
};

int main()
{
	Twitter twitter;
	twitter.postTweet(1, 5);
	auto var1 = twitter.getNewsFeed(1);
	twitter.follow(1, 2);
	twitter.postTweet(2, 6);
	auto var2 = twitter.getNewsFeed(1);
	twitter.unfollow(1, 2);
	auto var3 = twitter.getNewsFeed(1);
}