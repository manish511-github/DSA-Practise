class Solution {
public:


    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();

    vector<int> dp(n+1,1);
    dp[0]=1;
    int maxi =0;
    for(int i=0 ;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] >arr[j])
            {
                if(dp[i]<=dp[j]+1)
                {
                        dp[i]=dp[j]+1;
              

                }
            

            }
        }
          maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
};