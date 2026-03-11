class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        // [3,4,5,6,1,2]
        // mid = 6>2
        //

        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid]==target){
                return mid;
            }
            if (arr[low]<=arr[mid]){ // 5>3
            if (target>= arr[low] && target <=arr[mid]){
                high = mid-1;
            }
            else{
                low= mid+1;
            }   

            }else  {
              
            if (target>= arr[mid] && target <=arr[high]){
                low=mid+1;
            }
            else{
                high= mid-1;
            }
        }
        }

        
        return -1;

    }
};