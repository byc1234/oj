/*

*/
class Twitter {
public:
    unordered_map<int, unordered_set<int>> followeeToFollowers;
    unordered_map<int, list<pair<int,int>>> userIdToTweets;
    
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        list<pair<int,int>>& tweets = userIdToTweets[userId];
        if (tweets.size() > 10) {
            tweets.pop_front();
        }
        tweets.push_back(make_pair(userId,tweetId));
        unordered_set<int> &followers = followeeToFollowers[userId];
        for (auto e : followers) {
            list<pair<int,int>>& tws = userIdToTweets[e];
            if (tws.size() > 10) {
                tws.pop_front();
            }
            tws.push_back(make_pair(userId,tweetId));
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        list<pair<int,int>>& tweets = userIdToTweets[userId];
        vector<int> feeds;
        for (auto e : tweets) {
            feeds.push_back(e.second);
        }
        reverse(feeds.begin(), feeds.end());
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followeeToFollowers[followeeId].insert(followerId);
        list<pair<int,int>>& fromTweets = userIdToTweets[followeeId];
        list<pair<int,int>>& toTweets = userIdToTweets[followerId];
        for (auto t : fromTweets) {
            if (t.first == followeeId) {
                toTweets.push_back(t);
            }
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        unordered_set<int>& followers = followeeToFollowers[followeeId];
        for (auto e : followers) {
            list<pair<int,int>>& tws = userIdToTweets[e];
            auto new_end = std::remove_if(tws.begin(), tws.end(),
                              [&followeeId](const pair<int, int>& twt)
                              { return twt.first == followeeId; });
            tws.erase(new_end, tws.end());
        }
        if (followers.find(followerId) != followers.end()) followers.erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
