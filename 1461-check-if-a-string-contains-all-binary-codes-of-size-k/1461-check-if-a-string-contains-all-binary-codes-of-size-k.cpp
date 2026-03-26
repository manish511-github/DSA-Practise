class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string str="";
        if (s.length()<k){
            return false;
        }
        // 00 01 11 01 11 10 
        for (int head=0;head<s.length()-k+1;head++){
           st.insert(s.substr(head,k));
        //    cout<<s.substr(head,k)<<endl;
        }
        return st.size()==(1<<k);
    }
};