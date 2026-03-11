class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        // 1 1 2 3 3 4 4 8 8
        
        // 0 1 2 3 4 5 6 7 8 
        
        // mid =3
        // (mid-1 == 2 and mid ==2)

        int n=arr.size();
        int low =0;
        int high=n-1;
        if (arr.size()==1){
            return arr[0];
        }

        while(low<=high){
           int mid =(low+high)/2;
            if ((mid==0 && arr[mid]!=arr[mid+1]) || (mid==n-1 && arr[mid]!=arr[mid-1]) || (arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1])){
                return arr[mid];
            }
           if (arr[mid]==arr[mid+1]){
            if (mid%2==0){
                 low = mid+1;
            } else{
                high=mid-1;
            }
           }
           else if (arr[mid]== arr[mid-1] )
           {
            if (mid%2==0){
                 high = mid-1;
            } else{
                low=mid+1;
            }
           }

        }
        return -1;
    }
};