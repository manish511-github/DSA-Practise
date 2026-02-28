class Solution {
public:
    bool helper(int index, vector<int> & arr, vector<int> & dp){
        if (index==arr.size()-1){
            return true;
        }
        if (index>=arr.size()){
            return false;
        }
        if (dp[index]!=-1){
            return dp[index];
        }
        for(int i=1;i<=arr[index];i++){
            if (i+index<arr.size()){
                if (helper(i+index,arr,dp)){
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }
    
    bool canJump(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return helper(0,arr,dp);
        
    }
};