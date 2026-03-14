class Solution {
public:
    void sortColors(vector<int>& arr) {
        //dnf sorting
        int n= arr.size();
        int low =0;
        int high= n-1;
        int mid =0;

        // 2,0,2,1,1,0
        // 2>0
        // 0,0,2,1,1,2

        while(mid<=high)
        {
            if (arr[mid]==2)
            {
                swap(arr[mid],arr[high]);
                high--;

            }
            else if (arr[mid]==0)
            {
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else{
                mid++;
            }


        }


        
    }
};