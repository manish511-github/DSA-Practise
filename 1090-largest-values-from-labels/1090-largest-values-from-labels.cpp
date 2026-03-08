class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int sum=0;
        vector<pair<int,int>> v;
        int n=values.size();
        for (int i=0;i<n;i++){
            v.push_back({values[i],labels[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;
    });
    unordered_map<int,int>mp;
    for (int i=0;i<labels.size();i++){
        mp[labels[i]]=useLimit;
    }
    for (int i=0;i<v.size();i++){
        if (numWanted>0 && mp[v[i].second]>0){
            sum+=v[i].first;
            numWanted--;
            mp[v[i].second]--;
        }
    }
    return sum;
    }
};