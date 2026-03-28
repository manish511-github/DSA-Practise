class Solution {
public:
    int helper(int k){
        int count=0;
        while(k!=1){
            if (k%2==0){
                count++;
                k=k/2;
            }else{
                count++;
                k=3*k+1;
            }
        }
        return count;
    }
    int getKth(int low, int high, int k) {
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