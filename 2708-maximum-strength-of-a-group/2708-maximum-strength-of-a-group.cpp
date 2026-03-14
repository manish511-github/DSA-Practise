class Solution {
public:
// int helper(int index,vector<int> & arr){
//     if (index>=arr.size()){
//         return 1;
//     }
//     int take =1;
//     take = arr[index]*helper(index+1,arr);
//     int nottake = helper(index+1,arr);
//     return max(take,nottake);
// }
    long long maxStrength(vector<int>& arr) {
        if (arr.size()==1){
            return arr[0];
        }
        long long maxneg=INT_MIN;
        long long  negpro=1;
        long long pospro=1;
        int poscnt=0;
        int zero=false;
        int negcnt=0;
        for(int i=0;i<arr.size();i++){
            if (arr[i]<0){
                negcnt++;
                maxneg=max(maxneg,1LL*arr[i]);
                negpro=negpro*arr[i];
            }
            if (arr[i]==0){
                zero=true;
            }
            if (arr[i]>0){
                poscnt++;
                
                pospro*=arr[i];
            }
        }
        if (negcnt==0 && poscnt==0){
            return 0;
        }
        if (negcnt==1 && poscnt==0 && zero ){
            return 0;
        }
        if (negcnt==1 && poscnt==0){
            return arr[0];
        }
        if (negpro<0 && maxneg!=INT_MIN){
            negpro=negpro/maxneg;
        }
        return (negpro*pospro);
    }
};