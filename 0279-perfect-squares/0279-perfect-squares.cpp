class Solution {
public:
    

    int numSquares(int n) {
    // Start from n
	// Subtract all possible squares
	// Each subtraction is one level
	// First time you reach 0 → answer
    queue<pair<int,int>> q;
    q.push({n,0});
    vector<int>visited(10001,0);
    while(!q.empty()){
        auto it =q.front();
        int frontval=it.first;
        int level=it.second;
        if (frontval==0){
            return level;
        }
        q.pop();
        for(int j=1;j*j<=frontval;j++){
            int next =frontval-j*j;
            if (next==0){
                return (level+1);

            }
            if (visited[next]==0){
                visited[next]=1;
                q.push({next,level+1});
            }
            
        }
    }
    return 0;
    }

};