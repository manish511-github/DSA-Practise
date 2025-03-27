class Solution {
public:
const int MOD = 1e9+7;

    int countPaths(int n, vector<vector<int>>& arr) {
vector<vector<pair<long long, long long>>> adj(n);
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        for (auto it : arr)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long long currnode = pq.top().second;
            long long  currdist = pq.top().first;
            pq.pop();
            for(auto it:adj[currnode])
            {
                long long nbrnode = it.first;
                long long nbrdist = it.second;
                
                 if (currdist + nbrdist < dist[nbrnode])
                {
                    dist[nbrnode] = currdist+ nbrdist;
                    ways[nbrnode] = ways[currnode];
                    pq.push({dist[nbrnode],nbrnode});

                }
                 else if (currdist + nbrdist == dist[nbrnode])
                 {
                    ways[nbrnode]=(ways[nbrnode]+ ways[currnode])%MOD;
                 }
             
            }

        }
        return ways[n-1];

    }
};