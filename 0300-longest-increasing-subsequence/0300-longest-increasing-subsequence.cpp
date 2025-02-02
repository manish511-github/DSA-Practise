class Solution {
public:
    int helper(int index, int prev,vector<int> & arr)
    {
        if(index>= arr.size())
        {
            return 0;
        }
        int pick =0;

       
        if(prev==INT_MIN || arr[index]>prev)
        {
             pick = 1+ helper(index+1,arr[index],arr);
        }
        int notpick = helper(index+1,prev,arr);
        return max(pick,notpick);


         

    }

    int lengthOfLIS(vector<int>& arr) {
        return helper(0,INT_MIN,arr);

        
    }
};