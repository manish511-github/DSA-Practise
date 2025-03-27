class Solution {
public:
void dfs(int node,vector<vector<int>> &adj,vector<int> & visited,vector<int> &comp)
{
    visited[node]=1;
    comp.push_back(node);
    for(auto it: adj[node])
    {
        if (!visited[it])
        {
            dfs(it,adj,visited,comp);
        }
    }
}
bool isValidComponeent(vector<int> &comp,vector<vector<int>> &adj)
{
    int k=comp.size();
    for(int i=0;i<comp.size();i++)
    {
        if (adj[comp[i]].size()!= k-1)
        {
            return false;
        }

    }
    return true;
}

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     //  A connected component is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component. 
     //	The total number of edges is simply the number of unique ways to choose 2 nodes from the k available nodes (since an edge is always between 2 nodes).
     int count =0;
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        vector<int>visited(n,0);
        // find the nodes in one component
        for(int i=0;i<n;i++)
        {
            if (!visited[i])
            {
                vector<int> comp;
                  dfs(i,adj,visited,comp);
                  if (isValidComponeent(comp,adj))
                  {
                    count++;
                  }
            }
          

        }
        return count;


    }
};