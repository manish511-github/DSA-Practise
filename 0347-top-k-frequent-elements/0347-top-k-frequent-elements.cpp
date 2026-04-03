class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        //Approch 1:-
        unordered_map<int,int>mp;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for (int i=0;i<arr.size();i++){
            mp[arr[i]]++;

        }
        
        for (auto it : mp){
            pq.push({it.second,it.first});
        }
        
        while(!pq.empty() && k>0){
            auto t=pq.top();
            pq.pop();
            ans.push_back(t.second);
            k--;
        }
        return ans;

        
    }
};