class Solution {
public:


    bool searchMatrix(vector<vector<int>>& arr, int target) {
        // low =0 high = 12-1=11
        // mid =6
        // 6/4=1   targetr> = arr[i][0] and target<=arr[i][1]
        // helper()
        int n=arr.size();
        int m=arr[0].size();

        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if (arr[row][col]==target){
                return true;
            }
            else if (target<arr[row][col]){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return false;
        
    }
};