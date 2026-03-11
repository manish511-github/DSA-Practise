class Solution {
public:
bool helper(int mid, vector<int>& arr, int days){
    int curr=0;
    int need=1;

    for(int w : arr){
        if(curr + w <= mid){
            curr += w;
        }
        else{
            need++;
            curr = w;
        }
    }

    return need <= days;
}
    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(),arr.end());

        int n= arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        int high=sum;
        int ans=0;
        while(low<=high){
            int mid =(low+high)/2;
            if (helper(mid,arr,days)){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;

            }
        }
        return ans;
        
    }
};