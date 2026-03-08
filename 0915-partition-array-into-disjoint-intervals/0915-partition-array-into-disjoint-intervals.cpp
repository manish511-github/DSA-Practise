class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        // max value in left < less than max value in right 
        int n =arr.size();
        vector<int> pre(n,0);
        for (int i=0;i<arr.size();i++){
            pre[i]=(i==0)?arr[0]:max(arr[i],pre[i-1]);
        }
        vector<int> suff(n,0);
        for (int i=n-1;i>=0;i--){
            suff[i]=(i==n-1)?arr[i]:min(arr[i],suff[i+1]);
        }

        for (int i=0;i<arr.size();i++){
            cout<<pre[i]<<" ";
            
            cout<<suff[i]<<" ";

            if (pre[i]<=suff[i+1]){
                return i+1;
            }
        }
        return 0;


    }
};