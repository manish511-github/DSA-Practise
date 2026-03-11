class Solution {
public:
bool helper(int mid, vector<int> &arr,int h){
    long long cnt=0;

    for (int i=0;i<arr.size();i++){
        cnt+=(arr[i]/mid);
        if (arr[i]%mid!=0){
            cnt++;
        }    
    }
    return cnt<=h;
}
    int minEatingSpeed(vector<int>& arr, int h) {
        int low=1;     
        int max_it = *max_element(arr.begin(), arr.end());
        int high=max_it;
        int ans=0;
        while(low<=high){
            int mid =(low+high)/2;
            if (helper(mid,arr,h)){
                ans=mid;
                high=mid-1;

            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};