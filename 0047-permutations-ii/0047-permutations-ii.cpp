class Solution {
public:
void helper(int index, vector<int>& visited,vector<int>&arr,vector<int>&v,set<vector<int>>&st){
       if (v.size()==arr.size()){
        st.insert(v);
        return;
    }
    // if (index>=arr.size()){
    //     return;
    // }
 
    for (int i=0;i<arr.size();i++){
        if (!visited[i]){
            visited[i]=1;
            v.push_back(arr[i]);
            helper(i+1,visited,arr,v,st);
            v.pop_back();
            visited[i]=0;
        }
    }
    return;
}
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n=arr.size();
        vector<int>visited(n,0);
        vector<int>v;
        set<vector<int>>st;
        vector<vector<int>> ans;
        helper(0,visited,arr,v,st);
        for (auto it: st){
            ans.push_back(it);
        }
        return ans;
        
    }
};