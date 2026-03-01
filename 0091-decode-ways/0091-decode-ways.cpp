class Solution {
public:
int helper(int index,string s,vector<int> &dp){
    if (index>=s.length()){
        return 1;
    }
    if (s[index]=='0'){
        return 0;
    }
    if (dp[index]!=-1){
        return dp[index];
    }
    int count = 0;
    count+=helper(index+1,s,dp);
    if (index+1<s.length()){
        int dig=(s[index]-'0')*10+(s[index+1]-'0');
        if (dig>=10 && dig<=26){
            count+=helper(index+2,s,dp);
        }
    }
    return dp[index]=count;
}
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return helper(0,s,dp);

        
    }
};