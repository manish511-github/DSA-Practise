class Solution {
public:
int helper(int index,int buy,int remain, vector<int>& arr,vector<vector<vector<int>>>&dp)
{
    if (remain==0){
        return 0;
    }
    if (index==arr.size()){
        return 0;
    }
    if (dp[index][buy][remain]!=-1){
        return dp[index][buy][remain];
    }
    int profit=0;
    int val1=INT_MIN;
    int val2=INT_MIN;
    if (buy){
        int val1=-arr[index]+ helper(index+1,0,remain,arr,dp);
        int val2=helper(index+1,1,remain,arr,dp);
        profit =dp[index][buy][remain]=max(val1,val2);
    } else {
        int val1=arr[index] + helper(index+1,1,remain-1, arr,dp);
        int val2=helper(index+1,0,remain,arr,dp);
        profit=dp[index][buy][remain]=max(val1,val2);


    }
    return profit;
}
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0,1,2,arr,dp);
        
    }
};