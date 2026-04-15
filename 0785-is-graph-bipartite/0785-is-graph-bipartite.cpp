class Solution {
public:
    bool helper(int node,vector<vector<int>>& adj,vector<int>&colors,int color){
        colors[node]=color;
        for (auto it: adj[node]){
            if (colors[it]==-1){
                if (helper(it,adj,colors,!color)==false){
                    return false;
                }
            }
            if (colors[it]==color){
                return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& arr) {
        int n =arr.size();
        vector<int>colors(n+1,-1);
        for (int i=0;i<n;i++){
            if (colors[i]==-1){
                if (!helper(i,arr,colors,0)){
                    return false;
                }
            }
        }
        return true;
    }
};