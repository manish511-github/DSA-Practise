class Solution {
public:
    int minimumLevels(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n,0);
        // vector<int> suff(n,0);
        int total=0;
        for (int i=0;i<arr.size();i++){
            total +=(arr[i]==0)?-1:1;
        }
        for (int i=0;i<arr.size()-1;i++) {
            pre[i] = (i==0) ? ((arr[i]==0) ? -1 : 1) : pre[i-1] + ((arr[i]==0) ? -1 : 1);
            int suff= total-pre[i];
            if (pre[i]>suff){
                return i+1;
            }
        }
        
        return -1;
    }
};