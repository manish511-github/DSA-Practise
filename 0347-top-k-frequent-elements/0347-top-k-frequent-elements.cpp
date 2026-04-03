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
        // O(n) + O(m \log m) + O(k \log m)
        // Overall = O(n + m log m)

        // If all elements are unique (m = n):
        // Worst-case = O(n log n)

        //Space Complexity 
        //	1.	unordered_map → stores m unique elements → O(m)
        //  2.	priority_queue → stores m elements → O(m)
        //  3.	ans → stores k elements → O(k)

        //    So total: //O(m + k)

    }
};