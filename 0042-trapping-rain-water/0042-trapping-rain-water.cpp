class Solution {
public:
    int trap(vector<int>& arr) {
        // Apprach 1 :
        // we track the leftmax and rightmax height using array
        // and then find sum of filled water possible by adding water block at each step
        int n=arr.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        for (int i=0;i<n;i++){
            leftmax[i]= (i==0)?arr[i]:max(arr[i],leftmax[i-1]);
            rightmax[n-1-i]= (i==0)?arr[n-1-i]:max(arr[n-1-i],rightmax[n-i]);
        }
        int sum=0;
        for (int i=0;i<n;i++)
        {
            sum+=(min(leftmax[i],rightmax[i])-arr[i]);
        }
        return sum;
        
    }
};