class Solution {
public:
    int trap(vector<int>& arr) {
        // Apprach 2 :
        // we keep track of leftmax and right max
        // and keep on adding the possible water block with help of 2 pointers
        int n=arr.size();
        int left=0;
        int right=n-1;
        int leftmax=arr[0];
        int sum=0;
        int rightmax=arr[n-1];      
        while(left<right){
            leftmax=max(arr[left],leftmax);
            rightmax=max(arr[right],rightmax);
            if (leftmax<rightmax){
                sum+=(leftmax-arr[left]);
                left++;
            }
            else{
                sum+=(rightmax-arr[right]);
                right--;
            }

        }
        return sum;
    }
};