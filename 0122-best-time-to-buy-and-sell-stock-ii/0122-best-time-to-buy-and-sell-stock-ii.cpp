class Solution {
public:
int helper(int i, int buy ,vector<int> & arr,vector<vector<int>> &dp)
{
    if(i>= arr.size())
    {
        return 0;
    }
    int profit =0;

    if(dp[i][buy]!=-1)
    {
        return dp[i][buy];
    }
    if (buy)
    {
        profit = max(-arr[i] + helper(i+1,0,arr,dp),helper(i+1,1,arr,dp));
    }
    else
    {
          profit = max(arr[i] + helper(i+1,1,arr,dp),helper(i+1,0,arr,dp));
    }
    return dp[i][buy]= profit;
}
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp (n,vector<int>(2,-1));
        return helper(0,1,arr,dp);
        
    }
};