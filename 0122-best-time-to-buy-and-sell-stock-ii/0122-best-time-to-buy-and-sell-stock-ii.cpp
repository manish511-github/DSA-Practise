class Solution {
public:
    int helper(int index,int buy, vector<int>& arr,vector<vector<int>> &dp){
        // buy
        // sell
        if (index>=arr.size()){
            return 0;
        }
        int val1=0;
        int val2=0;
        int profit=INT_MIN;
        if (dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        if (buy){
            val1 =-arr[index]+helper(index+1,0,arr,dp);
            val2 = helper(index+1,1,arr,dp); 
            profit=max(val1,val2);
        }
        else {
            val1=arr[index]+helper(index+1,1,arr,dp);
            val2=helper(index+1,0,arr,dp);
            profit=max(val1,val2);
        }
        return dp[index][buy]=profit;


    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,arr,dp);
        
    }
};