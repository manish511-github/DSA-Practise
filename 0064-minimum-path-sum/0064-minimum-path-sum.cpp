class Solution {
public:
int helper(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
    if (i==0 && j==0){
        return arr[i][j];
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    int up=INT_MAX-200;
    if (i-1>=0){
        up=helper(i-1,j,arr,dp);
    }
    int right=INT_MAX-200;
    if (j-1>=0){
        right= helper(i,j-1,arr,dp);
    }
    return dp[i][j]=min(arr[i][j]+up,arr[i][j]+right);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
        
    }
};