class Solution {
public:
    int longestConsecutive(vector<int>& arr) {

        unordered_set<int> st (arr.begin(), arr.end());
        int maxi=0;
        for (auto it :st){
            int val=it;
            if (st.find(it-1)==st.end()){
                int cnt=1;
            while(st.find(val+1)!=st.end()){
                val++;
                cnt++;

            }
            maxi=max(cnt,maxi);
            }
            
        }
        return maxi;
        
    }
};