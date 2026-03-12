class Solution {
public:
    int subarraySum(vector<int>& arr, int target) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum=0;
        int cnt=0;
        for (int i=0;i<arr.size();i++){
            sum+=arr[i];
            if (mp.find(sum-target)!=mp.end()){
                cnt+=mp[sum-target];
            }
                mp[sum]++;
            
        }
        return cnt;

        
    }
};