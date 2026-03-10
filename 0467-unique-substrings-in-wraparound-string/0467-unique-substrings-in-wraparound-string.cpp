class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26,0);
        int len=0;

        for (int i=0;i<s.length();i++){
            if (i!=0 && (s[i]-s[i-1]==1 || (s[i-1]=='z' && s[i]=='a'))){
                len++;
            }
            else{
                len=1;
            }
            dp[s[i]-'a']=max(len,dp[s[i]-'a']);
        }
        int st= accumulate(dp.begin(),dp.end(),0);
        return st;
        
    }
};