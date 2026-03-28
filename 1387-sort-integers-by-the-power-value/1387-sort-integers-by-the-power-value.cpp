class Solution {
public:
    unordered_map<int, int> dp;

    int helper(int x){
        if (x==1){
            return 0;
        }
        if (dp.count(x)){
            return dp[x];
        }
        if (x % 2 == 0) {
            return dp[x] = 1 + helper(x / 2);
        } else {
            return dp[x] = 1 + helper(3 * x + 1);
        }
    }
    int getKth(int low, int high, int k) {
        dp[1]=0;
        vector<pair<int,int>>v;
        for (int i=low;i<=high;i++){
            int power=helper(i);
            v.push_back({power,i});
        }
        sort(v.begin(),v.end());
        for (int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        return v[k-1].second;
    }
};