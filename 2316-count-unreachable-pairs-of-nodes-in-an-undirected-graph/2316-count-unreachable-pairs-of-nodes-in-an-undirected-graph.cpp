class Solution {
public:

//[[1,0],[3,1],[0,4],[2,1]]
// 1--> 0->4

// |
// 3
void helper(int node ,vector<vector<int>> &adj,vector<int> &visited,long long &cnt){
    if (visited[node]==0){
        visited[node]=1;
    }
    cnt++;
    for (auto it:adj[node]){
        if (!visited[it]){
            helper(it,adj,visited,cnt);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

        }
        vector<int> visited(n,0);
        long long prev=0;
        long long ans=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                long long cnt=0;
                helper(i,adj,visited,cnt);
                ans+=prev*cnt;
                prev+=cnt;
            }
           

        }
        return ans;
        
    }
};