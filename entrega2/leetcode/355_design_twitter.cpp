#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Twitter {
private:
    vector<pair<int, int>> tweets;
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for (int i = tweets.size() - 1; i >= 0; --i) {
            int authorId = tweets[i].first;
            int tweetId = tweets[i].second;

            if (authorId == userId || followMap[userId].count(authorId)) {
                feed.push_back(tweetId);
            }

            if (feed.size() == 10) {
                break;
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);
    cout << "Feed Usuario 1: ";
    for (int id : twitter.getNewsFeed(1)) cout << id << " ";
    cout << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);

    cout << "Feed Usuario 1 tras seguir a 2: ";
    for (int id : twitter.getNewsFeed(1)) cout << id << " ";
    cout << endl;

    twitter.unfollow(1, 2);
    cout << "Feed Usuario 1 tras dejar de seguir a 2: ";
    for (int id : twitter.getNewsFeed(1)) cout << id << " ";
    cout << endl;

    return 0;
}
