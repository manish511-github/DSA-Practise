class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n=arr.size();
        
        vector<int> ans(n,0);
        int i=0;
        int j=arr.size()-1;
        int b=n-1;
        while(i<=j)
        {
            if(abs(arr[i]*arr[i])>abs(arr[j]*arr[j]))
            {
                ans[b]=arr[i]*arr[i];
                i++;
                b--;
            
                
                
            }
            else
                
            {
                ans[b]=arr[j]*arr[j];
                j--;
                b--;
                
            }
        }
        return ans;
        
        
    }
};