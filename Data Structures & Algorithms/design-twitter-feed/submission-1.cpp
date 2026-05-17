class Twitter {
    private:
        int time = 0;
        char followerMatrix[101][101] = {0};
        vector<pair<int,int>> tweetsBy[101];
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsBy[userId].emplace_back(++time, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> feed;
        int smallest = -1;
        for(int i = 1; i<101; i++){
            if(followerMatrix[userId][i] == 1 || userId==i){
                for(const auto& tweet: tweetsBy[i]){
                    feed.emplace(tweet);
                }
            }
        }
        vector<int> res;
        for(int i = 0; i<10 && !feed.empty(); i++){
            res.emplace_back(feed.top().second);
            feed.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followerMatrix[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMatrix[followerId][followeeId] = 0;        
    }
};
