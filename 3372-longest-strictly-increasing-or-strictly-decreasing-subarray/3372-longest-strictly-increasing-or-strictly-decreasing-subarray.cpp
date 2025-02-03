class Solution {
public:
int helper(vector<int> & arr)
{
     int count =1;
        int maxi =1;

        for(int i=1;i<arr.size();i++)
        {
            if (arr[i]>arr[i-1])
            {
                count++;


            }
            else
            {
                                maxi=max(maxi,count);

                count =1;

            }
        }
                        maxi=max(maxi,count);
                        return maxi;

}
    int longestMonotonicSubarray(vector<int>& arr) {
        // length of longest increasing subarray
        int x = helper(arr);
        reverse(arr.begin(),arr.end());
        int y = helper(arr);
        return max(x,y);


    }
};