class Solution {
public:
string invert(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '0')
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}
    // 011 1 001
    // 011 -> 011 1 reverse 100 -> 001 011^1 = 100
    string helper(int n){
        if (n==1){
            return "0";
        }
        string str = helper(n-1);
        string str2= invert(str);
        reverse(str2.begin(),str2.end());
        return str+'1'+ str2;

    }
    char findKthBit(int n, int k) {
        string s = helper(n);
        return s[k-1];
    }
};