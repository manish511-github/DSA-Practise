class Solution {
public:
    void helper(string s,unordered_set<string> &mp,string &ans,int n){
        if (s.length()==n){
            if (mp.find(s)==mp.end()){
                ans=s;
            }
            return ;
        }
        helper(s+'1',mp,ans,n);
        helper(s+'0',mp,ans,n);
        
    }
    string findDifferentBinaryString(vector<string>& arr) {
        int n = arr.size();
        unordered_set<string> mp(arr.begin(),arr.end());
        string ans="";
        helper("",mp,ans,n);
        return ans;
    }
};