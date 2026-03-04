class Solution {
public:
    
    int helper(int index,int val,vector<int>& arr,vector<vector<int>> &dp)
    {
        if (val==0){
            return 0;
        }
        if (index<0){
            return 10001;
        }
        int take=10001;
        if (dp[index][val]!=-1){
            return dp[index][val];
        }
        if (arr[index]<=val){
            take = 1+helper(index,val-arr[index],arr,dp);
        }
        int nottake=helper(index-1,val,arr,dp);
        return dp[index][val]=min(take,nottake);
    }
    int numSquares(int val) {
       vector<int> arr;

        for(int i = 1; i * i <= 10000; i++) {
            arr.push_back(i * i);
        }
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(10000+1,-1));
        return helper(n-1,val,arr,dp);
        

        
    }
};