class Solution {
public:
    int minDeletion(vector<int>& arr) {
        // nums[i]!=nums[i+1] 
        // 1 1 2 2 3 3 
        // 1 2 2 3 
        // i== odd nums[i]==nums[i-1] and i%2!=0
        // 1 1 2 2 3 3
        // 0 1 2 3 4 5

        // 1 2 2 3 3 
        // 0 1 2 3 4

        // i==0
        // 1
        // i==1
        // 3 4 9
        // 
        // [8,8,1,3,2,0,1,2,5,0]
        // [8 1 3 2 0 1 2 5 0]
        if (arr.size()==1){
            return 1;
        }
        int count=0;
        int index=0;
        for (int i=0;i<arr.size();i++){

            if (index%2!=0 && arr[i]==arr[i-1]){
                count++;
            }
            else{
                index++;
            }
        }
        // 1 1 2 2 3 3
        // 1 2 2 3 3 
//        [5,1,5,4,8,1,4,4,1,9,2,2,2,5,1]
        // 5 1 5 4 8 1 4 4 1 9 2 2 5 1

        if (index%2!=0){
            return count+1;
        }
        if (arr.size()%2==0 && count%2!=0){
            return count +1;
        }
        return count;

    }
};