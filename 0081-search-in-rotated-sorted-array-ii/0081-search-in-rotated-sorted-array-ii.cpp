class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        // [3,4,5,6,1,2]
        // mid = 6>2
        //
            // 2 5 6 0 0 1 2 
            // 0 1 2 3 4 5 6 
            // low = 0
            // high = 6
            // mid = 3
    // 1 0 1 1 1
    // 0 1 2 3 4 
    // 0+4/2 = 2;
    // 
        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid]==target){
                return true;
            }
                        else if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;

            }
            else if (arr[low]<=arr[mid]){ // 2<0
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

        
        return false;

    }
};