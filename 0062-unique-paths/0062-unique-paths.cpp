class Solution {
public:
    int helper(int i, int j,vector<vector<int>> &dp){
        if (i==0 && j==0){
            return 1;
        }
        if (i<0 || j<0){
            return 0;
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int count=0;
        if (i-1>=0)
        {
            count+=helper(i-1,j,dp);
        }
        if (j-1>=0)
        {
            count+=helper(i,j-1,dp);
        }
        return dp[i][j]=count ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
        
    }
};