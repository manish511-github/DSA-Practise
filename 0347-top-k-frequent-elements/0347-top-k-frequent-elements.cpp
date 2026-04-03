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
        // O(n) + O(m \log k) 
    
        // Worst-case = O(n log k)

        //Space Complexity 
        //	1.	unordered_map → stores m unique elements → O(m)
        //  2.	priority_queue → stores m elements → O(m)
        //  3.	ans → stores k elements → O(k)

        //    So total: //O(m + k)

    }
};