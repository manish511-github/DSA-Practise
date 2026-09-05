class Solution {
public:
int helper(string s, string str){
    cout<<s<<" "<<str <<endl;
    int cnt=0;
    for (int i=0;i<s.length();i++){
        if (s[i]!=str[i]){
            cnt++;
        }
    }
    return cnt/2;
}
    int minSwaps(string s) {
        // 1 1 1 0 0 0 
        // 1 0 1 0 1 0 
        // 0 1 0 1 0 1  

        // 110 
        
        // 101
        int n =s.length();
        string str0 = "";
        string str1 = "";
        for (int i =0;i<n;i++){
            if (i%2==0){
                str0+='1';
                str1+='0';
            }
            else {
                str0+='0';
                str1+='1';
            }
        }
        int cnt1=count(s.begin(), s.end(), '1');
        int cnt0=count(s.begin(), s.end(), '0');

        if (abs(cnt1-cnt0)>1){
            return -1;
        }

        if (n%2==0  ){
            if (cnt1==cnt0){
                int ans1 =helper(s,str1);
                int ans2 =helper(s,str0);
                return min(ans1,ans2); 
            }
            else {
                return -1;
            }

        }
        else {
            
            if (cnt1>cnt0){
                return helper (s,str0);
            }
            else{
                return helper (s,str1);
            }
        }
        return -1;

    }
};