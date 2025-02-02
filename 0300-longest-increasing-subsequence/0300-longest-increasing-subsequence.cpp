class Solution {
public:


    int lengthOfLIS(vector<int>& arr) {
        int n =arr.size();

        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int index= n-1;index>=0 ; index--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
        int pick =0;


        if(prev==-1 || arr[index]>arr[prev])
        {
             pick = 1+ dp[index+1][index+1];
        }
        int notpick = dp[index+1][prev+1];
       dp[index][prev+1]= max(pick,notpick);


            }
        }
        return dp[0][0];

        
    }
};