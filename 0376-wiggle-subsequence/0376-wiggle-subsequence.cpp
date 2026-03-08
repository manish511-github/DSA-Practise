class Solution {
public:


// [3,3,3,2,5]
// 3 2 5 
// 
    int helper(int index, int prev, vector<int> & arr, int diff, vector<vector<vector<int>>> &dp){
        if (index>=arr.size()){
            return 0;
        }
        int take=0;
        int take1=0;
        int take2=0;

        if (dp[index+1][prev+1][diff+1]!=-1){
            return dp[index+1][prev+1][diff+1];
        }
        if ((diff==-1) || (diff==1 && (arr[index]-prev)>0)){
            take1 = 1+helper(index+1,arr[index],arr,0,dp);
        }
        
        if ((diff==-1) || (diff==0 && (arr[index]-prev)<0)){
            take2 = 1+helper(index+1,arr[index],arr,1,dp);
        }
        take =max(take1,take2);

        int nottake= helper(index+1,prev,arr,diff,dp);
        return dp[index+1][prev+1][diff+1]= max(take,nottake);
    }
    int wiggleMaxLength(vector<int>& arr) {
       int n=arr.size();

       vector<vector<vector<int>>> dp(n+2, 
       vector<vector<int>>(1002, vector<int>(3, -1)));
        return helper(0,-1,arr,-1,dp);
        
    }
};