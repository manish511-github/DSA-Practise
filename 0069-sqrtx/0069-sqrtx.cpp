class Solution {
public:
    int mySqrt(int n) {
             if(n==1)
        {return 1;
        }
        int low=1;
        int high =n/2;
        int ans=0;
        while(low<=high){
            int mid =(low+high)/2;
            if (mid==n/mid){
                return mid;
            }
            else if (mid>n/mid){
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};