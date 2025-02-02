class Solution {
public:
int helper(int index, int buy,vector<int> & arr,int fee,vector<vector<int>> &dp)
{
    if (index>=arr.size())
    {
        return 0;
    }
    if(dp[index][buy]!=-1)
    {
        return dp[index][buy];
    }

    if (buy)
    {
    return dp[index][buy]=max(-arr[index]+helper(index+1,0,arr,fee,dp),helper(index+1,1,arr,fee,dp));

    }
    else
    {
return dp[index][buy]=max(arr[index]-fee +helper(index+1,1,arr,fee,dp),helper(index+1,0,arr,fee,dp));
    }
}
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();


        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return helper(0,1,arr,fee,dp);
        
    }
};