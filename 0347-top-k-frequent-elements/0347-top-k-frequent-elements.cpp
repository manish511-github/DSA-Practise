class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        //Approch 1:-
        unordered_map<int,int>mp;
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i=0;i<arr.size();i++){
            mp[arr[i]]++;

        }
        
        for (auto it : mp){
            pq.push({it.second,it.first});
            if (pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;

    }
};