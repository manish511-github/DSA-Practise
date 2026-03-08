class Solution {
public:
    int numSplits(string s) {
        int n= s.length();
        int count=0;
        unordered_set<char> st;
        vector<int> pre(n,0);
        vector<int> suff(n+1,0);

        for (int i=0;i<s.length();i++){
            st.insert(s[i]);
            pre[i]=st.size();
        }
        st.clear();

        for (int i=s.length()-1;i>=0;i--){
            st.insert(s[i]);
            suff[i]=st.size();
        }
        for (int i=0;i<s.length();i++){
           int left = pre[i];
            int right= suff[i+1];
            if (left==right){
                count++;
            }
        }
        return count;
        
    }
};