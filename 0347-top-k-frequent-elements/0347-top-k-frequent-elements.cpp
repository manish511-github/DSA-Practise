class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        //Approch 3:-
        unordered_map<int,int>mp;
        
        for (int i=0;i<arr.size();i++){
            mp[arr[i]]++;

        }
        vector<vector<int>>ans(arr.size()+1);
        for (auto it : mp){
            ans[it.second].push_back(it.first);
        }
        vector<int> v;
        for (int i=ans.size()-1;i>=1;i--){
            for (int j=0;j<ans[i].size();j++){
                v.push_back(ans[i][j]);
                if (v.size()==k){
                    return v;
                }
            }
        }
        return v;

    }
};