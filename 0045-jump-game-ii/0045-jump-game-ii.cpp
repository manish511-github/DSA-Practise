class Solution {
public:

    int helper(int index,vector<int> & arr, vector<int>& dp){
        if (index == arr.size()-1){
            return 0;
        }
        if (index>=arr.size())
        {
            return 0;

        }
        if (dp[index]!=-1)
        {
            return dp[index];
        }
        int mini=INT_MAX-1;

        for (int i=1;i<=arr[index];i++)
        {
            if (index+i<arr.size()){
                mini =min(mini,helper(index+i,arr,dp)+1);
            }
        }
        return dp[index] = mini;

    }
    int jump(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return helper(0,arr,dp);
        
    }
};