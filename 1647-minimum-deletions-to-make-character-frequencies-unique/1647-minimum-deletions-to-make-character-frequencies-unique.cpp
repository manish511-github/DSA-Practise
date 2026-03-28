class Solution {
public:
    int minDeletions(string s) {
        // no 2 differnt charactrers in s have sam frequency
        // minimum no of character removw -> []
        // aaabbcc
        // a->3
        // b->3
        // c->2
        // ceabaacb
        // aaabbcce
        unordered_map<char,int>mp;
        vector<int> v;

        
        for (int i=0;i<s.length();i++){
            mp[s[i]]++; 
        }
        for (auto it:mp){
            v.push_back(it.second);
        }
        int cnt=0;
        unordered_set<int> st;
        sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++){
            
            if (st.find(v[i])!=st.end()){
                int x=v[i];
                while(x>0 && st.find(x)!=st.end()){
                    x--;
                    cnt++;
                }
                if (x>0){
                    st.insert(x);
                }
            }
            else{
                st.insert(v[i]);
            }
        }
        return cnt;
    }
};