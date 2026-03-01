class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (i==0 && j==0){
                    dp[i][j]=arr[i][j];
                }
                else 
                {
                    int up=INT_MAX;
                    int right=INT_MAX;
                    if (i-1>=0){
                        up=arr[i][j]+dp[i-1][j];
                    }
                    if (j-1>=0){
                        right=arr[i][j]+dp[i][j-1];
                    }
                    dp[i][j]=min(up,right);
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};