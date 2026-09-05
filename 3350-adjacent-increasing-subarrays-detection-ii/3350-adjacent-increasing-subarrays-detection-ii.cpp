class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& arr) {
                            // [1,2,3,4,4,4,4,5,6,7]
                            //  4 3 2 1 1 1 4 3 2 1
                            //  0 1 2 3 4 5 6 7 8 9

                            // [2,5,7,8,9,2,3,4,3,1]
                            //  5 4 3 2 1 3 2 1 1 1
                            //  0 1 2 3 4 5 6 7 8 9
        int n=arr.size();
        unordered_map<int,int>mp;
        int maxi=0;
        mp[n-1]=1;
        for (int i=n-2;i>=0;i--){
            if (arr[i]<arr[i+1]){
                mp[i]=mp[i+1]+1;
            }
            else{
                mp[i]=1;
            }
        }
        int prev=1;
        
        for (int i=1;i<n;i++){
            // cout<<i<<" "<<prev<<" "<<mp[i]<<endl;
            // if (prev<=mp[i]){ // 2 
                int mini =min(prev,mp[i]);
                maxi=max(maxi,mini);
            // }
            if (arr[i]>arr[i-1]){
                prev++;
            }
            else{
                prev=1;
            }

        }
        return maxi;
        

        //[-8,7,-16,-7,18]
        //  2 1  3   2  1

                            
    }
};