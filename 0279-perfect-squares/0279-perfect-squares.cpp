class Solution {
public:
    
    int helper(int i,vector<int>& dp)
    {
        if (i==0){
            return 0;
        }
        int ans=INT_MAX;
        if (dp[i]!=-1){
            return dp[i];
        }
        for (int j=1;j*j<=i;j++){
            ans=min(ans,1+ helper(i-j*j,dp));
        }
        return dp[i]= ans;
      
    }
    int numSquares(int val) {
        vector<int> dp(10001,-1);
        return helper(val,dp);
    

        
    }
};