class Solution {
public:
    int minLength(vector<int>& arr, int k) {
        // 2 2 3 1
        vector<int> mp(100001, 0);
        int n=arr.size();
        // map -> [2   2]
        //         [3   1]
        //         while(sum>=k){
        //             tail++;
        //             maxi=max(maxi,head-tail)
        //         }
        int tail=0;
        int mini=INT_MAX;
        int sum=0;
        for (int head=0;head<n;head++){
            mp[arr[head]]++;
            if (mp[arr[head]]==1){
                sum+=arr[head];
            }
            while(sum>=k){
                // cout<<head<<" "<<tail<<endl;
                mini=min(mini,head-tail+1);
                mp[arr[tail]]--;
                if (mp[arr[tail]]<1){
                    sum-=arr[tail];

                }
                tail++;
            }
        }
        return mini==(INT_MAX)?-1:mini;

        
    }
};