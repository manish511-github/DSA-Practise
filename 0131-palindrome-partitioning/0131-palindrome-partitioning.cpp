class Solution {
public:
    bool ispalindrome(string s, int start , int end){
        while(start <= end )
        {
            if (s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void helper(int index, string s, vector<vector<string>> &ans,vector<string> & v){
        if (index==s.length()){
            ans.push_back(v);
            return ;
        }

        for (int i=index; i<s.length();i++){
            if (ispalindrome(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                helper(i+1,s,ans,v);
                v.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string> >ans;
        helper(0,s,ans,v);
        return ans;
    
        
    }
};