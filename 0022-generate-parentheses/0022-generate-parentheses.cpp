class Solution {
public:
 void helper(int op, int cl, vector<string> &v, string ans){
    if (op<0 || cl<0){
        return ;
    }
    if (op == 0 && cl ==0){
        v.push_back(ans);
        return;
    }
    if (op>cl)
    {
        return;
    }
    helper(op-1,cl, v,ans+'(');
    helper(op,cl-1, v,ans+')');

 }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string ans="";
        helper(n,n,v,ans);
        return v;
        
    }
};