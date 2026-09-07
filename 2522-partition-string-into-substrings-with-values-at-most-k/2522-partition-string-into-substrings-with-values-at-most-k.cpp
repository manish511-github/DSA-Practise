class Solution {
public:
// int helper(int index ,string &s, int k, vector<int> & dp){
//     if (index>=s.length()){
//         return 0;
//     }
//     if (dp[index]!=-1){
//         return dp[index];
//     }
//     string str="";
//     int maxpar=10e5;
//     long long number=0;
//     for (int i=index;i<s.length();i++){
//         // str+=s[i];
//         if (number>k/10 || (number==k/10 && s[i]-'0'>k%10)){
//             break;
//         }
//         number=number*10+(s[i]-'0');
//         // 1 6 5 4 6
//         // if(number<=k){
//            int npar= 1+helper(i+1,s,k,dp);
//             maxpar=min(npar,maxpar);
//         // }else{
//         //     break;
//         // }
         
//     }
//     return dp[index]=maxpar;
// }
    int minimumPartition(string s, int k) {
     // 165462 k = 60
     
     //
     int n=s.length();
    //  vector<int> dp(n+1,-1);    
    //  int ans= helper(0,s,k,dp);
    vector<int>dp(n+1,0);      
    //  return (ans==10e5?-1:ans);
    for (int index=n-1;index>=0;index--){
         long long number=0;
          int maxpar=10e5;
        for (int i=index;i<n;i++){

        if (number>k/10 || (number==k/10 && s[i]-'0'>k%10)){
            break;
        }
        number=number*10+(s[i]-'0');
        // 1 6 5 4 6
        // if(number<=k){
           int npar= 1+dp[i+1];
            maxpar=min(npar,maxpar);
        // }else{
        //     break;
        // }

        }
        dp[index]=maxpar;
    }
     // 165462
     // 1 
     return dp[0]==10e5?-1:dp[0];
    }
};