class Solution {
public:
    bool partitionArray(vector<int>& arr, int k) {
        // partitions n/k
        // 1-> 1
        // 2-> 1
        // 3-> 1
        // 4-> 1
        // // 
        // 3 -> 1
        // 5 -> 1
        // 2 -> 2
        unordered_map<int,int> mp;
        int n=arr.size();
        if (n%k!=0){
            return false;
        }

        int groups = n/k;
        for (int i=0;i<n;i++){
            mp[arr[i]]++;

        }
        for (auto it: mp){
            if (it.second>groups){
                return false;
            }
        }
        return true;
    }
};