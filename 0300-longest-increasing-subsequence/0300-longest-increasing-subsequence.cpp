class Solution {
public:
    int helper(int index, int prev,vector<int> & arr,  vector<vector<int>> &dp)
    {
        if(index>= arr.size())
        {
            return 0;
        }
        int pick =0;
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1];

        }

       
        if(prev==-1 || arr[index]>arr[prev])
        {
             pick = 1+ helper(index+1,index,arr,dp);
        }
        int notpick = helper(index+1,prev,arr,dp);
      return dp[index][prev+1]= max(pick,notpick);


         

    }

    int lengthOfLIS(vector<int>& arr) {
        int n =arr.size();

        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(0,-1,arr,dp);

        
    }
};