class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int cnt=0;
        for (int i=0;i<words.size();i++){
            string s = words[i].substr(0,k);
            cout<<s<<endl;
            if (s.size()==k){
                mp[s]++;
            }
            if (mp[s]==2){
                cnt++;
            }
        }
        return cnt;

        
    }
};