
class Twitter {
public:
    Twitter() {
        
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    
    int cnt=0;
    unordered_map<int,vector<pair<int,int>>>mp;
    unordered_map<int,unordered_set<int>> adj;
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({cnt,tweetId});
        cnt++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int k=10;
        vector<int> nuser(adj[userId].begin(),adj[userId].end());
        nuser.push_back(userId);
        for (int i=0;i<nuser.size();i++){
            vector<pair<int,int>> arr= mp[nuser[i]];
            for (int j=0;j<arr.size();j++){
                if (pq.size()<k){
                pq.push({arr[j].first,arr[j].second});
            }
            else{
                pq.pop();
                pq.push({arr[j].first,arr[j].second});
            }
            }
 
            
        }
        vector<int> ans;
        while(!pq.empty()){
            auto t=pq.top();
            ans.push_back(t.second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        adj[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (adj[followerId].find(followeeId)!=adj[followerId].end()){
            adj[followerId].erase(followeeId);
        }
        
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