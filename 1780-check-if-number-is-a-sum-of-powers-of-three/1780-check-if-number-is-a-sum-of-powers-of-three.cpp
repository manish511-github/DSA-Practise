class Solution {
public:
    bool helper(int index, vector<int>& arr, int target){
        if (target==0){
            return true;
        }
        if (index>=arr.size()){
            return false;
        }
        int take=0;
        if (arr[index]<=target){
            take=helper(index+1,arr,target-arr[index]);
        }
        int nottake =helper(index+1,arr,target);
        return take|| nottake;
        
    }
    bool checkPowersOfThree(int n) {
        vector<int> arr;
        int val=1;
        while(val<10e7){
            arr.push_back(val);
            val*=3;
            
        }
        reverse(arr.begin(),arr.end());
        if (helper(0,arr,n)){
            return true;
        }
        // for (int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        return false;
        
        
    }
};