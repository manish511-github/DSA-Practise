class Solution {
public:
    

    int numSquares(int n) {
        vector<int> dp(n+1,-1);

        for (int i=0;i<=n;i++){
            if (i==0){
                dp[i]=0;
            }
            else{
                int ans=INT_MAX;
            for (int j=1;j*j<=i;j++){
                ans=min(ans,1+ dp[i-j*j]);
                }
                dp[i]=ans;
            }

        }
        return dp[n];

        
    }
};